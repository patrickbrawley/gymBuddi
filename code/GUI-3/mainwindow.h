#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "countuptimer.h"
#include "window.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    // Declare the pointers to the UI widgets
    QComboBox *combo_box;
    QPushButton *button1, *button2, *button3;
    QLabel *label1, *label2, *label3, *label4, *label5, *label6, *label7;

    // Declare the pointer to the countuptimer object
    CountUpTimer *timer; 

private slots:

    // Declare the slots for click button events
    void startTimer();
    void stopTimer();
    void resetTimer();

    // Declare the slots for updating the labels  
    void updateLabel2(int value); 
    void updateOutputLabel(const cv::Mat& image); 

};

#endif // MAINWINDOW_H
