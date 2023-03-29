#include "Camera.h"

// Default camera constructor
Camera::Camera() : cameraSettings() {
    isOn=true;
}

//// Constructor with camera settings , sets isOn to be true
Camera::Camera(CameraSettings settings) : cameraSettings(settings){
    isOn = true;
}

// Setter function for the isOn member variable
void Camera::setOn(bool state){
    isOn = state;
}
// Thread loop function, continuously adds camera frames to be processed while the camera is on
void Camera::threadLoop(){
    while(isOn){
        postFrame();
    }
}


// Function that captures a camera frame and sends it to the scene callback function
void Camera::postFrame(){
    if(!sceneCallback) return;
    cv::Mat cap;
    videoCapture.read(cap);
    
    
     // Check if the frame capture was successful
    if (cap.empty()) {
        std::cerr << "ERROR! blank frame grabbed\n";
        return;
    }
    Scene s;
    s.frame=cap;
    sceneCallback->NextScene(s);
}


// Function that starts the camera thread and opens the video capture
void Camera::Start(){
    videoCapture.open(cameraSettings.deviceID, cameraSettings.apiID);
    cameraThread = std::thread(&Camera::threadLoop, this);
}

// Function that stops the camera thread
void Camera::Stop(){
    isOn=false;
    cameraThread.join();

}


bool Camera::getOn() {
    return isOn;
}
