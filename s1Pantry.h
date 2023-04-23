#ifndef S1PANTRY_H
#define S1PANTRY_H

#include <QWidget>
#include <QGroupBox>
#include"foodLibrary.h"
#include "modelnew.h"

namespace Ui {
class s1Pantry;
}

class s1Pantry : public QWidget
{
    Q_OBJECT

public:
    explicit s1Pantry(ModelNew& model, QWidget *parent = nullptr);
    ~s1Pantry();

public slots:
    void nextPage();

signals:
    void goToPage2();
    void onSendS2SelectedIngredients();

private:
    ModelNew& m_model;
    Ui::s1Pantry *ui;
    FoodLibrary foodLib;

};




#endif // S1PANTRY_H
