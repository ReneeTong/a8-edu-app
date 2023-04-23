//#include "simulations.h"
#include "s3Cooking.h"
#include "ui_s3Cooking.h"
#include <QPainter>
#include <QDebug>

s3Cooking::s3Cooking(Model& model, QWidget *parent) :
    QWidget(parent),
    m_model(model),
    ui(new Ui::s3Cooking)
{
    ui->setupUi(this);
    ui->widget->show();

    // jeffrey
    QTimer::singleShot(0, this, [this]() {
        ui->scrollArea->addWidget(ui->render);
    });

    //Andy Tran:
    //Step label
    ui->labelStep->setText("STEP 1");
    setAcceptDrops(true);


    xmaps.insert("tomato",QPixmap(":/sprites/icons/tomato.png"));
    xmaps.insert("carrot",QPixmap(":/sprites/icons/carrot.png"));

    //createLables();

    DragAndDropLabel * label2 = new DragAndDropLabel(parent);
    label2->setParent(ui->leftFrame);
    //ui->leftFrame->setAcceptDrops(true);
    QPixmap pixCarrot(":/sprites/icons/carrot.png");
    label2->setGeometry(QRect(5,5,50,50));
    label2->setPixmap(pixCarrot);
    label2->setScaledContents(true);
    label2->show();
    label2->setStyleSheet("background-color: rgba(0,0,0,0);");
    label2->move(50, 50);

    //set the background of the scene
//    QPixmap background(":/sprites/icons/Kitchen.PNG");
//    QBrush brush(background.scaled(300, 300));
//    scene->setBackgroundBrush(brush);
    ui->graphicsView->setScene(scene);

//    connect(ui->graphicsView, &DragAndDropGraphicsView::itemDrop,
//            this, &s3Cooking::imageEnter);
    connect(ui->graphicsView, &DragAndDropGraphicsView::mouseRelease,
            this, &s3Cooking::mouseRelease);


    //Ruini:add backgound image
    QPixmap image(":/sprites/icons/Kitchen.PNG");
    QLabel* background = ui->backgoundImage;
    background->setPixmap(image);
    background->setScaledContents(true); // Scale the image to fit the label
    background->setGeometry(QRect(0, 0, background->width(), background->height()));
    background->lower();

//    connect(listener, &MyContactListener::cut, this, &s3Cooking::handleCut);
//    connect(ui->tomato, &QPushButton::clicked, ui->widget, &simulations::testTrue);

    //Andy Tran: connection to communicate btw Model and S3
    connect(&m_model, &Model::onS3Update, this, &s3Cooking::onS3Update);
    //connect(this, &s3Cooking::onStepCookingUpdate, &m_model, &Model::onStepCookingUpdate);
    //Ruini edit
    connect(ui->widget->listener, &MyContactListener::onStepCookingUpdate, &m_model, &Model::onStepCookingUpdate);

}

s3Cooking::~s3Cooking()
{
    delete ui;
}

void s3Cooking::nextPage()
{
    emit goToPage4();
}

//Andy Tran: on s3 update
void s3Cooking::onS3Update(int curStep, QHash<Ingredient*, int>* todoList){
    ui->labelStep->setText("Step " + QString::number(curStep));
    this->todoList = todoList;

    //Update Left Frame and Right Frame to display properly

}
//----------------------------------------------------------------------------

//This is what the graphics view would do after the drop
void s3Cooking::imageEnter(QPoint mousePos, QPixmap pixmap, QGraphicsView *view)
{
    qDebug()<<"Drop location: ( "<<mousePos.x()<<", "<<mousePos.y()<<" )";
    QGraphicsScene* scene = view->scene();
    if(scene->items().count()>0){
        scene->clear();
    }
    scene->addPixmap(pixmap.scaled(26,26));
    view->setScene(scene);
    view->viewport()->update();
    view->update();
    view->show();

}
void s3Cooking::mouseRelease(QPoint pos){
    qDebug() << "release";
    // create a mouse press event
    QMouseEvent *mouseReleaseEvent = new QMouseEvent(QEvent::MouseButtonRelease, pos, Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);

    // send the mouse press event to a widget
    QCoreApplication::postEvent(ui->widget, mouseReleaseEvent);
}

void s3Cooking::createLables(){
    if(todoList != nullptr){
        QHash<Ingredient*, int>::const_iterator it;
        for (it = todoList->constBegin(); it != todoList->constEnd(); ++it) {
            // 'it.key()' is the Ingredient pointer
            // 'it.value()' is the integer value associated with the Ingredient
            // Do something with 'it.key()' and 'it.value()' here

            //tzhou drag:this is just a static example, not connect to anything.
            DragAndDropLabel * label1 = new DragAndDropLabel();
            label1->setParent(ui->leftFrame);
            QPixmap ingredientIcon = xmaps.value(it.key()->getName());
            label1->setGeometry(QRect(5,5,50,50));
            label1->setPixmap(ingredientIcon);
            label1->setScaledContents(true);
            label1->show();
            label1->setStyleSheet("background-color: rgba(0,0,0,0);");
            label1->move(10, 10);
        }
    }

}
