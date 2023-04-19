#include "recipebutton.h"
#include "ui_recipebutton.h"

recipeButton::recipeButton(const Recipe &recipe, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recipeButton)
{
    ui->setupUi(this);

//    // Customize the button appearance and behavior based on the provided recipe
//    // For example, if you have a QLabel named "recipeNameLabel" in your .ui file:
//    ui->recipeNameLabel->setText(recipe.getName());

//    // If you have a QProgressBar named "difficultyProgressBar":
//    ui->difficultyProgressBar->setValue(recipe.getDifficulty());
}

recipeButton::~recipeButton()
{
    delete ui;
}
