#include "recipenew.h"

RecipeNew::RecipeNew() : m_recipeTasks{}, m_recipeDisplayText{}
{

}

void RecipeNew::addTask(QString text, map<Ingredient, int> tasks) {
    m_recipeTasks.append(tasks);
    m_recipeDisplayText.append(text);
}
