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
    // remove later
    RecipeNew *noodle = new RecipeNew;
    noodle->addTask("Boil %1 (%3/%2)",
                    {
                          {Ingredient("salt", {BOIL}), 1}
                   });
    noodle->addTask("Cut %1 (%3/%2)\nBoil %4 (%6/%5)\nPut %7 in frying pan (%9/%8)",
                    {
                          {Ingredient("noodle", {BOIL}), 1},
                          {Ingredient("garlic", {CUT}), 4},
                          {Ingredient("oil", {FRY}), 1},
                   });
    noodle->addTask("Fry %1 (%3/%2)\nFry %4 (%6/%5)",
                    {
                          {Ingredient("noodle", {FRY}), 1},
                          {Ingredient("garlic", {FRY}), 1} // if we were to do two at once, more code is needed
                      });
    noodle->addTask("Add to frying pan\n%1 (%3/%2)\n%4 (%6/%5)\n%7 (%9/%8)",
                    {
                          {Ingredient("pepper", {FRY}), 1},
                          {Ingredient("chili yum", {FRY}), 1},
                          {Ingredient("soy sauce", {FRY}), 1},
                      });

    emit goToPage3();
    emit sendSelectedRecipe(noodle);
}

void s2Recipe::recieveSelectedIngredients(QList<Ingredient*> selectedIngredients){
    ui->ingredientArea->clearWidgets();
    for (Ingredient *ingredient : selectedIngredients) {
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
