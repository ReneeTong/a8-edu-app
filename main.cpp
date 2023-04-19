#include "MainWindow.h"
#include <QApplication>
#include "model.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model model;
    MainWindow w(model);

    // Create a QIcon object with the path to your icon file
    QIcon icon(":/sprites/icons/Kitchen.PNG");

    // Set the application icon using the setWindowIcon method
    a.setWindowIcon(icon);

    w.show();
    return a.exec();

}
