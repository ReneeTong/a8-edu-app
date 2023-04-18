#include "model.h"

Model::Model()
{

}

//Andy Tran
//Slots
void Model::onStepRecipe(QVector<Ingredient>* selectedIngre){
    //Update the list of ingredients from S1
    this->selectedIngre = selectedIngre;
}

void Model::onStepCooking(Recipe* recipe){
    //Update the recipe from S2
    this->recipe = recipe;
}

void Model::onStepCookingUpdate(){

}

//Private helper methods
void Model::renderBody(){
    //TO-DO: render b2body
}

void Model::updateProgress(){
    //TO-DO: update the progress list
}
