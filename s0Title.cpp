#include "s0Title.h"
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include "ui_s0Title.h"

s0Title::s0Title(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s0Title)
{
    setObjectName("s0Title");
    ui->setupUi(this);
    connect(ui->startBtn, &QPushButton::clicked, this , &s0Title::nextPage);

    QSequentialAnimationGroup *animationGroup = new QSequentialAnimationGroup(ui->title);
    animationGroup->setLoopCount(-1); // Set the loop count to -1 for infinite looping

    QPropertyAnimation *animation1 = new QPropertyAnimation(ui->title, "pos");
    animation1->setDuration(1250);
    animation1->setStartValue(ui->title->pos());
    animation1->setEndValue(QPoint(ui->title->pos().x(), ui->title->pos().y() + 20));
    animation1->setEasingCurve(QEasingCurve::InOutSine);

    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->title, "pos");
    animation2->setDuration(1250);
    animation2->setStartValue(QPoint(ui->title->pos().x(), ui->title->pos().y() + 20));
    animation2->setEndValue(ui->title->pos());
    animation2->setEasingCurve(QEasingCurve::InOutSine);

    animationGroup->addAnimation(animation1);
    animationGroup->addAnimation(animation2);
    animationGroup->start(); // Start the animation

//    //Ruini:add title image
//    QPixmap imageTitle(":/sprites/icons/Title.png");
//    QLabel* title = ui->title;
//    title->setPixmap(imageTitle);
//    title->setScaledContents(true); // Scale the image to fit the label
//    title->setGeometry(title->pos().x(), title->pos().y(), title->width(), title->height());

//    //Ruini:add backgound image
//    QPixmap imageBg(":/sprites/icons/Kitchen.PNG");
//    QLabel* background = ui->background;
//    background->setPixmap(imageBg);
//    background->setScaledContents(true); // Scale the image to fit the label
//    background->setGeometry(QRect(0, 0, background->width(), background->height()));
//    background->lower();
}

s0Title::~s0Title()
{
    delete ui;
}

void s0Title::nextPage()
{
    emit goToPage1();
}
