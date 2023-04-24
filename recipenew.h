#ifndef RECIPENEW_H
#define RECIPENEW_H

#include "ingredient.h"

using std::map;
using std::tuple;

class RecipeNew {
public:
    RecipeNew(QString name);

    // [== RECIPE DEFINITIONS ==]
    QString getName() const { return m_name; };

    QString getDescription() const { return m_description; };
    QString getLearnMore() const { return m_learnMore; };
    int getDifficulty() const { return m_difficulty; };
    QPixmap getPixmap() const { return m_pixmap; };


    void setDescription(QString text) { m_description = text; };
    void setLearnMore(QString text) { m_learnMore = text; };
    void setDifficulty(int difficulty) { m_difficulty = difficulty; };
    void setPixmap(QPixmap pixmap) { m_pixmap = pixmap; };

    // [== COOKING LOGIC ==]
    QList<Ingredient> getIngredeints();

    map<Ingredient, int> getTasks(int step) const;
    map<Ingredient, QString> getTasksText(int step) const;

    QString getDisplayText(int step) const { return m_recipeDisplayText[step]; };
    int isCompleted(int step) const { return step == m_recipeTasks.count(); };

    void addTask(QString text, map<Ingredient, tuple<int, QString>> tasks);

private:
    // [== RECIPE DEFINITIONS ==]
    QString m_name;

    QString m_description;
    QString m_learnMore;
    int m_difficulty;
    QPixmap m_pixmap;

    // [== COOKING LOGIC ==]
    QList<map<Ingredient, tuple<int, QString>>> m_recipeTasks;
    QList<QString> m_recipeDisplayText;

};


#endif // RECIPENEW_H
