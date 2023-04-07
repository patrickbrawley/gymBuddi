#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QBoxLayout>
#include <QLayout>
#include <QLabel>
#include <QPushButton>


#include <iostream>

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

  
       
    private:

        QPixmap *logo_image, *logo_image1;
        QLabel *top_logo, *bot_logo;
        QPushButton *but_start, *but_stop, *but_reset, *small_logo, *timer, *reps, *camera;

    QVBoxLayout *vLayout1, *vLayout2, *vLayout3, *vLayout4;
    QHBoxLayout *hLayout1;

    void createUI();
    //long count = 0;

};

#endif //MAINWINDOW_H