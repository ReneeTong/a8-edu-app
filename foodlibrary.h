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


private:
    vector<Ingredient*> allIngredients;
    vector<Recipe*> recipes;

    void initialIngredients();
    void initialRecipes();


 protected:

    //enum FoodCategory { MEAT, VEGETABLE, CONDIMENT };
    //enum FoodTags { NUT, VEGAN, DairyFree, LowSugar, GlutenFree};
    //Ingredient(QString name, FoodCategory cate, QVector<FoodTags> tags);

    Ingredient* broccoli = new Ingredient("broccoli", VEGETABLE, {VEGAN} );
    Ingredient* tomato = new Ingredient("tomato", VEGETABLE, {VEGAN} );
    Ingredient * peanut = new Ingredient("peanut", CONDIMENT, {VEGAN, NUT});
    Ingredient* beef = new Ingredient("beef", MEAT, {});
    Ingredient * pork = new Ingredient("pork", MEAT, {});
    Ingredient* chicken = new Ingredient("chicken",MEAT, {});
    Ingredient* pepper = new Ingredient("pepper", CONDIMENT, {VEGAN});
    Ingredient* soysauce = new Ingredient("soysauce", CONDIMENT, {VEGAN});
    Ingredient* riceNoodles = new Ingredient("riceNoodles", STAPLE, {VEGAN});
    Ingredient* carrot = new Ingredient("carrot", VEGETABLE, {VEGAN});
    Ingredient* cabbage = new Ingredient("cabbage", VEGETABLE, {VEGAN});
};

#endif // FOODLIBRARY_H
