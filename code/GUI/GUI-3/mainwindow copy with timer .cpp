#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
 
    // Create the widgets
    combo_box = new QComboBox();
    combo_box->addItem("Option 1");
    combo_box->addItem("Option 2");
    combo_box->addItem("Option 3");

    button1 = new QPushButton("Start");
    button2 = new QPushButton("Stop");
    button3 = new QPushButton("Reset");
    label1 = new QLabel("Logo");
    label2 = new QLabel("00:00");
    label3 = new QLabel("Reps");
    label4 = new QLabel("Camera");
    label5 = new QLabel("Logo1");
    label6 = new QLabel("GYMBUDDI");
    label7 = new QLabel("   Your Workout Companion");
    
    // Create the timer
    timer = new CountUpTimer(this);

    // Create the layout
    QVBoxLayout *layout_window = new QVBoxLayout();
    layout_window->addWidget(combo_box);
    layout_window->addWidget(button1);
    layout_window->addWidget(button2);
    layout_window->addWidget(button3);
    layout_window->addWidget(label1);
    layout_window->addWidget(label2);
    layout_window->addWidget(label3);
    layout_window->addWidget(label4);
    layout_window->addWidget(label5);
    layout_window->addWidget(label6);
    layout_window->addWidget(label7);

    // Connect the buttons to the timer slots
    connect(button1, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(button2, &QPushButton::clicked, this, &MainWindow::stopTimer);
    connect(button3, &QPushButton::clicked, this, &MainWindow::resetTimer);

    // Set the central widget
    QWidget *central_widget = new QWidget();
    central_widget->setLayout(layout_window);
    setCentralWidget(central_widget);
}

MainWindow::~MainWindow()
{
    delete combo_box;
    delete button1;
    delete button2;
    delete button3;
    delete label1;
    delete label2;
    delete label3;
    delete label4;
    delete label5;
    delete label6;
    delete label7;
    delete timer;
}

void MainWindow::startTimer()
{
    timer->start(0, 3600, 1, [&](int count) {
        int minutes = count / 60;
        int seconds = count % 60;
        QString text = QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
        label2->setText(text);
    }, [&]() {
        // Finished callback
    });
}

void MainWindow::stopTimer()
{
    timer->stop();
}

void MainWindow::resetTimer()
{
    timer->stop();
    label2->setText("00:00");
}

void MainWindow::updateLabel2(int value)
{
    int minutes = value / 60;
    int seconds = value % 60;
    QString text = QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
    label2->setText(text);
}
