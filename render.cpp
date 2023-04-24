#include "render.h"
#include "debugdraw.h"
#include "draganddrop.h"
#include "kitchencontactlistener.h"
#include "qpainter.h"
#include "shape.h"

#include <QMouseEvent>
#include<QApplication>
#include<QLabel>
#include <QTimer>
#include <Box2D/Box2D.h>

Render::Render(QWidget *parent)
    : QWidget{parent},
      world(b2Vec2(0.0f, 10.0f)),
      model(&world)
{
    setStyleSheet("background-color: grey;");
    setFixedSize(WINDOW_WIDTH+1, WINDOW_HEIGHT+1);
    setAcceptDrops(true);


    {
        KitchenContactListener *contactListen = new KitchenContactListener;
        world.SetContactListener(contactListen);
    }

    {
        DebugDraw *debugDraw = new DebugDraw(this);
        debugDraw->SetFlags(b2Draw::e_shapeBit);
        world.SetDebugDraw(debugDraw);
    }

    {
        b2Vec2 size = b2Vec2(WINDOW_WIDTH/2, GROUND_HEIGHT);
        b2Vec2 position = b2Vec2(size.x, WINDOW_HEIGHT-size.y);
        Shape *ground = new Shape(&world, position, size);
        ground->setStatic(true);
    }


    // [== CREATE UTENSILS AND CONNECT THEM ==]
    int const UTENSIL_COUNT = 3;

    {
        b2Vec2 size = b2Vec2(60, 10);
        b2Vec2 position = b2Vec2(WINDOW_WIDTH/(UTENSIL_COUNT+1), WINDOW_HEIGHT-(GROUND_HEIGHT*2)-size.y);

        Shape* cuttingBoard = new Shape(&world, position, size);
        cuttingBoard->setStatic(true);

        connect(cuttingBoard, &Shape::onContact, &model, &Model::cut);
    }

    {
        b2Vec2 size = b2Vec2(60, 50);
        b2Vec2 position = b2Vec2(WINDOW_WIDTH/(UTENSIL_COUNT+1) * 2, WINDOW_HEIGHT-(GROUND_HEIGHT*2)-size.y);

        Shape* boilingPot = new Shape(&world, position, size);
        boilingPot->setStatic(true);

        connect(boilingPot, &Shape::onContact, &model, &Model::boil);
    }

    {
        b2Vec2 size = b2Vec2(60, 15);
        b2Vec2 position = b2Vec2(WINDOW_WIDTH/(UTENSIL_COUNT+1) * 3, WINDOW_HEIGHT-(GROUND_HEIGHT*2)-size.y);

        fryingPan = new Shape(&world, position, size);
        fryingPan->setStatic(true);

        connect(fryingPan, &Shape::onContact, &model, &Model::fry);
    }

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Render::renderWorld);
    timer->start(1000 / 60);

}

void Render::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        QPointF clickPos = event->pos();
        b2Vec2 targetPos = b2Vec2(clickPos.x(), clickPos.y());

        // Iterate through all bodies in the world
        for (b2Body* body = world.GetBodyList(); body; body = body->GetNext())
        {
            // Calculate the distance between the mouse click and the body position
            b2Vec2 bodyPos = body->GetPosition();
            b2Vec2 clickPosB2(bodyPos.x - clickPos.x(), bodyPos.y - clickPos.y());
            float distance = clickPosB2.Length();

            // Check if the distance is less than the desired radius
            if (distance < 50)
            {
                b2MouseJointDef md;
                md.bodyA = fryingPan->getBody();
                md.bodyB = body;
                md.target = targetPos;
                md.maxForce = 1000.0f * body->GetMass();
                b2MouseJoint* joint = static_cast<b2MouseJoint*>(world.CreateJoint(&md));
                body->SetAwake(true);

                m_mouseJoints.append(joint);
            }
        }
    }
}

void Render::mouseMoveEvent(QMouseEvent* event) {
    if (event->buttons() & Qt::LeftButton) {
        QPointF clickPos = event->pos();
        b2Vec2 targetPos = b2Vec2(clickPos.x(), clickPos.y());

        for (b2MouseJoint *joint : m_mouseJoints) {
            if (joint) {
                joint->SetTarget(targetPos);
            }
        }
    }
}

void Render::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        for (b2MouseJoint *joint : m_mouseJoints) {
            world.DestroyJoint(joint);
        }
        m_mouseJoints.clear();
    }
}

void Render::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::gray);

    QPixmap background(":/sprites/icons/Kitchen.PNG");
    painter.drawPixmap(rect(), background);

    //painter.drawPixmap(30, 30, currentDrop.getPixmap());

//    for (Shape* shape : shapes) {
//        b2Vec2 position = shape->getBody()->GetPosition();
//        Ingredient* ingredient = static_cast<Ingredient*>(shape->getData());


//        QList<Ingredient> ingredients= model.getRecipe()->getIngredeints();

//        qDebug() <<ingredient->getName();

//        QPixmap current = parentWidget()->findChild<QWidget*>("ingredientList")->property("pixmap").value<QPixmap>();
//        painter.drawPixmap((int)(position.x*20), (int)(position.y*20), current);
//    }

    b2Vec2 panPos = fryingPan->getBody()->GetPosition();
    QPixmap panPix(":/sprites/icons/fryPan.png");
    QPixmap scaledPixmap = panPix.scaled(QSize(200, 200), Qt::KeepAspectRatio);
    int x = (int)(panPos.x - scaledPixmap.width() / 2.0) + 32;//32 is the offset
    int y = (int)(panPos.y - scaledPixmap.height() / 2.0);
    painter.drawPixmap(x, y, scaledPixmap);

    world.DrawDebugData();
//    painter.drawPixmap((int)((panPos.x*13)), (int)(panPos.y*16), panPix);


    painter.end();

}

void Render::dropEvent(QDropEvent*event)
{
//    QPointF localPos = this->mapFromGlobal(QCursor::pos());
//    QPointF windowPos = this->mapFromGlobal(QCursor::pos());
//    QPointF screenPos = QCursor::pos();
//    Qt::MouseButton button = Qt::LeftButton;
//    Qt::MouseButtons buttons = Qt::LeftButton;
//    Qt::KeyboardModifiers modifiers = Qt::NoModifier;
//    QMouseEvent *mousePressEvent = new QMouseEvent(QEvent::MouseButtonPress, localPos, windowPos, screenPos, button, buttons, modifiers);
//    QApplication::postEvent(this, mousePressEvent);

    DragAndDropLabel *label = qobject_cast<DragAndDropLabel*>(event->source());
    currentDrop = qvariant_cast<Ingredient>(label->property("Ingredient"));

    QPoint point = event->position().toPoint();

    b2Vec2 position(point.x(), point.y());
    b2Vec2 size(10.0f, 10.0f);

    Shape* shape = new Shape(&world, position, size);
    shape->setStatic(false);
    shape->setData(new Ingredient(currentDrop.getName(), {}));
    shapes.push_back(shape);
}

void Render::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
    event->acceptProposedAction();
}

void Render::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void Render::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
    event->acceptProposedAction();
}

void Render::renderWorld() {
    world.Step(1.0/60.0, 6, 2);

    for (const auto& method : model.actionQueue) {
        method();
    }
    model.actionQueue.clear();

    update();
}
