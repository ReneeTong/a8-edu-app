#include "model.h"
#include <QDebug>

Model::Model(QObject *parent) : QObject(parent){}

//Andy Tran
//Slots
//void Model::onRecieveRecipe(Recipe* recipe, QVector<Ingredient>* selectedIngre){
//    //Update the recipe from S2
//    this->recipe = *recipe;
//    this->copyRecipe = recipe;
//    this->selectedIngre = selectedIngre;
////    this->todoList = *selectedIngre;
//    recipe->resetNeededAmount();
//}
void Model::onSelectedListUpdate(Ingredient ingredient){
    //Remove if contain already
    if(selectedIngre->contains(ingredient)){
        int index = selectedIngre->indexOf(ingredient);

        // Remove the object at the index
        if (index != -1) {
            selectedIngre->remove(index);
        }
    }
    //Add to the selected list
    else{
        selectedIngre->push_back(ingredient);
    }
    foreach (Ingredient i, *selectedIngre) {
        qDebug() << i.getName();
    }
    qDebug() << "------------------";
}

void Model::onSendS2SelectedIngredients(){
    emit onS2Update(this->selectedIngre);
}

void Model::onRecieveRecipe(Recipe* recipe){
    //Update the recipe from S2
    this->recipe = *recipe;
    this->copyRecipe = recipe;
    recipe->resetNeededAmount();
    qDebug() << "Recipe Model: " << recipe->getName();
}

void Model::onStepCookingUpdate(Ingredient ingredient, Action action){

    //qDebug() << static_cast<int>(action); this is working, will print out the action is receiving.
    //qDebug() << ingredient.getName(); print out the ingredient's name

    //Ruini: comment out code because currently is getting error, but the the signals is working
    //on-progress Recipe
//    QList<Step> steps = recipe.getSteps();
//    Action curAction = steps[curStep-1].getAction();
//    QHash<Ingredient*, int>* curIngredientList = steps[curStep-1].getIngredients();


    //If on-progress Recipe contains this action
//    if(curAction == action){
//            //If on-progress Recipe contains this Ingredient
//            if(curIngredientList->contains(&ingredient)){
//                    //Increase the amount worked on by 1
//                    (*curIngredientList)[&ingredient]++;
//                    if(curIngredientList->value(&ingredient) == copyRecipe->getIngredients().value(&ingredient)){
//                        //Remove this ingredient from on-progress Recipe
//                        curIngredientList->remove(&ingredient);

//                        //If we have completed all the tasks
//                        if(curIngredientList -> size() == 0){
//                            //move to the next step if still have
//                            if(curStep < steps.size()){
//                                curStep = curStep + 1;
//                                todoList = steps[curStep-1].getIngredients();
//                                qDebug() << "Move to step " << curStep;
//                            }
//                            else{
//                                qDebug() << "Completed all the steps";
//                            }
//                        }
//                        else{
//                            todoList = curIngredientList;
//                        }

//                    }

//            }
//    }

//    emit onS3Update(curStep, todoList);
}

//Private helper methods
void Model::resetRecipe(){

}
void Model::renderBody(){
    //TO-DO: render b2body
}

void Model::updateProgress(){
    //TO-DO: update the progress list
}
