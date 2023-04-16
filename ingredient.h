
#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QString>
#include <QPixmap>
#include <QString>
#include <Box2D/Box2D.h>

// thoughts on enums? @jeffohh
enum FoodCategory { MEAT, VEGGIE, CONDIMENT };
enum FoodTags { NUT, VEGAN };

class Ingredient
{
public:
    //Ingredient(QString name, QString category, QString color, QString image, vector<QString> tags, b2BodyDef box2ddef );
    Ingredient(QString name, QString category, bool isVegan, bool isNutAllergic);

    // Getter methods
    QString getName() const;
    QString getCategory() const;
    QPixmap getPixmap() const;

    bool getIsVegan() const;
    bool getIsNutAllergic() const;

    void setPixmap();

private:
    QString name;
    QString category;
    QPixmap pixmap;

    bool isVegan;
    bool isNutAllergic;
};

#endif // INGREDIENT_H
