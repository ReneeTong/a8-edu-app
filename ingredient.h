
#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QString>
#include <vector>
#include<QPixmap>
#include<QString>
#include <Box2D/Box2D.h>

using std::vector;

class Ingredient
{
public:
    //Ingredient(QString name, QString category, QString color, QString image, vector<QString> tags, b2BodyDef box2ddef );
    Ingredient(QString name,QString category, bool isVegan, bool isNutAllergic);

    // Getter methods
    QString getName() const;
    QString getCategory() const;
    //QString getColor() const; //Tingting: for testing
    //QString getImage() const;//Tingting : image will be strictly related to name
    QPixmap getPixmap() const;
    //vector<QString> getTags() const;
    //b2BodyDef getBox2dDef() const;

    //Tzhou added, can delete if not like it
    bool getIsVegan() const;
    bool getIsNutAllergic() const;
    //bool getIsDairyFree() const;
    //bool getIsDiabetic() const;

    //setter
    void setPixmap();

private:
    QString name;
    QString category;
    //QString color;
    //QString image;
    QPixmap pixmap;
    //vector<QString> tags;//Tingting obnoxiously decided not to use this.
    //b2BodyDef box2ddef;//Tingting commented out: box2D hasn't been built yet, for testing purpose, ignore for now.

    //tzhou to Andy D.:
    //since we only have 5 ish tags, it's more convenient to have 5 bools
    //so when checking these tag only need 1 for loop
    //If you don't like it, you delete mine
    //But here it is:
    bool isVegan;
    bool isNutAllergic;
    //bool isDairyFree;
    //bool isDiabetic;
};

#endif // INGREDIENT_H
