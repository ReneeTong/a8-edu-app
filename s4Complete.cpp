#include "s4Complete.h"
#include "ui_s4Complete.h"


s4Complete::s4Complete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s4Complete)

{
    ui->setupUi(this);
    connect(ui->tryAgainBtn, &QPushButton::clicked, this, &s4Complete::nextPage);
      connect(ui->ExitBtn, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);

}


s4Complete::~s4Complete()
{
    delete ui;
}

//void s4Complete::receiveSelectedRecipe(RecipeNew *recipe)
//{
//    currentRecipe = recipe;
//    ui->titleLab->setText(QString("You have successfully made %1").arg(currentRecipe->getName()));
//}

void s4Complete::nextPage()
{
    emit goToPage1();
}


