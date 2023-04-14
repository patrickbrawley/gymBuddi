#include "window.h"

Window::Window()
{
	myCallback.window = this;
	camera.registerSceneCallback(&myCallback);
		
	image = new QLabel;

	hLayout = new QHBoxLayout();
	hLayout->addWidget(image);

	// Sets the layout for the camera
	setLayout(hLayout);
	
	// Starts the camera
	camera.start();
}

// Function stops  the camera when the window is closed
Window::~Window()
{
	camera.stop();
}

// function to update the image to the window
void Window::updateImage(const cv::Mat &mat) {
	const QImage frame(mat.data, mat.cols, mat.rows, mat.step,
			   QImage::Format_BGR888);
	image->setPixmap(QPixmap::fromImage(frame));
	const int h = frame.height();
	const int w = frame.width();
	const QColor c = frame.pixelColor(w/2, h/2);
	
}

// Function to stop the camera
void Window::stopCamera()
{
	camera.stop();
}
