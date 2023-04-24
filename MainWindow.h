#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "s0Title.h"
#include "s1Pantry.h"
#include "s2Recipe.h"
#include "s3Cooking.h"
#include "s4Complete.h"
#include <QMainWindow>
#include <QVBoxLayout>

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
    void restart();

private:
    Ui::MainWindow *ui=nullptr;
    s0Title *page0=nullptr;
    s1Pantry *page1=nullptr;
    s2Recipe *page2=nullptr;
    s3Cooking *page3=nullptr;
    s4Complete *page4=nullptr;
};
#endif // MAINWINDOW_H
