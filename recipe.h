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

enum class RecipeTags{GLUTENFREE, DAIRYFREE, NUTFREE};
enum class Country{VIETNAM,CHINA};

//Andy Tran Added
enum class Action{CUT,MIX,BOIL,STIR_FRY};
class Step {
    Action action;
    QHash<Ingredient*, int>ingredientsMap;
public:
    Step(Action action, QHash<Ingredient*, int> ingredientsMap){
        this->action = action;
        this->ingredientsMap = ingredientsMap;
    }
    QString toString(){
        QString result;
        result += "Action: " + QString::fromStdString(actionToString(action)) + " | ";
        result += "Ingredients: ";
        for (auto it = ingredientsMap.begin(); it != ingredientsMap.end(); ++it) {
            result += "  " + it.key()->getName() + " (" + QString::number(it.value()) + ") |";
        }
        return result;
    }

    std::string actionToString(Action action) {
        switch (action) {
            case Action::CUT: return "cut";
            case Action::MIX: return "mix";
            case Action::BOIL: return "boil";
            case Action::STIR_FRY: return "stir fry";
            default: return "";
        }
    }
};
//---------------------------------------

class Recipe
{
public:

    Recipe();
    Recipe(QString name, int difficulty, QHash<Ingredient *, int> ingredients,
           QVector<RecipeTags>recipeTags, Country country,QString description, QString learnMore,
           QMap<int, Ingredient *> prepSteps, QMap<int, Ingredient *> cookingSteps);

    //Andy Tran Added
    Recipe(QList<Step> steps);
    void printSteps();
    //------------------------

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

    QString getName() const;
    int getDifficulty() const;
    QVector<RecipeTags> getRecipeTags() const;
    void setRecipeTags(const QVector<RecipeTags> &newRecipeTags);
    Country getCountry() const;
    void setCountry(Country newCountry);
    QString getDescription() const;
    void setDescription(const QString &newDescription);
    QString getLearnMore() const;
    void setLearnMore(const QString &newLearnMore);

private:
    QString name;
    int difficulty; //(eg. 3/5)
    QVector<RecipeTags> recipeTags;
    Country country;
    QString description;
    QString learnMore;

    //ingredient is key, the amount is the value
    QHash<Ingredient*, int> ingredients;//when key is a ptr, need to use QHash

    //step order is key, ingredient is the value
    QMap<int, Ingredient*> prepSteps;
    QMap<int, Ingredient*> cookingSteps;

    //Andy Tran Added:
    //QList contains all the steps, QMap is all the ingredients in one step
    //which "int" is number of ingredients need to be completed
    QList<Step> steps;
    //-----------------------------

    //All the recipe with ingredients. Not yet to all everything else.
    QHash<Ingredient *, int> createPhoIngredients();
};

#endif // RECIPE_H
