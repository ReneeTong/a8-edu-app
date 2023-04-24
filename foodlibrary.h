#ifndef FOODLIBRARY_H
#define FOODLIBRARY_H

#include "ingredient.h"
#include"recipe.h"
#include "recipenew.h"
#include<vector>
using namespace std;

class FoodLibrary
{
public:

    FoodLibrary();
    vector<Ingredient*> getAllIngredients()const {return allIngredients;}
    vector<Recipe*> getAllRecipes() const {return recipes;}
    QList<RecipeNew*> getAllRecipesNew() const {return m_recipes; };

    Ingredient* getIngredientByName(const QString& name) const;
    Recipe* getRecipeByName(const QString& recipeName) const;

private:
    vector<Ingredient*> allIngredients;
    vector<Recipe*> recipes;

    QList<RecipeNew*> m_recipes;

    void initialRecipes();

};

#endif // FOODLIBRARY_H
