#include <QApplication>
#include <QLabel>
#include "repcounter.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QLabel label("Press spacebar to increase the counter.");
    label.show();

    RepCounter repCounter(&label);
    label.installEventFilter(&repCounter);

    QObject::connect(&repCounter, &RepCounter::counterChanged, [&label](int newCounter) {
        label.setText(QString("Counter: %1").arg(newCounter));
    });

    return app.exec();
}
