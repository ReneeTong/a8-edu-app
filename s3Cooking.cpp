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

    //Andy Tran:
    //Step label
    ui->labelStep->setText("STEP 1");

    //tzhou drag:this is just a static example, not connect to anything.
    QLabel * label = new DragAndDropLabel(parent);
    label->setParent(ui->leftFrame);
    QPixmap pix(":/sprites/icons/tomato.png");
    label->setGeometry(QRect(5,5,50,50));
    label->setPixmap(pix);
    label->setScaledContents(true);
    label->show();

    //set the background of the scene
    QPixmap background(":/sprites/icons/Kitchen.PNG");
    QBrush brush(background.scaled(300, 300));
    scene->setBackgroundBrush(brush);
    ui->graphicsView->setScene(scene);
    connect(ui->graphicsView, &DragAndDropGraphicsView::itemDrop,
            this, &s3Cooking::imageEnter);

    //Ruini:add backgound image
    //QPixmap image(":/sprites/icons/Kitchen.PNG");
    //QLabel* background = ui->backgoundImage;
    //background->setPixmap(image);
    //background->setScaledContents(true); // Scale the image to fit the label
    //background->setGeometry(QRect(0, 0, background->width(), background->height()));
    //background->lower();

    //connect(listener, &MyContactListener::cut, this, &s3Cooking::handleCut);
    //connect(ui->tomato, &QPushButton::clicked, this, &simulations::testTrue);

    //Andy Tran: connection to communicate btw Model and S3
    connect(&m_model, &Model::onS3Update, this, &s3Cooking::onS3Update);
    connect(this, &s3Cooking::onStepCookingUpdate, &m_model, &Model::onStepCookingUpdate);
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
