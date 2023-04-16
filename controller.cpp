#include "controller.h"
#include<QDebug>
controller::controller()
{
    Ingredient* broccoli = new Ingredient("broccoli", "vege",true, false);
    Ingredient* tomato = new Ingredient("tomato", "vege", true, false);
    Ingredient * peanut = new Ingredient("peanut", "condiment", true, true);
    Ingredient* beef = new Ingredient("beef", "meat", false, false);
    Ingredient * pork = new Ingredient("pork", "meat", false, false);
    Ingredient* chicken = new Ingredient("chicken","meat", false, false);
    allIngredients.push_back(broccoli);
    allIngredients.push_back(peanut);
    allIngredients.push_back(tomato);
    allIngredients.push_back(beef);
    allIngredients.push_back(pork);
    allIngredients.push_back(chicken);

    qDebug()<<allIngredients[0]->getName();
    qDebug()<<allIngredients[1]->getName();
    qDebug()<<allIngredients[2]->getName();
}

vector<Ingredient *> controller::getAllIngredients() const
{
    return allIngredients;
}
