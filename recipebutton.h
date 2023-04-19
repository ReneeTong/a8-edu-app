#ifndef RECIPEBUTTON_H
#define RECIPEBUTTON_H

#include <QWidget>
#include "recipe.h"

namespace Ui {
class recipeButton;
}

class recipeButton : public QWidget
{
    Q_OBJECT

public:
    explicit recipeButton(const Recipe &recipe, QWidget *parent = nullptr);
    ~recipeButton();

private:
    Ui::recipeButton *ui;
};

#endif // RECIPEBUTTON_H
