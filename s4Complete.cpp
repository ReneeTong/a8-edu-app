#include "s4Complete.h"
#include "ui_s4Complete.h"

s4Complete::s4Complete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s4Complete)
{
    ui->setupUi(this);
    connect(ui->nextBtn, &QPushButton::clicked, this, &s4Complete::nextPage);
}

s4Complete::~s4Complete()
{
    delete ui;
}

void s4Complete::nextPage()
{
    emit goToPage1();
}
