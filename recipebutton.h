#ifndef RECIPEBUTTON_H
#define RECIPEBUTTON_H

#include <QPushButton>
#include <QWidget>
#include "recipenew.h"
#include <QPainter>
#include <QMessageBox>
#include <QTextBlockFormat>
#include <QTextCursor>

namespace Ui {
class RecipeButton;
}

class recipeButton : public QPushButton
{
    Q_OBJECT

public:
    //explicit recipeButton(const Recipe &recipe, QWidget *parent = nullptr, const QList<Ingredient *> &selectedIngredients = QList<Ingredient *>());
    explicit recipeButton(RecipeNew* recipe, QList<Ingredient*> pantry, QWidget *parent = nullptr);
    ~recipeButton();

    bool getSelected() const;
    void setSelected(bool);

    RecipeNew* getRecipe() const { return m_recipe; }

    // jeffohh
    void setTitle(QString text);
    void setDescription(QString text);
    void setLearnMore(QString text);
    void setDifficulty(int difficulty);
    void setPixmap(QPixmap pixmap);
    int getMatchingCount() const{return matchingCount;}
    void setIngredientList(QList<Ingredient> ingredients, QList<Ingredient*> pantry);


protected:
    recipeButton(QWidget *parent = nullptr);

private:
    Ui::RecipeButton *ui=nullptr;
    RecipeNew* m_recipe=nullptr;
    bool selected;
    int matchingCount;
    QString msgBoxStyle;
    QMessageBox *msgBox;
};

#endif // RECIPEBUTTON_H
