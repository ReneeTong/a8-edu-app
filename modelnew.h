#ifndef MODELNEW_H
#define MODELNEW_H

#include "ingredientnew.h"
#include "qdebug.h"
#include "shape.h"
#include <QObject>

using std::function;



class RecipeNew {
public:
    RecipeNew() : tasksTracker{}, m_recipeTasks{} {

    };

    int currentTask = 0;

    map<IngredientNew, int> tasksTracker;

    void incrementIngredient(IngredientNew* ingredient) {
        if (currentTask == m_recipeTasks.count()) return;

        map<IngredientNew, int> tasks = m_recipeTasks[currentTask];

        // if the ingredient is part of current "tasks"
        if (tasks.find(*ingredient) != tasks.end()) {
            // if the ingredient doesn't exist, create a tracker for it
            if (tasksTracker.find(*ingredient) == tasksTracker.end())
                tasksTracker[*ingredient] = 0;

            qDebug() << "incremeented";
            // increment tracker
            tasksTracker[*ingredient]++;
        }

        if (checkTasks()) {
            currentTask++;
            // check bounds of m_steps and currentTask
            qDebug() << currentTask;

            if (currentTask == m_recipeTasks.count())
                qDebug() << "WINNER!!!";

            // emit win signal
            // win will clean up model
        }
    }

    bool checkTasks() {
        map<IngredientNew, int> tasks = m_recipeTasks[currentTask];
        for (const auto& [ingredient, count] : tasks) {
            if (tasksTracker.find(ingredient) != tasks.end()) {
                if (tasksTracker[ingredient] < count) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }

    bool isComplete = false;

    void addTask(map<IngredientNew, int> tasks) {
        m_recipeTasks.append(tasks);
    }

private:
    QList<map<IngredientNew, int>> m_recipeTasks;
};







class ModelNew : public QObject
{
    Q_OBJECT
public:
    explicit ModelNew(b2World *world, QObject *parent = nullptr);

    QVector<function<void()>> actionQueue;

public slots:
    void cut(Shape*);
    void boil(Shape*);
//    void fry(Shape*);
//    void mix(Shape*);

private:
    RecipeNew *m_recipe;
    b2World *m_world;

signals:

};

#endif // MODELNEW_H
