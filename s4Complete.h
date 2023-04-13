#ifndef S4COMPLETE_H
#define S4COMPLETE_H

#include <QWidget>
#include <Box2D/Box2D.h>

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



signals:
    void goToPage1();

private:
    Ui::s4Complete *ui;

};

#endif // S4COMPLETE_H





