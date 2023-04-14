#include "mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
 
    //Load logo image
    QPixmap pixmap1("/home/gymbuddi3/gymBuddi/code/GUI-3/small_logo.png");
    QPixmap pixmap3("/home/gymbuddi3/gymBuddi/code/GUI-3/small_logo.png");    
    
    // Create the widget Combo box
    combo_box = new QComboBox();

    // Create the links for selecting the relevent excerise (further devolpment required) for the working models
    combo_box->addItem("Option 1");
    combo_box->addItem("Option 2");
    combo_box->addItem("Option 3");

    // Create the widgets for the QPushbuttons start stop reset
    button1 = new QPushButton("Start");
    button2 = new QPushButton("Stop");
    button3 = new QPushButton("Reset");

    // Create the QLabels widgets for the logos, camera, and texts  
    label1 = new QLabel("Logo");
    label2 = new QLabel("00:00");
    label3 = new QLabel("Timer");
    label4 = new QLabel("Camera");
    label5 = new QLabel("Logo1");
    label6 = new QLabel("GYMBUDDI");
    label7 = new QLabel("   Your Workout Companion");
    
    // Create the timer object
    timer = new CountUpTimer(this);

    // Create the camera object
    Window* camera_window = new Window();




    // Set the colour of the background with a grey gradient
    setStyleSheet("QMainWindow {background: qlineargradient(spread:reflect, x1:0.5, y1:0, x2:0, y2:0, stop:0 #474c53, stop:1 #323841);}");


    // Style the QpushButtons with white text, a thicker border with a rduis, a colour for the background, style and size the text font
    button1->setStyleSheet("QPushButton{ color: white; border: 4px solid black; border-radius: 10px; background: #32a862; padding: 0 8px; font-family: Arial Black; font-size: 14px; font-weight: bold; }");
    button2->setStyleSheet("QPushButton{ color: white; border: 4px solid black; border-radius: 10px; background: #a83232; padding: 0 8px; font-family: Arial Black; font-size: 14px; font-weight: bold; }");
    button3->setStyleSheet("QPushButton{ color: white; border: 4px solid black; border-radius: 10px; background: #327da8; padding: 0 8px; font-family: Arial Black; font-size: 14px; font-weight: bold; }");

    // Style the Labels where required with Altering the font size and style, and adding a border to the timer labels
    label1->setStyleSheet("QLabel{ border: 4px solid black; border-radius: 10px; padding: 0 8px; }");
    label2->setStyleSheet("QLabel{ color: white; border: 4px solid black; border-radius: 10px; padding: 0 8px; font-family: Arial Black; font-size: 14px; font-weight: bold; }");
    label3->setStyleSheet("QLabel{ color: white; border: 4px solid black; border-radius: 10px; padding: 0 8px; font-family: Arial Black; font-size: 14px; font-weight: bold; }");
    //label4->setStyleSheet("QLabel{ border: 4px solid black; border-radius: 10px; padding: 0 8px; }");
    label5->setStyleSheet("QLabel{ border: none; border-radius: 10px; padding: 0 8px; }");
    label6->setStyleSheet("QLabel{ color: white; border: none; border-radius: 10px; padding: 0 8px; font-family: Arial Black; font-size: 72px; font-weight: bold; }");
    label7->setStyleSheet("QLabel{ color: white; border: none; border-radius: 10px; padding: 0 8px; font-family: Arial Black; font-size: 28px; font-weight: bold; }");


    //Set button and label dimesions
    button1->setFixedHeight(100);
    button1->setFixedWidth(150);
    button2->setFixedHeight(100);
    button2->setFixedWidth(150);
    button3->setFixedHeight(100);
    button3->setFixedWidth(150);
    label1->setFixedHeight(100);
    label1->setFixedWidth(150);
    label2->setFixedHeight(75);
    label2->setFixedWidth(300);
    label3->setFixedHeight(75);
    label5->setFixedHeight(200);

    // set the pixmap at the labe image
    pixmap1 = pixmap1.scaled(label1->size(), Qt::KeepAspectRatio);
    label1->setPixmap(pixmap1);

    pixmap3 =pixmap3.scaled(label5->size(), Qt::KeepAspectRatio);
    label5->setPixmap(pixmap3);

    // Create the layout
    QVBoxLayout *layout_combo_camera = new QVBoxLayout();
    QHBoxLayout *layout_start_stop = new QHBoxLayout();
    QHBoxLayout *layout_reset_logo = new QHBoxLayout();
    QVBoxLayout *layout_controls = new QVBoxLayout();
    QHBoxLayout *layout_controls_camera = new QHBoxLayout();
    QVBoxLayout *layout_banner_text = new QVBoxLayout();
    QHBoxLayout *layout_banner = new QHBoxLayout();
    QVBoxLayout *layout_window = new QVBoxLayout();


    //Groups the Conbo box and camera together in a vertical layout
    layout_combo_camera->addWidget(combo_box);
    layout_combo_camera->addWidget(camera_window);

    //Create the camera widget
    QWidget *camera_widget = new QWidget();
    camera_widget->setLayout(layout_combo_camera);
    camera_widget->setStyleSheet("QWidget {border: 2px solid white; border-radius: 10px;}");
   

    //Groups the start and stop button together horizontally
    layout_start_stop->addWidget(button1);
    layout_start_stop->addWidget(button2);

    //groups the rest and logo together horizontally
    layout_reset_logo->addWidget(button3);
    layout_reset_logo->addWidget(label1);

    //Creates the vertical layout grouping the layout_start_stop, layout_reset_logo, timer, and reps counters together
    layout_controls->addLayout(layout_start_stop);
    layout_controls->addLayout(layout_reset_logo);
    layout_controls->addWidget(label3);
    layout_controls->addWidget(label2);

    // Stetching the Qlabels in the widget to the width of the widget
    layout_controls->addStretch();

    //Create the controls widget from the layout_controls
    QWidget *controls_widget = new QWidget();
    controls_widget->setLayout(layout_controls);

    // Sets the width of the widget
    controls_widget->setFixedWidth(320);

    // Sets the style for the border of the control widget to white with a radius at the conner
    controls_widget->setStyleSheet("QWidget {border: 2px solid white; border-radius: 10px;}");

    //Creates a layout to group the controls and comera widget together
    layout_controls_camera->addWidget(controls_widget);
    layout_controls_camera->addWidget(camera_widget);

    //Groups the text for the banner together
    layout_banner_text->addWidget(label6);
    layout_banner_text->addWidget(label7);


    //Adds the logo besides the banner text in there layout
    layout_banner->addWidget(label5);
    layout_banner->addLayout(layout_banner_text);

    //Create the banner widget and set the layout
    QWidget *banner_widget = new QWidget();
    banner_widget->setLayout(layout_banner);

    // Sets the style for the banner widget with a white border and raduised at the corners
    banner_widget->setStyleSheet("QWidget {border: 2px solid white; border-radius: 10px; }");

    // Sets the height for the banner widget
    banner_widget->setFixedHeight(200);



    //Creates the layout for the window for the controls and camera layout and the banner widget
    layout_window->addLayout(layout_controls_camera);
    layout_window->addWidget(banner_widget);



    // Connect the buttons start, stop, and reset to the timer slots
    connect(button1, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(button2, &QPushButton::clicked, this, &MainWindow::stopTimer);
    connect(button3, &QPushButton::clicked, this, &MainWindow::resetTimer);

    // Connect the buttons start and stop to the camera
    connect(button1, &QPushButton::clicked, camera_window, &Window::show);
    connect(button2, &QPushButton::clicked, camera_window, &QWidget::close);

    // Connects the camera window to the label
    connect(camera_window, SIGNAL(sendImage(cv::Mat)), this, SLOT(updateOutputLabel(cv::Mat)));
   
    // Set the central widget
    QWidget *central_widget = new QWidget();
    central_widget->setLayout(layout_window);

    // Sets the central widget of the main window to the newly created QWidget
    setCentralWidget(central_widget);
}

