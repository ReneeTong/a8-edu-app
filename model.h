#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QWidget>

//Andy Tran
#include <Box2D/Box2D.h>
#include "Box.h"
#include <Recipe.h>
#include <ingredient.h>

//global uses
enum STEP{
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
    void onStepCooking(Recipe* recipe, vector<Ingredient>* selectedIngre);

    //Call from S3: update what have completed
    //Still need to dicuss what should View send back and forth
    void onStepCookingUpdate();

private:
    //Andy Tran
    Recipe* recipe; //selected Recipe
    vector<Ingredient>* selectedIngre; //selected Ingredients

    //All these could be update according to the current step in recipe
    STEP curStep = STEP1; //current step. Default is S1
    vector<Ingredient>* progessList; //list of Ingredients need to be done in current step
    vector<b2Body>* drawBodies; //all the objects that need to be drawn
    Box* boxes; //do we need this?

    //Render the b2Body for each step
    void renderBody();
    //Update the Progress List
    void updateProgress();
private slots:

signals:
    //Call when transfer from S2 -> S3 until S3 is complete.
    //Update the current step, recipe, the progress, and vector of b2Body for drawing purposes
    void onS3Update(STEP curStep, vector<Ingredient>* progessList, vector<b2Body>* drawBodies);
};

#endif // MODEL_H
