
#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QString>
#include <QPixmap>
#include <QString>
#include<QVector>
#include <Box2D/Box2D.h>
#include <QObject>

using std::is_permutation;

// thoughts on enums? @jeffohh
enum ActionsPerformed { CUT, BOIL, MIX, FRY};
enum FoodCategory { STAPLE, MEAT, VEGETABLE, CONDIMENT };
enum FoodTags { NUT, VEGAN, Dairy, SUGAR , Gluten};

class Ingredient
{
public:
    Ingredient();
    Ingredient(const QString& name);
    Ingredient( const QString& name,  QList<ActionsPerformed> actions);
    Ingredient(QString name, FoodCategory cate, QVector<FoodTags> tags,
               QList<ActionsPerformed> actions);

    // Getter methods
    QString getName() const{return name; }
    QPixmap getPixmap() const{return pixmap;}
    FoodCategory getCate() const{return cate;}
    QVector<FoodTags> getTags() const{return tags;}
    QList<ActionsPerformed> getActions() const{return actions;}

    //Setters
    void setPixmap(){
        QString path = ":/sprites/icons//";
        path += name;
        path+= ".png";
        QPixmap pix (path);
        pixmap = pix;
    }
    void setPixmap(QString path){
        QPixmap pix (path);
        pixmap = pix;
    }
    void setCate(FoodCategory newCate){cate = newCate;}
    void setTags(const QVector<FoodTags> &newTags){tags= newTags;}
    void setActions(const QList<ActionsPerformed> &newActions){actions = newActions;}

    //new
    QList<ActionsPerformed> actions;
    bool operator==(const Ingredient& other) const;
    bool operator<(const Ingredient& other) const;


private:
    QString name;
    FoodCategory cate;
    QVector<FoodTags> tags;
    QPixmap pixmap;

};

#endif // INGREDIENT_H
