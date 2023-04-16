#include "ingredient.h"
#include<QDebug>

Ingredient::Ingredient(QString name, QString category, bool isVegan, bool isNutAllergic):
name(name),
category(category),
isVegan(isVegan),
isNutAllergic(isNutAllergic)
{
    setPixmap();
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

void Ingredient::setPixmap()
{
    QString path = ":/sprites//";
    path += name;
    path+= ".png";
    QPixmap pix (path);
    pixmap = pix;

   qDebug()<<path;

}
