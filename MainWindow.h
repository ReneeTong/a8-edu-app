#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "s1Pantry.h"
#include "s2Recipe.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void switchToPage2();

private:
    Ui::MainWindow *ui;
    s1Pantry *page1;
    s2Recipe *page2;
};
#endif // MAINWINDOW_H
