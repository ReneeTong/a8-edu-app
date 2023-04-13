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
    page3 = new s3Cooking(this);
    page4 = new s4Complete(this);
    ui->stackedWidget->addWidget(page1);
    ui->stackedWidget->addWidget(page2);
    ui->stackedWidget->addWidget(page3);
    ui->stackedWidget->addWidget(page4);
    ui->stackedWidget->setCurrentWidget(page1);

    connect(page1, &s1Pantry::goToPage2, this, [=]() {
        ui->stackedWidget->setCurrentWidget(page2);
    });
    connect(page2, &s2Recipe::goToPage3, this, [=]() {
        ui->stackedWidget->setCurrentWidget(page3);
    });
    connect(page3, &s3Cooking::goToPage4, this, [=]() {
        ui->stackedWidget->setCurrentWidget(page4);
    });
    connect(page4, &s4Complete::goToPage1, this, [=]() {
        ui->stackedWidget->setCurrentWidget(page1);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

