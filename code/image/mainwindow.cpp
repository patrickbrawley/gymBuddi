#include "mainwindow.h"

#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent){
    
    createUI();

}

void MainWindow::createUI()
{
    QPixmap pix("/home/gymbuddi3/gymBuddi/images/gymbuddi_landscape_logo.PNG");
    pix = pix.scaledToWidth(1000);

    lab_icon = new QLabel("test",this);
    lab_icon->setPixmap(pix);

    //horizontal layout for icon
    QHBoxLayout *icon_layout = new QHBoxLayout;
    icon_layout->addWidget(lab_icon);



    //set layout in QWidget
    QWidget *window = new QWidget();
    window->setLayout(icon_layout);


    setCentralWidget(window);
    }

 MainWindow::~MainWindow()
 {

 }   