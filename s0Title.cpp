#include "s0Title.h"
#include "ui_s0Title.h"
#include "titledisplay.h"

s0Title::s0Title(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s0Title)
{
    ui->setupUi(this);
    connect(ui->startBtn, &QPushButton::clicked, this , &s0Title::nextPage);

}

s0Title::~s0Title()
{
    delete ui;
}

void s0Title::nextPage()
{
    emit goToPage1();
}
