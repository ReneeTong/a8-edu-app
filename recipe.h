#ifndef RECIPE_H
#define RECIPE_H

#include<QVector>
#include<QMap>
#include<QHash>
#include<QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include "ingredient.h"

enum class Tag{GLUTENFREE, DAIRYFREE, NUTFREE};
enum class Country{VIETNAM,CHINA};

class Recipe
{
public:

    Recipe();
    Recipe(QString name, int difficulty, QHash<Ingredient *, int> ingredients,
           QMap<int, Ingredient *> prepSteps, QMap<int, Ingredient *> cookingSteps);

    //Getters
    QHash<Ingredient *, int> getIngredients() const; //pantry use this
    QMap<int, Ingredient *> getPrepSteps() const; // box2d cutting mixing stage use this
    QMap<int, Ingredient *> getCookingSteps() const; // box2d cooking stage use this

    //Read from Json
    static QJsonObject readJsonFile(const QString &filePath);
    static Recipe deserialize(const QJsonObject &jsonObj);


    void setName(const QString &newName);
    void setDifficulty(int newDifficulty);
    void setIngredients(const QHash<Ingredient *, int> &newIngredients);
    void setPrepSteps(const QMap<int, Ingredient *> &newPrepSteps);
    void setCookingSteps(const QMap<int, Ingredient *> &newCookingSteps);

private:
    QString name;
    int difficulty; //(eg. 3/5)

    //ingredient is key, the amount is the value
    QHash<Ingredient*, int> ingredients;//when key is a ptr, need to use QHash

    //step order is key, ingredient is the value
    QMap<int, Ingredient*> prepSteps;
    QMap<int, Ingredient*> cookingSteps;
};

#endif // RECIPE_H
