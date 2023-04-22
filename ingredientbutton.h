#ifndef INGREDIENTBUTTON_H
#define INGREDIENTBUTTON_H

#include "ingredient.h"
#include <QPushButton>
#include <QMainWindow>
#include <QObject>
#include <QEvent>

class IngredientButton : public QPushButton
{
    Q_OBJECT
public:
    IngredientButton(Ingredient, int, QWidget *parent = nullptr);

    Ingredient getIngredient() const;
    bool getSelected() const;
    void setSelected(bool);

private:
    Ingredient ingredient;
    bool selected;
signals:
    void onSelectedListUpdate(Ingredient);
};

#endif // INGREDIENTBUTTON_H
