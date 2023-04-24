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
                        "3. Put all the chopped meat to boiling water to cook for 5 hours. \n"
                        "4. Add all the vegetables into the soup and cook 30 minutes or more. \n"
                        "5. Cook the noodle in the soup for 5 minutes. And add some soysauce. \n"
                        "6. Pour all content to a bowl. ");
    pho->setLearnMore("<p>What is Phở?</p>"
                         "<p>- Phở is a Vietnamese soup dish consisting of broth, rice noodles (bánh phở), herbs, and meat (usually beef (phở bò), sometimes chicken (phở gà)). Phở is a popular food in Vietnam, where it is served in households, street-stalls, and restaurants country-wide.</p>"
                         "<p>Where did Phở emerge?</p>"
                         "<p>- Residents of the city of Nam Định were the first to create Vietnamese traditional phở</p>"
                         "<p>When did Phở become popular?</p>"
                         "<p>- Originated in the early 20th century in Northern Vietnam, and was popularized throughout the world by refugees after the Vietnam War.</p>"
                         "<p>Fun fact:</p>"
                         "<p>- Because phở's origins are poorly documented, there is disagreement over the cultural influences that led to its development in Vietnam, as well as the etymology of the name.</p>"
                         "<p>- The Hanoi (northern) and Saigon (southern) styles of pho differ by noodle width, sweetness of broth, and choice of herbs and sauce.</p>");



    pho->setRecipeTags({RecipeTags::DAIRYFREE, RecipeTags::GLUTENFREE, RecipeTags::NUTFREE});
    recipes.push_back(pho);
    pho->setTasks(  {
                        {Ingredient(QString("Broccoli"), {ActionsPerformed::CUT}), 1},
                        {Ingredient(QString("Carrort"), {ActionsPerformed::CUT}), 1},
                        {Ingredient(QString("Cabbage"), {ActionsPerformed::CUT}), 1},
                        {Ingredient(QString("Beef" ) , {ActionsPerformed::CUT}), 1},
                        {Ingredient(QString("Chicken"), {ActionsPerformed::CUT}), 1},

                        //Boil
                        {Ingredient(QString("Beef"      ) ,    {ActionsPerformed::CUT, ActionsPerformed::BOIL}), 1},
                        {Ingredient(QString("Chicken"   ) , {ActionsPerformed::CUT, ActionsPerformed::BOIL}), 1},
                        {Ingredient(QString("Broccoli"  ),{ActionsPerformed::CUT, ActionsPerformed::BOIL}), 1},
                        {Ingredient(QString("Carrot"    ),  {ActionsPerformed::CUT, ActionsPerformed::BOIL}), 1},
                        {Ingredient(QString("Cabbage"   ), {ActionsPerformed::CUT, ActionsPerformed::BOIL}), 1},
                        {Ingredient(QString("RiceNoodles"),{ActionsPerformed::BOIL}), 1},
                        {Ingredient(QString("SoySauce"  ) ,{ActionsPerformed::BOIL}), 1}

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

