#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qwt/qwt thermo.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>

//#include <QPixmap>
#include <QBoxLayout>
//#include <QLayout>
//#include <QLabel>
#include <QPushButton>


//#include <iostream>

//using namespace std;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

    void timerEvent( QTimerEvent *);
       
private:

    //QPixmap *logo_image;
    //QLabel *lab_icon;
    QPushButton *but_start, *but_stop, *but_reset, *small_logo, *timer, *reps, *camera, *wide_logo;

    QVBoxLayout *vLayout1, *vLayout2, *vLayout3;
    QHBoxLayout *hLayout;

    long count = 0;

};

#endif //MAINWINDOW_H