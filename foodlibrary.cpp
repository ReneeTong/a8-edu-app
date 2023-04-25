#include "foodLibrary.h"
#include "recipenew.h"
#include<QDebug>
FoodLibrary::FoodLibrary()
{
    initialRecipes();

    // STAPLE
    {
        Ingredient* riceNoodles = new Ingredient("RiceNoodles", STAPLE, {VEGAN}, {});
        allIngredients.push_back(riceNoodles);
    }

    // MEAT
    {
        Ingredient* beef = new Ingredient("Beef", MEAT, {}, {});
        allIngredients.push_back(beef);

        Ingredient * pork = new Ingredient("Pork", MEAT, {}, {});
        allIngredients.push_back(pork);

        Ingredient* chicken = new Ingredient("Chicken", MEAT, {}, {});
        allIngredients.push_back(chicken);
    }

    // VEGET
    {
        Ingredient* broccoli = new Ingredient("Broccoli", VEGETABLE, {VEGAN}, {} );
        allIngredients.push_back(broccoli);

        Ingredient* tomato = new Ingredient("Tomato", VEGETABLE, {VEGAN}, {} );
        allIngredients.push_back(tomato);

        Ingredient* carrot = new Ingredient("Carrot", VEGETABLE, {VEGAN}, {});
        allIngredients.push_back(carrot);

        Ingredient* cabbage = new Ingredient("Cabbage", VEGETABLE, {VEGAN}, {});
        allIngredients.push_back(cabbage);
    }

    // CONDIMENT
    {
        Ingredient* peanut = new Ingredient("Peanut", CONDIMENT, {VEGAN, NUT}, {});
        allIngredients.push_back(peanut);

        Ingredient* pepper = new Ingredient("Pepper", CONDIMENT, {VEGAN}, {});
        allIngredients.push_back(pepper);

        Ingredient* soysauce = new Ingredient("SoySauce", CONDIMENT, {VEGAN}, {});
        allIngredients.push_back(soysauce);
    }


    // [== RECIPES ==]

    // Fried Noodle?
    {      
        RecipeNew *noodle = new RecipeNew("Fried Noodles");       
        noodle->setPixmap(QPixmap(":/sprites/icons/pho.png"));
        noodle->setDescription("1. Chop broccoli, carrot and cabbage. \n "
                            "2. Chop all the proteins including beef or chicken. \n"
                            "3. Put all the chopped meat to boiling water to cook for 5 hours. \n"
                            "4. Add all the vegetables into the soup and cook 30 minutes or more. \n"
                            "5. Cook the noodle in the soup for 5 minutes. And add some soysauce. \n"
                            "6. Pour all content to a bowl. "
                            );

        noodle->setLearnMore("<p>What is Phở?</p>"
                          "<p>- Phở is a Vietnamese soup dish consisting of broth, rice noodles (bánh phở), herbs, and meat (usually beef (phở bò), sometimes chicken (phở gà)). Phở is a popular food in Vietnam, where it is served in households, street-stalls, and restaurants country-wide.</p>"
                          "<p>Where did Phở emerge?</p>"
                          "<p>- Residents of the city of Nam Định were the first to create Vietnamese traditional phở</p>"
                          "<p>When did Phở become popular?</p>"
                          "<p>- Originated in the early 20th century in Northern Vietnam, and was popularized throughout the world by refugees after the Vietnam War.</p>"
                          "<p>Fun fact:</p>"
                          "<p>- Because phở's origins are poorly documented, there is disagreement over the cultural influences that led to its development in Vietnam, as well as the etymology of the name.</p>"
                          "<p>- The Hanoi (northern) and Saigon (southern) styles of pho differ by noodle width, sweetness of broth, and choice of herbs and sauce.</p>"
                          );
        noodle->setDifficulty(4);

        noodle->addTask("First, describe tasks...",
                        {
                            {Ingredient("Salt", {BOIL}),                {1, "Put salt in the boiling pot"}}
                        });
        noodle->addTask("Very cool!",
                        {
                            {Ingredient("RiceNoodles", {BOIL}),         {1, "Boil the rice noodles until soft"}},
                            {Ingredient("Garlic", {CUT}),               {2, "Mince garlic"}},
                            {Ingredient("Oil", {FRY}),                  {1, "Oil the frying pan"}}
                        });
        noodle->addTask("Epic?",
                        {
                            {Ingredient("RiceNoodles", {FRY}),          {1, "Fry the rice noodles"}},
                            {Ingredient("Garlic", {CUT, FRY}),          {8, "Fry the minced garlic"}}
                        });
        noodle->addTask("Almost done!",
                        {
                            {Ingredient("Pepper", {FRY}),               {1, "Add pepper to the frying pan"}},
                            {Ingredient("ChiliYum", {FRY}),             {1, "Add chili yum to the frying pan"}},
                            {Ingredient("SoySauce", {FRY}),             {1, "Add soy sauce to the frying pan"}}
                        });

        m_recipes.append(noodle);
    }

    // Pho
    {
        RecipeNew* pho = new RecipeNew("Pho");
        pho->setPixmap(QPixmap(":/sprites/icons/pho.png"));
        pho->setDescription("1. Chop broccoli, carrot and cabbage. \n "
                            "2. Chop all the proteins including beef or chicken. \n"
                            "3. Put all the chopped meat to boiling water to cook for 5 hours. \n"
                            "4. Add all the vegetables into the soup and cook 30 minutes or more. \n"
                            "5. Cook the noodle in the soup for 5 minutes. And add some soysauce. \n"
                            "6. Pour all content to a bowl. "
                            );

        pho->setLearnMore("<p>What is Phở?</p>"
                          "<p>- Phở is a Vietnamese soup dish consisting of broth, rice noodles (bánh phở), herbs, and meat (usually beef (phở bò), sometimes chicken (phở gà)). Phở is a popular food in Vietnam, where it is served in households, street-stalls, and restaurants country-wide.</p>"
                          "<p>Where did Phở emerge?</p>"
                          "<p>- Residents of the city of Nam Định were the first to create Vietnamese traditional phở</p>"
                          "<p>When did Phở become popular?</p>"
                          "<p>- Originated in the early 20th century in Northern Vietnam, and was popularized throughout the world by refugees after the Vietnam War.</p>"
                          "<p>Fun fact:</p>"
                          "<p>- Because phở's origins are poorly documented, there is disagreement over the cultural influences that led to its development in Vietnam, as well as the etymology of the name.</p>"
                          "<p>- The Hanoi (northern) and Saigon (southern) styles of pho differ by noodle width, sweetness of broth, and choice of herbs and sauce.</p>"
                          );

        pho->setDifficulty(3);

        pho->addTask("Chop beef and chicken.", {
                         {Ingredient("Beef", {CUT}),                        {1, "Chop beef"}},
                         {Ingredient("Chicken", {CUT}),                     {1, "Chop chicken"}},
                     });
        pho->addTask("Put chopped meats into boiling pot for 5 hours.", {
                         {Ingredient("Beef", {CUT, BOIL}),                  {4, "Boil chopped beef"}},
                         {Ingredient("Chicken", {CUT, BOIL}),               {4, "Boil chopped chicken"}},
                     });

        pho->addTask("Chop broccoli, carrot, and cabbage.", {
                         {Ingredient("Broccoli", {CUT}),                    {1, "Chop broccoli"}},
                         {Ingredient("Carrot", {CUT}),                      {1, "Chop carrot"}},
                         {Ingredient("Cabbage", {CUT}),                     {1, "Chop cabbage"}},
                     });
        pho->addTask("Add chopped vegetables into boiling pot for 30 minutes or more.", {
                         {Ingredient("Broccoli", {CUT, BOIL}),              {4, "Boil chopped broccoli"}},
                         {Ingredient("Carrot", {CUT, BOIL}),                {4, "Boil chopped carrot"}},
                         {Ingredient("Cabbage", {CUT, BOIL}),               {4, "Boil chopped cabbage"}},
                     });

        pho->addTask("Boil the rice noodle in the soup for 5 minutes.", {
                         {Ingredient("RiceNoodles", {BOIL}),                {1, "Boil rice noodles"}},
                     });
        pho->addTask("Add soysauce to the soup.", {
                         {Ingredient("SoySauce", {BOIL}),                   {1, "Add soysauce to the boiling pot"}},
                     });

        m_recipes.append(pho);
    }

}

