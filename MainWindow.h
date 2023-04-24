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

private:
    Ui::MainWindow *ui;
    s0Title *page0;
    s1Pantry *page1;
    s2Recipe *page2;
    s3Cooking *page3;
    s4Complete *page4;
};
#endif // MAINWINDOW_H
