#ifndef RECIPEBUTTON_H
#define RECIPEBUTTON_H

#include <QPushButton>
#include <QWidget>
#include "recipe.h"
#include <QPainter>
#include <QMessageBox>

namespace Ui {
class RecipeButton;
}

class recipeButton : public QPushButton
{
    Q_OBJECT

public:
     explicit recipeButton(const Recipe &recipe, QWidget *parent = nullptr, const QList<Ingredient *> &selectedIngredients = QList<Ingredient *>());
    ~recipeButton();

   Q_SIGNAL void ingredientsReadySignal(const QList<Ingredient *> &selectedIngredients);

    static recipeButton* previousClickedRecipe;

    bool isIngredientChosen(const Ingredient &recipeIngredient, const QList<Ingredient *> &chosenIngredients);
    void populateIngredientsList(const QList<Ingredient *> &recipeIngredients, const QList<Ingredient *> &chosenIngredients);

    bool getSelected() const;
    void setSelected(bool);

    Recipe* getRecipe();
protected:
    recipeButton(QWidget *parent = nullptr);

public slots:
    void onClicked();

//    void toggleSelected();
//protected:
//    void paintEvent(QPaintEvent *event) override;

private:

    Ui::RecipeButton *ui;
    Recipe* recipe;
    bool selected;
};

#endif // RECIPEBUTTON_H
