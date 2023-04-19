#include "MainWindow.h"
#include <QApplication>
#include "model.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model model;
    MainWindow w(model);

    //set app icon
    QIcon icon(":/sprites/icons/Kitchen.PNG");
    a.setWindowIcon(icon);

    w.show();
    return a.exec();

}
