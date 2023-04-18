#include "foodLibrary.h"
#include<QDebug>
FoodLibrary::FoodLibrary()
{
    initialIngredients();
    initialRecipes();

}

vector<Ingredient *> FoodLibrary::getAllIngredients() const
{
    return allIngredients;
}

vector<Recipe *> FoodLibrary::getAllRecipes() const
{
    return recipes;
}

void FoodLibrary::initialIngredients()
{
    allIngredients.push_back(broccoli);
    allIngredients.push_back(peanut);
    allIngredients.push_back(tomato);
    allIngredients.push_back(beef);
    allIngredients.push_back(pork);
    allIngredients.push_back(chicken);
    allIngredients.push_back(pepper);
    allIngredients.push_back(soysauce);
    allIngredients.push_back(riceNoodles);
    allIngredients.push_back(carrot);
    allIngredients.push_back(cabbage);
}

void FoodLibrary::initialRecipes()
{
    QJsonObject obj;
    Recipe pho;
    obj = Recipe::readJsonFile(":/sprites/recipes/Pho.txt");
    pho = Recipe::deserialize(obj);

    qDebug()<<pho.getName();
    qDebug()<<pho.getDifficulty();
    qDebug()<<pho.getDescription();
    qDebug()<<pho.getLearnMore();
    qDebug()<<"\nIngredients: ";
    qDebug()<<"Name   cut    mix    boil    fired ";
    QHash<Ingredient*, int> ingredients = pho.getIngredients();
    QList<Ingredient*> iList = ingredients.keys();
    for(Ingredient* i : iList){
        qDebug()<<i->getName()<<i->getIsCut()<<i->getIsMixed()
               <<i->getIsBoiled()<<i->getIsFried();

    }


    qDebug()<<"\nPrep Steps: ";
    QMap<int,Ingredient*> prep = pho.getPrepSteps();
    QList<Ingredient*> prepList = prep.values();
    for(Ingredient* p:prepList ){
         qDebug()<<p->getName()<<" Cut: "<<p->getIsCut();
    }

    qDebug()<<"\nCooking Steps: ";
    QMap<int,Ingredient*> cook = pho.getCookingSteps();
    QList<Ingredient*> cookList = cook.values();
    for(Ingredient* c:cookList ){
         qDebug()<<c->getName()<<" Cooked: "<<c->getIsBoiled();
    }

}
