#include "s3Cooking.h"
#include "ui_s3Cooking.h"

s3Cooking::s3Cooking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s3Cooking)
{
    ui->setupUi(this);
    connect(ui->nextBtn, &QPushButton::clicked, this, &s3Cooking::nextPage);
}

s3Cooking::~s3Cooking()
{
    delete ui;
}

void s3Cooking::nextPage()
{
    emit goToPage4();
}
