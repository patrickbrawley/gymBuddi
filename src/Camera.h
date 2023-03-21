#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <stdlib.h>
#include <thread>

#include "PipelineLink.h"
#include "CameraSettings.h"



class Camera: public PipelineLink{
public:
    Camera();
    Camera(CameraSettings settings);
    bool getOn();
    void setOn(bool state);
    void Start();
    void Stop();
    
private:
    void postFrame();
    void threadLoop();
    cv::VideoCapture videoCapture;
    CameraSettings cameraSettings;
    
    std::thread cameraThread;

    bool isOn = false;
};
