#include "ingredient.h"
#include<QDebug>

Ingredient::Ingredient()
{

}

Ingredient::Ingredient(const QString &name):
    name(name)
{

}


Ingredient::Ingredient(const QString &name ,QList<ActionsPerformed> actions) :
    name(name),
    actions(actions)
{
    setPixmap();
}


Ingredient::Ingredient( QString name, FoodCategory cate, QVector<FoodTags> tags,QList<ActionsPerformed> actions ):
    name(name),
    cate(cate),
    tags(tags),
    actions(actions)
{
    setPixmap();

}

bool Ingredient::operator==(const Ingredient& other) const {
    if (name != other.name) {
        return false;
    }
    if (actions.size() != other.actions.size()) {
        return false;
    }
    return is_permutation(actions.begin(), actions.end(), other.actions.begin(), other.actions.end());
}

bool Ingredient::operator<(const Ingredient& other) const {
    if (name != other.name) {
        return name < other.name;
    }
    return actions < other.actions;
}



