#include "s0Title.h"
#include "ui_s0Title.h"

s0Title::s0Title(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s0Title)
{
    ui->setupUi(this);
    connect(ui->startBtn, &QPushButton::clicked, this , &s0Title::nextPage);

    //Ruini:add title image
    QPixmap imageTitle(":/sprites/icons/title.png");
    QLabel* title = ui->title;
    title->setPixmap(imageTitle);
    title->setScaledContents(true); // Scale the image to fit the label
    title->setGeometry(title->pos().x(), title->pos().y(), title->width(), title->height());

    //Ruini:add backgound image
    QPixmap imageBg(":/sprites/icons/Kitchen.PNG");
    QLabel* background = ui->background;
    background->setPixmap(imageBg);
    background->setScaledContents(true); // Scale the image to fit the label
    background->setGeometry(QRect(0, 0, background->width(), background->height()));
    background->lower();



}

s0Title::~s0Title()
{
    delete ui;
}

void s0Title::nextPage()
{
    emit goToPage1();
}
