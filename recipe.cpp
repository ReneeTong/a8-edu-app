#include "recipe.h"

Recipe::Recipe(QHash<Ingredient *, int> ingredients, QMap<int, Ingredient *> prepSteps, QMap<int, Ingredient *> cookingSteps):
    ingredients(ingredients),
    prepSteps(prepSteps),
    cookingSteps(cookingSteps)
{

}

QHash<Ingredient *, int> Recipe::getIngredients() const
{
    return ingredients;
}

QMap<int, Ingredient *> Recipe::getPrepSteps() const
{
    return prepSteps;
}

QMap<int, Ingredient *> Recipe::getCookingSteps() const
{
    return cookingSteps;
}

