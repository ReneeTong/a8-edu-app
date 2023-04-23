#include "s2Recipe.h"
#include "foodLibrary.h"
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

//        Recipe* phoRecipe = foodLibrary.getRecipeByName("Pho");

//        recipeButton *phoButton = new recipeButton(*phoRecipe);
//        ui->scrollArea_2->addWidget(phoButton);

//        //default is the first one
//        emit phoButton->clicked(true);

//        recipeButton *phoButton1 = new recipeButton(*phoRecipe);
//        ui->scrollArea_2->addWidget(phoButton1);

//        recipeButton *phoButton2 = new recipeButton(*phoRecipe);
//        ui->scrollArea_2->addWidget(phoButton2);

    });

    //Andy Tran: connection to send recipe and selected ingredients

    connect(ui->backBtn, &QPushButton::clicked, this, &s2Recipe::on_backButton_clicked);
    //connect(&m_model, &ModelNew::onS2Update, this, &s2Recipe::onS2Update);
    //connect(this, &s2Recipe::onRecieveRecipe, &m_model, &ModelNew::onRecieveRecipe);

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

void s2Recipe::onS2Update(QVector<Ingredient>* selectedIngre){


    this->selectedIngre = selectedIngre;

    foreach (Ingredient i, *selectedIngre) {
        qDebug() << i.getName();
    }
    qDebug() << "------------------";
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

