#ifndef S1PANTRY_H
#define S1PANTRY_H

#include <QWidget>

namespace Ui {
class s1Pantry;
}

class s1Pantry : public QWidget
{
    Q_OBJECT

public:
    explicit s1Pantry(QWidget *parent = nullptr);
    ~s1Pantry();

public slots:
    void nextPage();

signals:
    void goToPage2();

private:
    Ui::s1Pantry *ui;
};




#endif // S1PANTRY_H
