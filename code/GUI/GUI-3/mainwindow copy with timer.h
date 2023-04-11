#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "mytimer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QComboBox *combo_box;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *label6;
    QLabel *label7;
    CountUpTimer *timer; 

private slots:
    void startTimer();
    void stopTimer();
    void resetTimer();
    void updateLabel2(int value); // add slot for updating label2
};

#endif // MAINWINDOW_H
