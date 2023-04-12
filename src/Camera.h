#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <stdlib.h>
#include <thread>

#include "PipelineLink.h"
#include "CameraSettings.h"



class Camera: public PipelineLink{
public:
     // Default constructor
    Camera();
     // Constructor that takes a CameraSettings object as a parameter
    Camera(CameraSettings settings);
    // Getter function for the isOn member variable
    bool getOn();
    // Setter function for the isOn member variable
    void setOn(bool state);
    // Function that starts the camera thread and opens the video capture
    void Start();
    // Function that stops the camera thread
    void Stop();
    
private:
    // Function that captures a camera frame and sends it to the scene callback function
    void postFrame();
     // Thread loop function that continuously posts camera frames while the camera is on
    void threadLoop();
     // openCV used to read frames from the camera
    cv::VideoCapture videoCapture;
    // Camera settings object used to configure the camera
    CameraSettings cameraSettings;
    
    // Thread object used to run the camera thread
    std::thread cameraThread;
   // Boolean variable that indicates whether the camera is on or off
    bool isOn = false;
};
