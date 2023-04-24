#include "s2Recipe.h"
#include "ingredientbutton.h"
#include "recipebutton.h"
#include "ui_s2Recipe.h"

s2Recipe::s2Recipe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s2Recipe)
{
    ui->setupUi(this);
    connect(ui->nextBtn, &QPushButton::clicked, this, &s2Recipe::nextPage);
    connect(ui->backBtn, &QPushButton::clicked, this, &s2Recipe::backButtonClickedSlot);

}

s2Recipe::~s2Recipe()
{
    delete ui;
}

void s2Recipe::nextPage()
{
    if (selectedRecipe == nullptr) return;

    emit goToPage3();
    emit sendSelectedRecipe(selectedRecipe);
}

void s2Recipe::recieveSelectedIngredients(QList<Ingredient*> receivedIngredients){
    ui->ingredientArea->clearWidgets();
    for (Ingredient *ingredient : receivedIngredients) {
        IngredientButton *button = new IngredientButton(*ingredient, 75);
        button->setSelectable(false);

        ui->ingredientArea->addWidget(button);
    }


    // load recipes
    ui->scrollArea_2->clearWidgets();

    QList<recipeButton*> buttons;
    for (RecipeNew* recipe : foodLibrary.getAllRecipesNew()) {
        recipeButton *button = new recipeButton(recipe, receivedIngredients);
        buttons.append(button);

        // we can sort here maybe????
        // recipe button can contain some "matching" stuff
        // sort by matching, then difficulty
        ui->scrollArea_2->addWidget(button);
    }

    for (recipeButton* button : buttons) {
        connect(button, &QPushButton::clicked, this, [this, buttons, button]() {
            for (const auto& btn : buttons) {
                btn->setSelected(false);
            }
            button->setSelected(true);
            selectedRecipe = button->getRecipe();
        });
    }
}


////This function is used to compare recipe which will have more matching ingredient with choosenIngredients.
//bool sortRecipeByIngredients (QWidget *widget1, QWidget *widget2 ){
//    Recipe *recipe1 = widget1->property("recipe").value<Recipe *>();
//    Recipe *recipe2 = widget2->property("recipe").value<Recipe *>();

//    if(!recipe1 || !recipe2){
//         return false;
//     }

//     //TODO: Add the list in here later.
//    QList<Ingredient*> choosenIngredients = {};

//     auto countMatchingIngredient = [&](Recipe *recipe){
//        int count = 0;
//            for(Ingredient *ingredient : choosenIngredients){
//            if(recipe->getIngredients().contains(ingredient)){
//                    count++;
//                }
//        }
//            return count;
//    };

//    int matchingIngredients1 = countMatchingIngredient(recipe1);
//    int matchingIngredients2 = countMatchingIngredient(recipe2);

//    return matchingIngredients1 > matchingIngredients2;

//}

void s2Recipe::backButtonClickedSlot() {
    emit backButtonClicked();
}
