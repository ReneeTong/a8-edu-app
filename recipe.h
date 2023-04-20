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
    QHash<Ingredient *, int> getIngredients() const{return ingredients;}
    QMap<int, Ingredient *> getPrepSteps() const{return prepSteps;}
    QMap<int, Ingredient *> getCookingSteps() const{return cookingSteps;}
    QString getName() const{return name;}
    int getDifficulty() const{return difficulty;}
    QVector<RecipeTags> getRecipeTags() const{return recipeTags;}
    Country getCountry() const{return country;}
    QString getDescription() const{return description;}
    QString getLearnMore() const{return learnMore;}
    QList<Step> getSteps() const{return steps;}

    //Setters
    void setName(const QString &newName){name = newName;}
    void setDifficulty(int newDifficulty){difficulty = newDifficulty;}
    void setIngredients(const QHash<Ingredient *, int> &newIngredients){ingredients = newIngredients;}
    void setPrepSteps(const QMap<int, Ingredient *> &newPrepSteps){ prepSteps = newPrepSteps; }
    void setCookingSteps(const QMap<int, Ingredient *> &newCookingSteps){ cookingSteps = newCookingSteps; }
    void setRecipeTags(const QVector<RecipeTags> &newRecipeTags){recipeTags = newRecipeTags; }
    void setCountry(Country newCountry){country = newCountry; }
    void setDescription(const QString &newDescription){description = newDescription;}
    void setLearnMore(const QString &newLearnMore){learnMore = newLearnMore; }
    void setSteps(const QList<Step> &newSteps){steps = newSteps;}

    //Read from Json
    static QJsonObject readJsonFile(const QString &filePath);
    static Recipe deserialize(const QJsonObject &jsonObj);

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
