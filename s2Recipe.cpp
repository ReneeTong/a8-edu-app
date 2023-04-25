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

    }   

    // Sort the buttons based on the matching count (highest to lowest)
    std::sort(buttons.begin(), buttons.end(), [](const recipeButton* a, const recipeButton* b) {
        return a->getMatchingCount() > b->getMatchingCount();
    });

    //int numRecipesToDisplay = 4;
    for (int i = 0; i < buttons.size(); i++) {
        ui->scrollArea_2->addWidget(buttons[i]);
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

void s2Recipe::backButtonClickedSlot() {
    emit backButtonClicked();
}
