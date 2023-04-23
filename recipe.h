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
//enum class Action{CUT,MIX,BOIL,STIR_FRY};
//class Step {
//    Action action;
//    QHash<Ingredient*, int> ingredientsMap;
//public:
//    Step(Action action, QHash<Ingredient*, int> ingredientsMap){
//        this->action = action;
//        this->ingredientsMap = ingredientsMap;
//    }
//    void resetAmount(){
//        for (auto it = ingredientsMap.begin(); it != ingredientsMap.end(); ++it) {
//            it.value() = 0;
//        }
//    }
//    int getNeededAmount(Ingredient* ingredient){
//        if (ingredientsMap.contains(ingredient)) {
//            return ingredientsMap.value(ingredient);
//        }
//        return 0;
//    }

//    Action getAction(){
//        return action;
//    }

//    QHash<Ingredient*, int>* getIngredients(){
//        return &ingredientsMap;
//    }

//    QString toString(){
//        QString result;
//        result += "Action: " + QString::fromStdString(actionToString(action)) + " | ";
//        result += "Ingredients: ";
//        for (auto it = ingredientsMap.begin(); it != ingredientsMap.end(); ++it) {
//            result += "  " + it.key()->getName() + " (" + QString::number(it.value()) + ") |";
//        }
//        return result;
//    }

//    std::string actionToString(Action action) {
//        switch (action) {
//            case Action::CUT: return "cut";
//            case Action::MIX: return "mix";
//            case Action::BOIL: return "boil";
//            case Action::STIR_FRY: return "stir fry";
//            default: return "";
//        }
//    }
//};
//---------------------------------------

class Recipe
{
public:

    Recipe();
    Recipe(QString name, int difficulty, QHash<Ingredient *, int> ingredients,
           QVector<RecipeTags>recipeTags, Country country,QString description, QString learnMore,
           QMap<int, Ingredient *> prepSteps, QMap<int, Ingredient *> cookingSteps);

    //Andy Tran Added
//    Recipe(QList<Step> steps);
//    void printSteps();
//    QList<Step> getSteps();
//    void resetNeededAmount();
    //------------------------

    //Getters
    QVector<Ingredient *> getIngredients() const{return ingredients;}
    QString getName() const{return name;}
    int getDifficulty() const{return difficulty;}
    QVector<RecipeTags> getRecipeTags() const{return recipeTags;}
    Country getCountry() const{return country;}
    QString getDescription() const{return description;}
    QString getLearnMore() const{return learnMore;}
    QMap<Ingredient, int> getTasks() const{return tasks;}

    //Setters
    void setName(const QString &newName){name = newName;}
    void setDifficulty(int newDifficulty){difficulty = newDifficulty;}
    void setIngredients(const QVector<Ingredient *> &newIngredients){ingredients = newIngredients;}
    void setRecipeTags(const QVector<RecipeTags> &newRecipeTags){recipeTags = newRecipeTags; }
    void setCountry(Country newCountry){country = newCountry; }
    void setDescription(const QString &newDescription){description = newDescription;}
    void setLearnMore(const QString &newLearnMore){learnMore = newLearnMore; }
    void setTasks(const QMap<Ingredient, int> &newTasks){tasks = newTasks;}

private:
    QString name;
    int difficulty; //(eg. 3/5)
    QVector<RecipeTags> recipeTags;
    Country country;
    QString description;
    QString learnMore;
    QMap<Ingredient, int> tasks;
    QVector<Ingredient*> ingredients;

//    //Andy Tran Added:
//    //QList contains all the steps, QMap is all the ingredients in one step
//    //which "int" is number of ingredients need to be completed
//    QList<Step> steps;
//    //-----------------------------

//    //All the recipe with ingredients. Not yet to all everything else.
//    QHash<Ingredient *, int> createPhoIngredients();
};

#endif // RECIPE_H
