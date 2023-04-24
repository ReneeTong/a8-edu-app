#ifndef S1PANTRY_H
#define S1PANTRY_H

#include <QWidget>
#include <QGroupBox>
#include"foodLibrary.h"

namespace Ui {
class s1Pantry;
}

class s1Pantry : public QWidget
{
    Q_OBJECT

public:
    explicit s1Pantry(QWidget *parent = nullptr);
    ~s1Pantry();

    void addIngredient(Ingredient *i);
    void removeIngredient(Ingredient *i);

public slots:
    void nextPage();

signals:
    void goToPage2();
    void sendSelectedIngredients(QList<Ingredient*>);

private:
    Ui::s1Pantry *ui=nullptr;

    QList<Ingredient*> selectedIngredients;

};




#endif // S1PANTRY_H
