#ifndef S4COMPLETE_H
#define S4COMPLETE_H

#include <QWidget>
#include <Box2D/Box2D.h>
#include "recipenew.h"

using namespace std;

namespace Ui {
class s4Complete;
}

class s4Complete : public QWidget
{
    Q_OBJECT

public:
    explicit s4Complete(QWidget *parent = nullptr);
    ~s4Complete();


public slots:
    void nextPage();
//    void receiveSelectedRecipe(RecipeNew *recipe);


signals:
    void goToPage1();
    void exitButtonClicked();
    void restartApp();

private:
    Ui::s4Complete *ui=nullptr;
    RecipeNew *currentRecipe=nullptr;
};

#endif // S4COMPLETE_H





