#include "MainWindow.h"
#include "s1Pantry.h"
#include "s2Recipe.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->show();

    page1 = new s1Pantry(this);
    page2 = new s2Recipe(this);
    ui->stackedWidget->addWidget(page1);
    ui->stackedWidget->addWidget(page2);
    ui->stackedWidget->setCurrentWidget(page1);

    connect(page1, &s1Pantry::goToPage2, this, &MainWindow::switchToPage2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switchToPage2()
{
    ui->stackedWidget->setCurrentWidget(page2);
}
