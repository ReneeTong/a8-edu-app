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

//All getter methods:
QString Ingredient::getName() const {
    return name;
}

QPixmap Ingredient::getPixmap() const
{
    return pixmap;
}

bool Ingredient::getIsCut() const
{
    return isCut;
}

bool Ingredient::getIsMixed() const
{
    return isMixed;
}

bool Ingredient::getIsBoiled() const
{
    return isBoiled;
}

bool Ingredient::getIsFried() const
{
    return isFried;
}

void Ingredient::setPixmap()
{
    QString path = ":/sprites/icons//";
    path += name;
    path+= ".png";
    QPixmap pix (path);
    pixmap = pix;

}

void Ingredient::setIsCut(bool isCut)
{
    this->isCut = isCut;
}

void Ingredient::setIsMixed(bool isMixed)
{
    this->isMixed = isMixed;
}

void Ingredient::setIsBoiled(bool isBoiled)
{
    this->isBoiled = isBoiled;
}

void Ingredient::setIsFried(bool isFried)
{
    this->isFried = isFried;
}

FoodCategory Ingredient::getCate() const
{
    return cate;
}

void Ingredient::setCate(FoodCategory newCate)
{
    cate = newCate;
}

QVector<FoodTags> Ingredient::getTags() const
{
    return tags;
}

void Ingredient::setTags(const QVector<FoodTags> &newTags)
{
    tags = newTags;
}
