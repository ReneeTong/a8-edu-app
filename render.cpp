#include "render.h"
#include "debugdraw.h"
#include "kitchencontactlistener.h"
#include "qpainter.h"
#include "shape.h"
#include"foodLibrary.h"

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

        Shape* fryingPan = new Shape(&world, position, size);
        fryingPan->setStatic(true);

        //connect(fryingPan, &Shape::onContact, &model, &Model::boil);
    }

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Render::renderWorld);
    timer->start(1000 / 60);

}

void Render::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        QPoint point = event->pos();

        b2Vec2 position(point.x(), point.y());
        b2Vec2 size(10.0f, 10.0f);

        Shape* shape = new Shape(&world, position, size);
        shape->setStatic(false); 
        //shape->setData(new Ingredient("tomato", {}));
        //bad: delete later
        FoodLibrary f;
        shape->setData(f.tomato);
    }
}

void Render::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::gray);

    QPixmap background(":/sprites/icons/Kitchen.PNG");
    painter.drawPixmap(rect(), background);

    world.DrawDebugData();
}

void Render::dropEvent(QDropEvent *event)
{

    QPoint pos = event->pos();
    QMouseEvent *mousePressEvent = new QMouseEvent(QEvent::MouseButtonPress, pos, Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
    QApplication::postEvent(this, mousePressEvent);

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
