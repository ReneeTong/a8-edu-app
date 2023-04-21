#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QWidget>

//Andy Tran
#include <Box2D/Box2D.h>
#include <Recipe.h>
#include <ingredient.h>

//global uses
enum STEP{
    STEP0,
    STEP1,
    STEP2,
    STEP3,
    STEP4
};

class Model
{

public:
    Model();

public slots:
    //Andy Tran
    //Call from S2: receiving selected recipe
    void onRecieveRecipe(Recipe* recipe, QVector<Ingredient>* selectedIngre);

    //Call from S3: update what have completed
    //Still need to dicuss what should View send back and forth
    void onStepCookingUpdate();

private:
    //Andy Tran
    Recipe recipe; //selected Recipe
    QVector<Ingredient>* selectedIngre; //selected Ingredients
    STEP curStep = STEP0; //current step. Default is STEP0(0)
    QVector<Ingredient>* todoList; //list of Ingredients need to be done in current step
    QVector<b2Body>* drawBodies; //all the objects that need to be drawn

    //Render the b2Body for each step
    void renderBody();
    //Update the Progress List
    void updateProgress();
private slots:

signals:
    //Call when transfer from S2 -> S3 until S3 is complete.
    //Update the current step, recipe, the progress, and vector of b2Body for drawing purposes
    void onS3Update(STEP curStep, QVector<Ingredient>* todoList);
};

#endif // MODEL_H
