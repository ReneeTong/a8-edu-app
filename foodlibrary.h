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
    vector<Ingredient*>getAllIngredients()const{return allIngredients;}
    vector<Recipe*>getAllRecipes() const{return recipes;}
    Recipe* getRecipeByName(const QString& recipeName) const;

    Ingredient* broccoli = new Ingredient("Broccoli", VEGETABLE, {VEGAN}, {} );
    Ingredient* tomato = new Ingredient("Tomato", VEGETABLE, {VEGAN}, {} );
    Ingredient * peanut = new Ingredient("Peanut", CONDIMENT, {VEGAN, NUT}, {});
    Ingredient* beef = new Ingredient("Beef", MEAT, {}, {});
    Ingredient * pork = new Ingredient("Pork", MEAT, {}, {});
    Ingredient* chicken = new Ingredient("Chicken",MEAT, {}, {});
    Ingredient* pepper = new Ingredient("Pepper", CONDIMENT, {VEGAN}, {});
    Ingredient* soysauce = new Ingredient("SoySauce", CONDIMENT, {VEGAN}, {});
    Ingredient* riceNoodles = new Ingredient("RiceNoodles", STAPLE, {VEGAN}, {});
    Ingredient* carrot = new Ingredient("Carrot", VEGETABLE, {VEGAN}, {});
    Ingredient* cabbage = new Ingredient("Cabbage", VEGETABLE, {VEGAN}, {});

private:
    vector<Ingredient*> allIngredients;
    vector<Recipe*> recipes;

    void initialIngredients();
    void initialRecipes();

};

#endif // FOODLIBRARY_H
