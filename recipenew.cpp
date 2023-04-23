#include "recipenew.h"

RecipeNew::RecipeNew() : m_recipeTasks{}, m_recipeDisplayText{}
{

}

QList<Ingredient> RecipeNew::getIngredeints() {
    // check filter list from s1 maybe?

    QList<Ingredient> ingredientList;
    for (const auto &tasks : m_recipeTasks) {
        for (const auto& [ingredient, count] : tasks) {
            Ingredient raw(ingredient.getName());
            if (!ingredientList.contains(raw)) {
                ingredientList.append(raw);
            }
        }
    }

    return ingredientList;
}

void RecipeNew::addTask(QString text, map<Ingredient, int> tasks) {
    m_recipeTasks.append(tasks);
    m_recipeDisplayText.append(text);
}
