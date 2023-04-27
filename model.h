#ifndef MODEL_H
#define MODEL_H

#include "ingredient.h"
#include "recipenew.h"
#include "shape.h"
#include <QObject>
#include "qfont.h"
#include <QSoundEffect>

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

    RecipeNew *m_recipe=nullptr;
    b2World *m_world=nullptr;
    QSoundEffect *cutSound;
    QSoundEffect *boilSound;
    QSoundEffect *frySound;

signals:
    void updateDisplayText(QString text); // temp feedback solution
    void enableFinalized();
};

#endif // MODEL_H