// This dealloactes from memory the GUI widgets and the objects for the timer and camera
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

// This function starts the countuptimer object which counts from 0 to 120 seconds in 1 seconds increments
void MainWindow::startTimer()
{
    timer->start(0, 120, 1, [&](int count) {
        
        // Calculates the values in minutes and seconds
        int minutes = count / 60;
        int seconds = count % 60;
        
        // Formats the minutes and seconds into a string starting with the value 0
        QString text = QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
        
        // Sets the text of the label to the formatted string
        label2->setText(text);
    }, [&]() {
        // Finished callback
    });
}

// This function stops the timer
void MainWindow::stopTimer()
{
    timer->stop();
}

// This function stops the timer and resets the label to "00:00"
void MainWindow::resetTimer()
{
    timer->stop();
    label2->setText("00:00");
}

// This function updates a QLabel "Timer" to display the value for the timer in minutes and seconds
void MainWindow::updateLabel2(int value)
{
    // Calculates the values in minutes and seconds
    int minutes = value / 60;
    int seconds = value % 60;

    // Formats the minutes and seconds into a string starting with the value 0
    QString text = QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
    
    // Sets the text of the label to the formatted string
    label2->setText(text);
}

// This fuction updates a label with an image with an RGB format
//It converts an OpenCv Mat to a QImage that is used to set the Pixmap for the QLabel
void MainWindow::updateOutputLabel(const cv::Mat& image)
{
    const QImage qimage(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
    label4->setPixmap(QPixmap::fromImage(qimage));
}


