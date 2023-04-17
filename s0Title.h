#ifndef S0TITLE_H
#define S0TITLE_H

#include <QWidget>

namespace Ui {
class s0Title;
}

class s0Title : public QWidget
{
    Q_OBJECT

public:
    explicit s0Title(QWidget *parent = nullptr);
    ~s0Title();

public slots:
    void nextPage();

signals:
    void goToPage1();

private:
    Ui::s0Title *ui;
};

#endif // S0TITLE_H
