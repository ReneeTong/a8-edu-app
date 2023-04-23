#include "model.h"
#include "qdebug.h"


Model::Model(b2World *world, QObject *parent)
    : QObject{parent},
      m_world(world)
{

//    m_recipe->addTask({
//                          {Ingredient("salt", {BOIL}), 1}
//                   });
//    m_recipe->addTask({
//                          {Ingredient("noodle", {BOIL}), 1},
//                          {Ingredient("garlic", {CUT}), 2},
//                          {Ingredient("oil", {FRY}), 2},
//                   });
//    m_recipe->addTask({
//                          {Ingredient("noodle", {BOIL, FRY}), 1},
//                          {Ingredient("garlic", {CUT, FRY}), 2} // if we were to do two at once, more code is needed
//                      });
//    m_recipe->addTask({
//                          {Ingredient("pepper", {FRY}), 1},
//                          {Ingredient("chili yum", {FRY}), 1},
//                          {Ingredient("soy sauce", {FRY}), 1},
//                      });

}


void Model::setRecipe(RecipeNew* recipe) {
    currentTask = 0;
    trackerTask.clear();

    m_recipe = recipe;
    emit updateDisplayText(getDisplayText());
}


void Model::incrementIngredient(Ingredient* ingredient) {
    if (m_recipe->isCompleted(currentTask)) return;

    map<Ingredient, int> tasks = m_recipe->getTasks(currentTask);

    // if the ingredient is part of current "tasks"
    if (tasks.find(*ingredient) != tasks.end()) {
        // if the ingredient doesn't exist, create a tracker for it
        if (trackerTask.find(*ingredient) == trackerTask.end())
            trackerTask[*ingredient] = 0;

        qDebug() << "incremeented";
        // increment tracker
        trackerTask[*ingredient]++;
    }

    if (checkTasks()) {
        currentTask++;

        if (m_recipe->isCompleted(currentTask))
            qDebug() << "WINNER!!!";

        // emit win signal
        // win will clean up model
    }

    emit updateDisplayText(getDisplayText());
}

bool Model::checkTasks() {
    map<Ingredient, int> tasks = m_recipe->getTasks(currentTask);

    for (const auto& [ingredient, count] : tasks) {
        if (trackerTask.find(ingredient) != tasks.end()) {
            if (trackerTask[ingredient] < count) {
                return false;
            }
        } else {
            return false;
        }
    }

    return true;
}

QString Model::getDisplayText() { // ignore this, hard coded @jeffohh
    if (m_recipe->isCompleted(currentTask)) return "Completed!";

    map<Ingredient, int> tasks = m_recipe->getTasks(currentTask);

    QString displayText = m_recipe->getDisplayText(currentTask);
    for (const auto& [ingredient, count] : tasks) {
        displayText = displayText.arg(ingredient.getName()).arg(count);

        int progress = 0;
        if (trackerTask.find(ingredient) != tasks.end()) {
            progress = trackerTask[ingredient];
        }
        displayText = displayText.arg(progress);
    }

    return "Step " + QString::number(currentTask + 1) + ":\n" + displayText;
}



// [== COOKING EVENTS ==]
void Model::cut(Shape *shape) {
    Ingredient *ingredient = static_cast<Ingredient*>(shape->getData());
    if (!ingredient) return;

    // check if cuttable?


    // increment only if it contains CUT attribute
    if (ingredient->actions.contains(CUT)) {
        auto method = [shape]() {
            delete shape;
        };
        actionQueue.append(method);

        incrementIngredient(ingredient);
        return;
    }

    auto method = [this, shape, ingredient]() {
        ingredient->actions.append(CUT);

        b2Vec2 position = shape->getBody()->GetPosition();
        b2Vec2 size = shape->getSize();
        size *= 0.5;

        for (int i = 1; i <= 4; i++) {
            float x = rand() / (RAND_MAX + 1.);
            x = (x - 0.5) * 2;
            float y = rand() / (RAND_MAX + 1.);
            y = (y - 1) * 2;

            b2Vec2 variance(x, y);
            variance *= 15;

            Shape *copy = new Shape(m_world, position + variance, size);
            copy->getBody()->SetLinearVelocity(variance);
            copy->setData(ingredient);
            copy->setStatic(false);
        }

        delete shape;
    };

    actionQueue.append(method);
}

void Model::boil(Shape *shape) {
    Ingredient *ingredient = static_cast<Ingredient*>(shape->getData());
    if (!ingredient) return;

    ingredient->actions.append(BOIL);

    if (ingredient->actions.contains(BOIL)) {
        auto method = [shape]() {
            delete shape;
        };
        actionQueue.append(method);

        incrementIngredient(ingredient);
    }
}
