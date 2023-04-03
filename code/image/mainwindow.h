#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QBoxLayout>
#include <QLayout>
#include <QLabel>

#include <iostream>

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:

    QPixmap *logo_image;
    QLabel *lab_icon;

    void createUI();
    //int count = 0;

};

#endif //MAINWINDOW_H