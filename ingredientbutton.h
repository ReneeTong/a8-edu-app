#ifndef INGREDIENTBUTTON_H
#define INGREDIENTBUTTON_H

#include "ingredient.h"
#include <QPushButton>
#include <QMainWindow>
#include <QObject>
#include <QEvent>
#include <QToolTip>
#include <QEvent>

class IngredientButton : public QPushButton
{
    Q_OBJECT
public:
    IngredientButton(Ingredient, int, QWidget *parent = nullptr);

    Ingredient getIngredient() const;
    bool getSelected() const;
    void setSelected(bool);
    void setSelectable(bool);

    //
    bool event(QEvent *event);
private:
    Ingredient ingredient;
    bool selected;
    bool selectable;

signals:
    void onSelectedListUpdate(Ingredient);
    void onSelected(bool);
};

#endif // INGREDIENTBUTTON_H
