#include <functional>
#include <iostream>
#include <thread>

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

enum Err_type {
    NO_ERROR,
    ERR_INIT,
    ERR_EMPTY_FRAME
};

class Camera {
private:
    struct {
        int camIdx;
        int camApi;
        bool isOn = false;
    } CamSettings;

    int errCode;
    cv::Mat currentFrame;
    cv::VideoCapture activeCapture;
    std::thread camThread;
    void camThreadLoop(std::function<void(cv::Mat)> callback);

public:
    Camera(int camIdx = 0, int camApi = cv::CAP_ANY);
    ~Camera();
    void display();
    void startRecording(std::function<void(cv::Mat)> callback);
    void stopRecording();
    int getErr();
};

Camera::Camera(int camIdx, int camApi) {
    /* Set Camera Settings */
    CamSettings.camIdx = camIdx;
    CamSettings.camApi = camApi;

    /* Open Camera */
    cv::VideoCapture capture(camIdx, camApi);
    if (!capture.isOpened()) {
        errCode = ERR_INIT;
        std::cerr << "ERROR " << errCode << ": Can't initialize camera capture" << std::endl;
    }
    activeCapture = capture;

    std::cout << "Frame width: " << capture.get(cv::CAP_PROP_FRAME_WIDTH) << std::endl;
    std::cout << "     height: " << capture.get(cv::CAP_PROP_FRAME_HEIGHT) << std::endl;
    std::cout << "Capturing FPS: " << capture.get(cv::CAP_PROP_FPS) << std::endl;
}

void Camera::display() {
    cv::imshow("Frame", currentFrame);
}

void Camera::camThreadLoop(std::function<void(cv::Mat)> callback) {
    while (CamSettings.isOn) {
        activeCapture.read(currentFrame);

        if (currentFrame.empty()) {
            errCode = ERR_EMPTY_FRAME;
            std::cerr << "ERROR: " << ERR_EMPTY_FRAME << " blank frame grabbed\n";
            return;
        }

        // Pass the current frame to the callback function
        callback(currentFrame);

        display();
        int key = cv::waitKey(1);
        if (key == 27 /*ESC*/) { break; }
    }
}

void Camera::startRecording(std::function<void(cv::Mat)> callback) {
    CamSettings.isOn = true;
    if (!activeCapture.open(CamSettings.camIdx, CamSettings.camApi)) {
        errCode = ERR_INIT;
        std::cerr << "ERROR " << errCode << ": Can't initialize camera capture" << std::endl;
    }

    /* Start Thread */
    camThread = std::thread(&Camera::camThreadLoop, this, callback);
}

void Camera::stopRecording() {
    CamSettings.isOn = false;
    camThread.join();
}

int Camera::getErr() {
    return errCode;
}

Camera::~Camera() {
    CamSettings.isOn = false;
    activeCapture.release();
}

void pipelineCallback(cv::Mat frame) {
    // Do something with the frame
}

int main() {
    Camera cam;
    cam.startRecording(pipelineCallback);
    // ...
}
