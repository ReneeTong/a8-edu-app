#ifndef RECIPEBUTTON_H
#define RECIPEBUTTON_H

#include <QPushButton>
#include <QWidget>
#include "recipe.h"
#include <QPainter>

namespace Ui {
class recipeButton;
}

class recipeButton : public QPushButton
{
    Q_OBJECT

public:
    explicit recipeButton(const Recipe &recipe, QWidget *parent = nullptr);
    ~recipeButton();
    bool isIngredientChosen(Ingredient* ingredient, const QList<Ingredient*>& chosenIngredients);
    void populateIngredientsList(const QHash<Ingredient*, int>& ingredients, const QList<Ingredient*>& chosenIngredients);
    bool getSelected() const;
    void setSelected(bool selected);

protected:
    void paintEvent(QPaintEvent *event) override;
private:

    Ui::recipeButton *ui;
      bool selected;
};

#endif // RECIPEBUTTON_H
