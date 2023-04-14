#include "window.h"

Window::Window()
{
	myCallback.window = this;
	camera.registerSceneCallback(&myCallback);
	
	
	image = new QLabel;


	hLayout = new QHBoxLayout();
	hLayout->addWidget(image);

	setLayout(hLayout);
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
	
}

void Window::stopCamera()
{
	camera.stop();
}
