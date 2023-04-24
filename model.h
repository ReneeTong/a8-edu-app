#ifndef MODEL_H
#define MODEL_H

#include "ingredient.h"
#include "recipenew.h"
#include "shape.h"
#include <QObject>

using std::function;

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(b2World *world, QObject *parent = nullptr);

    QVector<function<void()>> actionQueue;

    void setRecipe(RecipeNew*);
    RecipeNew * getRecipe(){return m_recipe;}

    void incrementIngredient(Ingredient* ingredient);
    bool checkTasks();
    QString getDisplayText();

public slots:
    void cut(Shape*);
    void boil(Shape*);
    void fry(Shape*);
//    void mix(Shape*);

private:
    int currentTask;
    map<Ingredient, int> trackerTask;

    RecipeNew *m_recipe;
    b2World *m_world;

signals:
    void updateDisplayText(QString text); // temp feedback solution
};

#endif // MODEL_H
