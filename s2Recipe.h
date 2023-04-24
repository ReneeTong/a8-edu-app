#ifndef S2RECIPE_H
#define S2RECIPE_H

#include <QWidget>
#include "recipenew.h"
#include "foodlibrary.h"

namespace Ui {
class s2Recipe;
}

class s2Recipe : public QWidget
{
    Q_OBJECT

public:
    explicit s2Recipe(QWidget *parent = nullptr);
    ~s2Recipe();

public slots:
    void nextPage();
    void recieveSelectedIngredients(QList<Ingredient*>);

signals:
    void goToPage3();
    void backButtonClicked();
    void sendSelectedRecipe(RecipeNew* recipe);

private slots:
    void backButtonClickedSlot();

private:
    Ui::s2Recipe *ui;
    FoodLibrary foodLibrary;

    RecipeNew* selectedRecipe;

};

#endif // S2RECIPE_H
