#include "ingredient.h"
#include<QDebug>

Ingredient::Ingredient()
{

}

Ingredient::Ingredient(QString name, QString category, bool isVegan, bool isNutAllergic):
name(name),
category(category),
isVegan(isVegan),
isNutAllergic(isNutAllergic)
{
    setPixmap();
    isCut = false;
    isMixed = false;
    isBoiled = false;
    isFried = false;
}

//All getter methods:
QString Ingredient::getName() const {
    return name;
}

QString Ingredient::getCategory() const {
    return category;
}

QPixmap Ingredient::getPixmap() const
{
    return pixmap;
}

bool Ingredient::getIsVegan() const
{
    return isVegan;
}

bool Ingredient::getIsNutAllergic() const
{
    return isNutAllergic;
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

   qDebug()<<path;

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