void FoodLibrary::initialRecipes()
{
//    Recipe* pho = new Recipe();
//    //Set all ingredient
//    pho->setIngredients({broccoli, carrot, cabbage, riceNoodles,beef, chicken,soysauce});
//    pho->loadImageFromFile(":/sprites/icons/pho.png");
//    pho->setCountry(Country::VIETNAM);
//    pho->setName("Pho");
//    pho->setDifficulty(3);
//    pho->setDescription("1. Chop broccoli, carrot and cabbage. \n "
//                        "2. Chop all the proteins including beef or chicken. \n"
//                        "3. Put all the chopped meat to boiling water to cook for 5 hours. \n"
//                        "4. Add all the vegetables into the soup and cook 30 minutes or more. \n"
//                        "5. Cook the noodle in the soup for 5 minutes. And add some soysauce. \n"
//                        "6. Pour all content to a bowl. ");

//    pho->setLearnMore("<p>What is Phở?</p>"
//                         "<p>- Phở is a Vietnamese soup dish consisting of broth, rice noodles (bánh phở), herbs, and meat (usually beef (phở bò), sometimes chicken (phở gà)). Phở is a popular food in Vietnam, where it is served in households, street-stalls, and restaurants country-wide.</p>"
//                         "<p>Where did Phở emerge?</p>"
//                         "<p>- Residents of the city of Nam Định were the first to create Vietnamese traditional phở</p>"
//                         "<p>When did Phở become popular?</p>"
//                         "<p>- Originated in the early 20th century in Northern Vietnam, and was popularized throughout the world by refugees after the Vietnam War.</p>"
//                         "<p>Fun fact:</p>"
//                         "<p>- Because phở's origins are poorly documented, there is disagreement over the cultural influences that led to its development in Vietnam, as well as the etymology of the name.</p>"
//                         "<p>- The Hanoi (northern) and Saigon (southern) styles of pho differ by noodle width, sweetness of broth, and choice of herbs and sauce.</p>");



//    pho->setRecipeTags({RecipeTags::DAIRYFREE, RecipeTags::GLUTENFREE, RecipeTags::NUTFREE});
//    recipes.push_back(pho);
//    pho->setTasks(  {
//                        {Ingredient(QString("Broccoli"), {ActionsPerformed::CUT}), 1},
//                        {Ingredient(QString("Carrort"), {ActionsPerformed::CUT}), 1},
//                        {Ingredient(QString("Cabbage"), {ActionsPerformed::CUT}), 1},
//                        {Ingredient(QString("Beef" ) , {ActionsPerformed::CUT}), 1},
//                        {Ingredient(QString("Chicken"), {ActionsPerformed::CUT}), 1},

//                        //Boil
//                        {Ingredient(QString("Beef"      ) ,    {ActionsPerformed::CUT, ActionsPerformed::BOIL}), 1},
//                        {Ingredient(QString("Chicken"   ) , {ActionsPerformed::CUT, ActionsPerformed::BOIL}), 1},
//                        {Ingredient(QString("Broccoli"  ),{ActionsPerformed::CUT, ActionsPerformed::BOIL}), 1},
//                        {Ingredient(QString("Carrot"    ),  {ActionsPerformed::CUT, ActionsPerformed::BOIL}), 1},
//                        {Ingredient(QString("Cabbage"   ), {ActionsPerformed::CUT, ActionsPerformed::BOIL}), 1},
//                        {Ingredient(QString("RiceNoodles"),{ActionsPerformed::BOIL}), 1},
//                        {Ingredient(QString("SoySauce"  ) ,{ActionsPerformed::BOIL}), 1}

//                    });
}

Ingredient* FoodLibrary::getIngredientByName(const QString& name) const {
    for (Ingredient* ingredient : allIngredients) {
        if (ingredient->getName() == name) {
            return ingredient;
        }
    }
    return nullptr;
}

Recipe* FoodLibrary::getRecipeByName(const QString& recipeName) const {
    for (Recipe* recipe : recipes) {
        if (recipe->getName() == recipeName) {
            return recipe;
        }
    }
    return nullptr;
}

