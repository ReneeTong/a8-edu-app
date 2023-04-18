#ifndef FOODLIBRARY_H
#define FOODLIBRARY_H

#include "ingredient.h"
#include"recipe.h"
#include<vector>
using namespace std;

class FoodLibrary
{
public:

    FoodLibrary();
    vector<Ingredient*>getAllIngredients()const;
    vector<Recipe*>getAllRecipes() const;

private:
    vector<Ingredient*> allIngredients;
    vector<Recipe*> recipes;

    void initialIngredients();
    void initialRecipes();

 protected:
    Ingredient* broccoli = new Ingredient("broccoli", "vege",true, false);
    Ingredient* tomato = new Ingredient("tomato", "vege", true, false);
    Ingredient * peanut = new Ingredient("peanut", "condiment", true, true);
    Ingredient* beef = new Ingredient("beef", "meat", false, false);
    Ingredient * pork = new Ingredient("pork", "meat", false, false);
    Ingredient* chicken = new Ingredient("chicken","meat", false, false);
    Ingredient* pepper = new Ingredient("pepper", "condiment", true, false);
    Ingredient* soysauce = new Ingredient("soysauce", "condiment", true, false);
};


#endif // FOODLIBRARY_H
