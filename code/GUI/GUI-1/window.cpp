#include "window.h"

Window::Window()
{
	myCallback.window = this;
	camera.registerSceneCallback(&myCallback);
	
	// set up the thermometer
	thermo = new QwtThermo; 
	thermo->setFillBrush( QBrush(Qt::red) );
	thermo->setScale(0, 255);
	thermo->show();

	image = new QLabel;

	butstart = new QPushButton("Start");
	butstart->setStyleSheet("background-color: green");
	// see https://doc.qt.io/qt-5/signalsandslots-syntaxes.html
	//connect(button1,&QPushButton::clicked,this,&Window::reset);

	butstop = new QPushButton("Stop");
	butstop->setStyleSheet("background-color: red");
	// see https://doc.qt.io/qt-5/signalsandslots-syntaxes.html
	//connect(button2,&QPushButton::clicked,this,&Window::reset);

	// plot to the left of button and thermometer

	vLayout = new QVBoxLayout();
	vLayout->addWidget(butstart);
	vLayout->addWidget(butstop);
	//hLayout = new QHBoxLayout();
	//hLayout->addWidget(vLayout);
	vLayout->addWidget(image);

	setLayout(vLayout);
	camera.start();
}

Window::~Window()
{
	camera.stop();
}

void Window::updateImage(const cv::Mat &mat) {
	const QImage frame(mat.data, mat.cols, mat.rows, mat.step,
			   QImage::Format_BGR888);
	image->setPixmap(QPixmap::fromImage(frame));
	const int h = frame.height();
	const int w = frame.width();
	const QColor c = frame.pixelColor(w/2, h/2);
	thermo->setValue(c.lightness());
}


