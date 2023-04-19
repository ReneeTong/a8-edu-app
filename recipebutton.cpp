#include "recipebutton.h"
#include "ui_recipebutton.h"

recipeButton::recipeButton(const Recipe &recipe, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recipeButton)
{
    ui->setupUi(this);
    ui->recipeName->setText(recipe.getName());
    qDebug() << "Recipe name:" << recipe.getName(); // Add this line
    ui->recipeDifficulty->setValue(recipe.getDifficulty());
}

recipeButton::~recipeButton()
{
    delete ui;
}

