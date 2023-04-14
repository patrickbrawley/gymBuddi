#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) 
{
    
    // Create a new QApplication
    QApplication app(argc, argv);
    
    // Create a new mainwindow object 
    MainWindow gymbuddi;

    // Show the mainwindow
    gymbuddi.show();

    // Start the application and return the exit code code when complete
    return app.exec();
}
