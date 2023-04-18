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
}

/// Recipe1:
/// Ingredients :tomato 2, broccoli 1, beef 250 gram(1 serving), soysauce 1;
/// Steps:
///     1. Cut all tomato, broccoli, beef;
///     2. Mix all pre-cut tomato and pre-cut broccoli;
///     3. Fry all pre-cut ingredients and add soysauce;
///
void FoodLibrary::initialRecipes()
{
    QHash<Ingredient*, int> ingredients;
    QMap<int, Ingredient*> prepSteps;
    QMap<int, Ingredient*> cookingSteps;

    //start
    ingredients[tomato] = 2;
    ingredients[broccoli] = 1;
    ingredients[beef] = 1;
    ingredients[soysauce] =1;

    //step 1 result
    Ingredient* tomatoCut = new Ingredient();
    *tomatoCut = *tomato;
    tomatoCut->setIsCut(true);
    prepSteps[1] = tomatoCut;

    Ingredient* broccoliCut = new Ingredient();
    *broccoliCut = *broccoli;
    broccoliCut->setIsCut(true);
    prepSteps[2] = broccoliCut;

    Ingredient* beefCut = new Ingredient();
    *beefCut = *beef;
    beefCut->setIsCut(true);
    prepSteps[3] = beefCut;

    //Step 2 result:
    Ingredient* tomatoCutMix = new Ingredient();
    *tomatoCutMix = *tomatoCut;
    tomatoCutMix->setIsMixed(true);
    prepSteps[4] = tomatoCutMix;

    Ingredient* broccoliCutMix = new Ingredient();
    *broccoliCutMix = *broccoliCut;
    broccoliCutMix->setIsMixed(true);
    prepSteps[5] = broccoliCutMix;

    //Step 3 result:
    Ingredient* beefCutFry = new Ingredient();
    *beefCutFry = *beefCut;
    beefCutFry->setIsFried(true);
    cookingSteps[1] = beefCutFry;

    Ingredient* tomatoCutMixFry = new Ingredient();
    *tomatoCutMixFry = *tomatoCutMix;
    tomatoCutMixFry->setIsFried(true);
    cookingSteps[2] = tomatoCutMixFry;

    Ingredient* broccoliCutMixFry = new Ingredient();
    *broccoliCutMixFry = *broccoliCutMix;
    broccoliCutMixFry->setIsFried(true);
    cookingSteps[3] = broccoliCutMixFry;

    Ingredient* soysauceFry = new Ingredient();
    *soysauceFry = *soysauce;
    soysauceFry->setIsFried(true);
    cookingSteps[4] = soysauceFry;

    //create the recipe and add it to the recipes collection
    Recipe* recipe1 = new Recipe(ingredients, prepSteps, cookingSteps);
    recipes.push_back(recipe1);
}
