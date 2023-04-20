//#include "simulations.h"
#include "s3Cooking.h"
#include "ui_s3Cooking.h"
#include <QPainter>
#include <QDebug>

s3Cooking::s3Cooking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s3Cooking)
{
    ui->setupUi(this);
    ui->widget->show();

    //tzhou drag:this is just a static example, not connect to anything.
    QLabel * label = new DragAndDropLabel(parent);
    label->setParent(ui->leftFrame);
    QPixmap pix(":/sprites/icons/tomato.png");
    label->setGeometry(QRect(5,5,50,50));
    label->setPixmap(pix);
    label->setScaledContents(true);
    label->show();

    ui->graphicsView->setScene(scene);
    connect(ui->graphicsView, &DragAndDropGraphicsView::itemDrop,
            this, &s3Cooking::imageEnter);

    //Ruini:add backgound image
    QPixmap image(":/sprites/icons/Kitchen.PNG");
    QLabel* background = ui->backgoundImage;
    background->setPixmap(image);
    background->setScaledContents(true); // Scale the image to fit the label
    background->setGeometry(QRect(0, 0, background->width(), background->height()));
    background->lower();

    //connect(listener, &MyContactListener::cut, this, &s3Cooking::handleCut);
    //connect(ui->tomato, &QPushButton::clicked, this, &simulations::testTrue);





}

s3Cooking::~s3Cooking()
{
    delete ui;
}

void s3Cooking::nextPage()
{
    emit goToPage4();
}

void s3Cooking::imageEnter(QPixmap pixmap, QGraphicsView *view)
{
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
