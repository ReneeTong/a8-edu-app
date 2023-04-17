#include "MainWindow.h"
#include "s1Pantry.h"
#include "s2Recipe.h"
#include "ui_MainWindow.h"

#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->show();

    QStackedWidget *stackedWidget = new QStackedWidget;
    setCentralWidget(stackedWidget);

    page0 = new s0Title(this);
    page1 = new s1Pantry(this);
    page2 = new s2Recipe(this);
    page3 = new s3Cooking(this);
    page4 = new s4Complete(this);
    stackedWidget->addWidget(page0);
    stackedWidget->addWidget(page1);
    stackedWidget->addWidget(page2);
    stackedWidget->addWidget(page3);
    stackedWidget->addWidget(page4);
    stackedWidget->setCurrentWidget(page0);

    connect(page0, &s0Title::goToPage1, this, [=]() {
        stackedWidget->setCurrentWidget(page1);
    });
    connect(page1, &s1Pantry::goToPage2, this, [=]() {
        stackedWidget->setCurrentWidget(page2);
    });
    connect(page2, &s2Recipe::goToPage3, this, [=]() {
        stackedWidget->setCurrentWidget(page3);
    });
    connect(page3, &s3Cooking::goToPage4, this, [=]() {
        stackedWidget->setCurrentWidget(page4);
    });
    connect(page4, &s4Complete::goToPage1, this, [=]() {
        stackedWidget->setCurrentWidget(page0);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

