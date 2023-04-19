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

    //Ruini:add backgound image
    QPixmap image(":/sprites/icons/Kitchen.PNG");
    QLabel* background = ui->backgoundImage;
    background->setPixmap(image);
    background->setScaledContents(true); // Scale the image to fit the label
    background->setGeometry(QRect(0, 0, background->width(), background->height()));
    background->lower();

//    connect(listener, &MyContactListener::cut, this, &s3Cooking::handleCut);
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


