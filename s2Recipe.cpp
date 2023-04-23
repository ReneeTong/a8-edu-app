#include "s2Recipe.h"
#include "foodLibrary.h"
#include "ingredientbutton.h"
#include "recipebutton.h"
#include "ui_s2Recipe.h"

s2Recipe::s2Recipe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s2Recipe)
{
    ui->setupUi(this);
    connect(ui->nextBtn, &QPushButton::clicked, this, &s2Recipe::nextPage);

    QTimer::singleShot(0, this, [this](){

        FoodLibrary foodLibrary;

        Recipe* phoRecipe = foodLibrary.getRecipeByName("Pho"); // Make sure the name matches the recipe in the FoodLibrary

            recipeButton *phoButton = new recipeButton(*phoRecipe);
            ui->scrollArea_2->addWidget(phoButton);


        //default is the first one
        emit phoButton->clicked(true);

        recipeButton *phoButton1 = new recipeButton(*phoRecipe);
       ui->scrollArea_2->addWidget(phoButton1);

        recipeButton *phoButton2 = new recipeButton(*phoRecipe);
       ui->scrollArea_2->addWidget(phoButton2);

    });

    connect(ui->backBtn, &QPushButton::clicked, this, &s2Recipe::on_backButton_clicked);
}

s2Recipe::~s2Recipe()
{
    delete ui;
}

void s2Recipe::nextPage()
{
    emit goToPage3();
    //emit onRecieveRecipe(recipeButton::previousClickedRecipe->getRecipe());
}

void s2Recipe::recieveSelectedIngredients(QList<Ingredient*> selectedIngre){
    ui->ingredientArea->clearWidgets();
    for (Ingredient *ingredient : selectedIngre) {
        IngredientButton *button = new IngredientButton(*ingredient, 75);
        button->setSelectable(false);

        ui->ingredientArea->addWidget(button);
    }
}

//This function is used to compare recipe which will have more matching ingredient with choosenIngredients.
bool sortRecipeByIngredients (QWidget *widget1, QWidget *widget2 ){
    Recipe *recipe1 = widget1->property("recipe").value<Recipe *>();
    Recipe *recipe2 = widget2->property("recipe").value<Recipe *>();

    if(!recipe1 || !recipe2){
         return false;
     }

     //TODO: Add the list in here later.
    QList<Ingredient*> choosenIngredients = {};

     auto countMatchingIngredient = [&](Recipe *recipe){
        int count = 0;
            for(Ingredient *ingredient : choosenIngredients){
            if(recipe->getIngredients().contains(ingredient)){
                    count++;
                }
        }
            return count;
    };

    int matchingIngredients1 = countMatchingIngredient(recipe1);
    int matchingIngredients2 = countMatchingIngredient(recipe2);

    return matchingIngredients1 > matchingIngredients2;

}

void s2Recipe::on_backButton_clicked() {
    emit backButtonClicked();
}
