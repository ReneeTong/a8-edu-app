#include "s2Recipe.h"
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

        // Get the Pho recipe from the FoodLibrary
        Recipe phoRecipe;
        for (Recipe *recipe : foodLibrary.getAllRecipes()) {
            if (recipe->getName() == "pho") {
                phoRecipe = *recipe;
                break;
            }
        }

        recipeButton *phoButton = new recipeButton(phoRecipe);
        phoButton->setFixedSize(550, 500);
        ui->scrollArea_2->addWidget(phoButton);

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
