
#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QString>
#include <QPixmap>
#include <QString>
#include<QVector>
#include <Box2D/Box2D.h>

// thoughts on enums? @jeffohh
enum FoodCategory { MEAT, VEGETABLE, CONDIMENT, STAPLE };
enum FoodTags { NUT, VEGAN, Dairy, SUGAR , Gluten};

class Ingredient
{
public:
    Ingredient();
    Ingredient(QString name, FoodCategory cate, QVector<FoodTags> tags);

    // Getter methods
    QString getName() const;
    QString getCategory() const;
    QPixmap getPixmap() const;
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

    FoodCategory getCate() const;
    void setCate(FoodCategory newCate);
    QVector<FoodTags> getTags() const;
    void setTags(const QVector<FoodTags> &newTags);

private:
    QString name;
    FoodCategory cate;
    QVector<FoodTags> tags;
    QPixmap pixmap;

    bool isCut;
    bool isMixed;
    bool isBoiled;
    bool isFried;
};

#endif // INGREDIENT_H
