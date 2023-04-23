#include "foodLibrary.h"
#include<QDebug>
FoodLibrary::FoodLibrary()
{
    initialIngredients();
    initialRecipes();

    //Andy Tran Added
    //    Recipe recipe;
    //    QHash<Ingredient*, int> myHash1;
    //    int needed = 3;
    //    myHash1.insert(broccoli, needed);
    //    myHash1.insert(tomato, needed);
    //    myHash1.insert(peanut, needed);

    //    QHash<Ingredient*, int> myHash2;
    //    myHash2.insert(broccoli, needed);
    //    myHash2.insert(tomato, needed);
    //    myHash2.insert(peanut, needed);

    //    QHash<Ingredient*, int> myHash3;
    //    myHash3.insert(broccoli, needed);
    //    myHash3.insert(tomato, needed);
    //    myHash3.insert(peanut, needed);
    //    Step step1 = Step(Action::CUT, myHash1);
    //    Step step2 = Step(Action::MIX, myHash2);
    //    Step step3 = Step(Action::BOIL, myHash3);
    //    QList<Step> stepVector = {step1,step2,step3};
    //    recipe = Recipe(stepVector);

    //    recipe.printSteps();
    //    recipe.resetNeededAmount();
}

void FoodLibrary::initialIngredients()
{
    allIngredients.push_back(broccoli);
    allIngredients.push_back(peanut);
    allIngredients.push_back(tomato);
    allIngredients.push_back(beef);
    allIngredients.push_back(pork);
    allIngredients.push_back(chicken);
    allIngredients.push_back(pepper);
    allIngredients.push_back(soysauce);
    allIngredients.push_back(riceNoodles);
    allIngredients.push_back(carrot);
    allIngredients.push_back(cabbage);
}

void FoodLibrary::initialRecipes()
{
    Recipe* pho = new Recipe();
    //Set all ingredient
    pho->setIngredients({broccoli, carrot, cabbage, riceNoodles,beef, chicken,soysauce});
    pho->setCountry(Country::VIETNAM);
    pho->setName("Pho");
    pho->setDifficulty(3);
    pho->setDescription("1. Chop broccoli, carrot and cabbage. \n "
                        "2. Chop all the proteins including beef or chicken. \n"
                        "3. Put all the chopped meat to boiling water to cook for 2 hours. \n"
                        "4. Add all the vegetables into the soup and cook 30 more minutes. \n"
                        "5. Cook the noodle in the soup for 5 minutes. And add some soysauce. \n"
                        "6. Pour all content to a bowl. ");
    pho->setLearnMore("This is learn more. ");
    pho->setRecipeTags({RecipeTags::DAIRYFREE, RecipeTags::GLUTENFREE, RecipeTags::NUTFREE});
    pho->setTasks(  {
                        {Ingredient(QString("broccoli"), {ActionsPerformed::CUT}), 1},
                        {Ingredient(QString("carrort"), {ActionsPerformed::CUT}), 1},
                        {Ingredient(QString("cabbage"), {ActionsPerformed::CUT}), 1},
                        {Ingredient(QString("beef" ) , {ActionsPerformed::CUT}), 1},
                        {Ingredient(QString("chicken"), {ActionsPerformed::CUT}), 1},

                        //Boil
                        {Ingredient(QString("beef"      ) ,    {ActionsPerformed::CUT, ActionsPerformed::BOIL}), 1},
                        {Ingredient(QString("chicken"   ) , {ActionsPerformed::CUT, ActionsPerformed::BOIL}), 1},
                        {Ingredient(QString("broccoli"  ),{ActionsPerformed::CUT, ActionsPerformed::BOIL}), 1},
                        {Ingredient(QString("carrot"    ),  {ActionsPerformed::CUT, ActionsPerformed::BOIL}), 1},
                        {Ingredient(QString("cabbage"   ), {ActionsPerformed::CUT, ActionsPerformed::BOIL}), 1},
                        {Ingredient(QString("riceNoodle"),{ActionsPerformed::BOIL}), 1},
                        {Ingredient(QString("soysauce"  ) ,{ActionsPerformed::BOIL}), 1}
                    });
}

Recipe* FoodLibrary::getRecipeByName(const QString& recipeName) const {
    for (Recipe* recipe : recipes) {
        if (recipe->getName() == recipeName) {
            return recipe;
        }
    }
    return nullptr;
}

