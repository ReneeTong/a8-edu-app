
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
    Ingredient(const QString &name);
    Ingredient(QString name, FoodCategory cate, QVector<FoodTags> tags);

    // Overloaded operators
    bool operator==(const Ingredient& other) const;

    // Getter methods
    QString getName() const{return name; }
    QPixmap getPixmap() const{return pixmap;}
    FoodCategory getCate() const{return cate;}
    QVector<FoodTags> getTags() const{return tags;}
    bool getIsCut() const{return isCut;}
    bool getIsMixed() const{return isMixed; }
    bool getIsBoiled() const{return isBoiled;}
    bool getIsFried() const{return isFried;}

    //Setters
    void setPixmap(){
        QString path = ":/sprites/icons//";
        path += name;
        path+= ".png";
        QPixmap pix (path);
        pixmap = pix;
    }
    void setIsCut(bool newIsCut){isCut = newIsCut;}
    void setIsMixed(bool newIsMixed){isMixed = newIsMixed;}
    void setIsBoiled(bool newIsBoiled){isBoiled = newIsBoiled;}
    void setIsFried(bool newIsFried){isFried = newIsFried;}
    void setCate(FoodCategory newCate){cate = newCate;}
    void setTags(const QVector<FoodTags> &newTags){tags= newTags;}

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
