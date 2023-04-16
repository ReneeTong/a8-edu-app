
#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QString>
#include <vector>
#include <Box2D/Box2D.h>

using std::vector;

class Ingredient
{
public:
    Ingredient(QString name, QString category, QString color, QString image, vector<QString> tags, b2BodyDef box2ddef );

    // Getter methods
    QString getName() const;
    QString getCategory() const;
    QString getColor() const;
    QString getImage() const;
    vector<QString> getTags() const;
    b2BodyDef getBox2dDef() const;

private:
    QString name;
    QString category;
    QString color;
    QString image;
    vector<QString> tags;
    b2BodyDef box2ddef;
};

#endif // INGREDIENT_H
