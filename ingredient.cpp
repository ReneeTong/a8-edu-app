
#include "ingredient.h"

Ingredient::Ingredient(QString name, QString category, QString color, QString image, vector<QString> tags, b2BodyDef box2ddef)
    : name(name), category(category), color(color), image(image), tags(tags), box2ddef(box2ddef) {

}

//All getter methods:
QString Ingredient::getName() const {
    return name;
}

QString Ingredient::getCategory() const {
    return category;
}

QString Ingredient::getColor() const {
    return color;
}

QString Ingredient::getImage() const {
    return image;
}

vector<QString> Ingredient::getTags() const {
    return tags;
}

b2BodyDef Ingredient::getBox2dDef() const {
    return box2ddef;
}
