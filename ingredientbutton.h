#ifndef INGREDIENTBUTTON_H
#define INGREDIENTBUTTON_H

#include "ingredient.h"
#include <QPushButton>
#include <QMainWindow>
#include <QObject>

class IngredientButton : public QPushButton
{
    Q_OBJECT
public:
    IngredientButton(Ingredient, int, QWidget *parent = nullptr);

    Ingredient getIngredient() const;

private:
    Ingredient ingredient;
};

#endif // INGREDIENTBUTTON_H
