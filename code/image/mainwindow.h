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

    //void timerEvent( QTimerEvent *);
    void updateImage(const cv::Mat &mat);
       
private:

    //QPixmap *logo_image;
    QLabel *image;
    Camera camera;
    QPushButton *but_start, *but_stop, *but_reset, *small_logo, *timer, *reps, *camera, *wide_logo;

    QVBoxLayout *vLayout1, *vLayout2, *vLayout3;
    QHBoxLayout *hLayout;

    struct MyCallback : Camera::SceneCallback {
        Window* window =nullptr;
        virtual void nextScene(const cv::Mat &mat) {
            if (nullptr != window) {
                window -> updateImage(mat);
            
            }
        }
    };
    
    MyCallback mycallback;
    
    

    //long count = 0;

};

#endif //MAINWINDOW_H