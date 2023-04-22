#ifndef S2RECIPE_H
#define S2RECIPE_H

#include <QWidget>
#include "recipe.h"
#include "foodlibrary.h"
#include "Model.h"

namespace Ui {
class s2Recipe;
}

class s2Recipe : public QWidget
{
    Q_OBJECT

public:
    explicit s2Recipe(Model& model, QWidget *parent = nullptr);
    ~s2Recipe();

public slots:
    void nextPage();
    void onS2Update(QVector<Ingredient>* selectedIngre);

signals:
    void goToPage3();
    void onRecieveRecipe(Recipe* recipe);

private:
    Model& m_model;
    Ui::s2Recipe *ui;
    QVector<Ingredient>* selectedIngre;
};

#endif // S2RECIPE_H
