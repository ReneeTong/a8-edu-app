
#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QString>
#include <QPixmap>
#include <QString>
#include <Box2D/Box2D.h>

// thoughts on enums? @jeffohh
enum FoodCategory { MEAT, VEGETABLE, CONDIMENT };
enum FoodTags { NUT, VEGAN };

class Ingredient
{
public:
    Ingredient();
    Ingredient(QString name, QString category, bool isVegan, bool isNutAllergic);

    // Getter methods
    QString getName() const;
    QString getCategory() const;
    QPixmap getPixmap() const;
    bool getIsVegan() const;
    bool getIsNutAllergic() const;
    bool getIsCut() const;
    bool getIsMixed() const;
    bool getIsBoiled() const;
    bool getIsFried() const;

    //Setters
    void setPixmap();
    void setIsCut(bool isCut);
    void setIsMixed(bool isMixed);
    void setIsBoiled(bool isBoiled);
    void setIsFried(bool isFried);

private:
    QString name;
    QString category;
    QPixmap pixmap;

    bool isVegan;
    bool isNutAllergic;
    bool isCut;
    bool isMixed;
    bool isBoiled;
    bool isFried;
};

#endif // INGREDIENT_H
