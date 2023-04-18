#ifndef RECIPE_H
#define RECIPE_H

#include<vector>
#include<QMap>
#include<QHash>
#include "ingredient.h"
using namespace std;

class Recipe
{
public:
    Recipe(QHash<Ingredient *, int> ingredients, QMap<int, Ingredient *> prepSteps, QMap<int, Ingredient *> cookingSteps);

    //Getters
    QHash<Ingredient *, int> getIngredients() const; //pantry use this
    QMap<int, Ingredient *> getPrepSteps() const; // box2d cutting mixing stage use this
    QMap<int, Ingredient *> getCookingSteps() const; // box2d cooking stage use this

private:
    //ingredient is key, the amount is the value
    QHash<Ingredient*, int> ingredients;//when key is a ptr, need to use QHash

    /**
     *Recipe1:
     *
     *Ingredients :tomato 2, broccoli 1, beef 250 gram(1 serving), soysauce 1;
     *
     *Steps:
     *  1. Cut all tomato, broccoli, beef;
     *  2. Mix all pre-cut tomato and pre-cut broccoli;
     *  3. Fry all pre-cut ingredients and add soysauce;
     *
     * How to verify:
     *
     *  1. prep steps should have:
     *      1 cut tomato, 1 cut broccoli, 1 cut beef,
     *      1 cut and mixed and tomato, 1 cut and mixed broccli;
     *
     *  2. cooking step should have
     *      1 cut & mixed & fired tomato, 1 cut & mixed & fired broccoli,
     *      1 cut & fried beef, 1 fired soysauce.
     *
     **/
    //step order is key, ingredient is the value
    QMap<int, Ingredient*> prepSteps;
    QMap<int, Ingredient*> cookingSteps;
};

#endif // RECIPE_H
