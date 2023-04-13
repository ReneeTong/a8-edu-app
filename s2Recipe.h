#ifndef S2RECIPE_H
#define S2RECIPE_H

#include <QWidget>

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

signals:
    void goToPage3();

private:
    Ui::s2Recipe *ui;
};

#endif // S2RECIPE_H
