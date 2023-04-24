#ifndef RECIPENEW_H
#define RECIPENEW_H

#include "ingredient.h"

using std::map;
using std::tuple;

class RecipeNew {
public:
    RecipeNew();

    // [== RECIPE DEFINITIONS ==]


    // [== COOKING LOGIC ==]
    QList<Ingredient> getIngredeints();

    map<Ingredient, int> getTasks(int step) const;
    map<Ingredient, QString> getTasksText(int step) const;

    QString getDisplayText(int step) const { return m_recipeDisplayText[step]; };
    int isCompleted(int step) const { return step == m_recipeTasks.count(); };;

    void addTask(QString text, map<Ingredient, tuple<int, QString>> tasks);

private:
    // [== RECIPE DEFINITIONS ==]


    // [== COOKING LOGIC ==]
    QList<map<Ingredient, tuple<int, QString>>> m_recipeTasks;
    QList<QString> m_recipeDisplayText;

};


#endif // RECIPENEW_H
