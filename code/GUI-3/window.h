#ifndef WINDOW_H
#define WINDOW_H


#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "camera.h"

// class definition 'Window'
class Window : public QWidget
{
	// must include the Q_OBJECT macro for for the Qt signals/slots framework to work with this class
	Q_OBJECT

public:
	Window();
	~Window();
	void updateImage(const cv::Mat &mat);

	QHBoxLayout  *hLayout;  // horizontal layout
	Camera       camera;
	QLabel       *image;

	struct MyCallback : Camera::SceneCallback {
		Window* window = nullptr;
		virtual void nextScene(const cv::Mat &mat) {
			if (nullptr != window) {
				window->updateImage(mat);
			}
		}
	};

	MyCallback myCallback;


	signals:
		void sendImage(const cv::Mat& image);

	private:
	
		// function to stop the camera
		void stopCamera();

};

#endif // WINDOW_H
