#include "model.h"


Model::Model(b2World *world, QObject *parent)
    : QObject{parent},
      m_world(world)
{

    m_recipe = new RecipeNew;
    m_recipe->addTask("Cut %1 slices (%3/%2)\nBoil a %4 (%6/%5)",
                      {
                          {Ingredient("tomato", {CUT}), 4},
                          {Ingredient("tomato", {BOIL}), 1}
                      });
    m_recipe->addTask("Boil a %1 (%3/%2)",
                      {
                          {Ingredient("tomato", {BOIL}), 2}
                      });
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

        m_recipe->incrementIngredient(ingredient);
        emit updateDisplayText(m_recipe->getDisplayText());
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

        m_recipe->incrementIngredient(ingredient);
        emit updateDisplayText(m_recipe->getDisplayText());
    }
}
