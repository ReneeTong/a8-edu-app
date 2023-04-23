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
    explicit recipeButton(const Recipe &recipe, QWidget *parent = nullptr);   
    ~recipeButton();

    static recipeButton* previousClickedRecipe;

    bool isIngredientChosen(Ingredient* ingredient, const QList<Ingredient*>& chosenIngredients);
    void populateIngredientsList(const QMap<Ingredient, int> tasks, const QList<Ingredient*>& chosenIngredients);
    bool getSelected() const;
    void setSelected(bool selected);

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
