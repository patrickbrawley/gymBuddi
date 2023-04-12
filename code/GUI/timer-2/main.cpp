#include <QApplication>
#include <QMainWindow>
#include "TimerControls.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow window;
    TimerControls timerControls;
    window.setCentralWidget(&timerControls);
    window.show();

    return a.exec();
}
