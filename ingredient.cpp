#include "ingredient.h"
#include<QDebug>

//Ingredient::Ingredient(QString name, QString category, QString color, QString image, vector<QString> tags, b2BodyDef box2ddef)
//    : name(name), category(category), color(color), image(image), tags(tags), box2ddef(box2ddef) {
//
//}

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

//QString Ingredient::getColor() const {
//    return color;
//}

//QString Ingredient::getImage() const {
//    return image;
//}

//vector<QString> Ingredient::getTags() const {
//    return tags;
//}

//b2BodyDef Ingredient::getBox2dDef() const {
//    return box2ddef;
//}

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

//bool Ingredient::getIsDairyFree() const
//{
//    return isDairyFree;
//}
//
//bool Ingredient::getIsDiabetic() const
//{
//    return isDiabetic;
//}
