#include "ingredient.h"
#include<QDebug>

Ingredient::Ingredient()
{
    isCut = false;
    isMixed= false;
    isBoiled = false;
    isFried = false;
}

Ingredient::Ingredient( QString name, FoodCategory cate, QVector<FoodTags> tags ):
    name(name),
    cate(cate),
    tags(tags)
{
    setPixmap();
    isCut = false;
    isMixed= false;
    isBoiled = false;
    isFried = false;
}

