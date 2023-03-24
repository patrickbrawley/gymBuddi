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

	// plot to the left of button and thermometer
	hLayout = new QHBoxLayout();
	hLayout->addWidget(thermo);
	hLayout->addWidget(image);

	setLayout(hLayout);
	camera.start(1);
}

Window::~Window()
{
	camera.stop();
}

void Window::updateImage(const cv::Mat &mat) {
	const QImage frame(mat.data, mat.cols, mat.rows, mat.step,
			   QImage::Format_RGB888);
	image->setPixmap(QPixmap::fromImage(frame));
	const int h = frame.height();
	const int w = frame.width();
	const QColor c = frame.pixelColor(w/2, h/2);
	thermo->setValue(c.lightness());
}
