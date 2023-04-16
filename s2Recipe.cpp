#include "s2Recipe.h"
#include "ui_s2Recipe.h"

s2Recipe::s2Recipe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s2Recipe)
{
    ui->setupUi(this);
    connect(ui->nextBtn, &QPushButton::clicked, this, &s2Recipe::nextPage);

    QTimer::singleShot(0, this, [this](){
        for (int i = 0; i < 5; i++) {
            QPushButton *button = new QPushButton("RECIPE " + QString::number(i));
            button->setFixedSize(550, 500);
            ui->scrollArea_2->addWidget(button);
        }
    });
}

s2Recipe::~s2Recipe()
{
    delete ui;
}

void s2Recipe::nextPage()
{
    emit goToPage3();
}
