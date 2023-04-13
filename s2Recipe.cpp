#include "s2Recipe.h"
#include "ui_s2Recipe.h"

s2Recipe::s2Recipe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s2Recipe)
{
    ui->setupUi(this);
}

s2Recipe::~s2Recipe()
{
    delete ui;
}
