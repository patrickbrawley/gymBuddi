#include <QApplication>
#include <QLabel>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create a label to display the countdown
    QLabel label("Timer");
    label.show();

    // Create a QTimer object
    QTimer timer;
    timer.setInterval(1000); // Set the timer interval to 1 second

    // Connect the timeout signal of the timer to a lambda function
    QObject::connect(&timer, &QTimer::timeout, [&label, &timer]() {
        static int count = 120; // Initialize a static counter variable

        if (count >= 0) {
            label.setText(QString::number(count--)); // Update the label with the countdown value
        } else {
            label.setText("Timer finished"); // Update the label when the countdown is finished
            timer.stop(); // Stop the timer
        }
    });

    // Start the timer
    timer.start();

    return app.exec();
}

