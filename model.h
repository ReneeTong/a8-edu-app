#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QWidget>

//Andy Tran
#include <Box2D/Box2D.h>
#include <Recipe.h>
#include <ingredient.h>
#include <QVector>
#include <QHash>

class Model : public QObject
{
    Q_OBJECT

public:
    explicit Model(QObject *view = nullptr);

public slots:
    //Andy Tran
    //Call from IngredientButton: receiving selected ingredients
    void onSelectedListUpdate(Ingredient ingredient);

    //Call from S1: receiving selected ingredients
    void onSendS2SelectedIngredients();

    //Call from S2: receiving selected recipe
    void onRecieveRecipe(Recipe* recipe);

    //Call from S3: update what have completed
    //Still need to dicuss what should View send back and forth
    void onStepCookingUpdate(Ingredient, Action);

private:
    //Andy Tran
    Recipe recipe; //selected Recipe
    Recipe* copyRecipe; //selected Recipe
    QVector<Ingredient>* selectedIngre = new QVector<Ingredient>(); //selected Ingredients
    int curStep = 1; //current step. Default is STEP0(0)
    QHash<Ingredient*, int>* todoList; //list of Ingredients need to be done in current step
    QVector<b2Body>* drawBodies; //all the objects that need to be drawn

    //Set inital amounts need to all zero
    void resetRecipe();

    //Render the b2Body for each step
    void renderBody();
    //Update the Progress List
    void updateProgress();
private slots:

signals:
    //Call when transfer from S1 -> S2
    void onS2Update(QVector<Ingredient>* selectedIngre);

    //Call when transfer from S2 -> S3 until S3 is complete.
    //Update the current step, recipe, the progress, and vector of b2Body for drawing purposes
    void onS3Update(int curStep, QHash<Ingredient*, int>* todoList);
};

#endif // MODEL_H
