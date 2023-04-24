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
    void sendSelectedRecipe(RecipeNew* recipe);
    void sendNameOfRecipe(Recipe recipe);
    void backButtonClicked();

private slots:
    void backButtonClickedSlot();


private:
    Ui::s2Recipe *ui;
    QList<Ingredient*> selectedIngredients;
    FoodLibrary foodLibrary;
    void initializeRecipeButtons();

};

#endif // S2RECIPE_H
