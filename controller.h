#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "ingredient.h"
#include<vector>
using namespace std;

//Tzhou to everyone:

//I know he hasn't mentioned anything about controller,
//But the lib on our graph is actually a controller.
//Ingrediants and Recipes are the models.

//I will first hook up controller with Jeffery's view
//Then based on the cotroller to design the model
class controller
{
public:
    controller();
    vector<Ingredient*>getAllIngredients()const;

private:
    vector<Ingredient*> allIngredients;
};

#endif // CONTROLLER_H
