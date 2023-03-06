// checks whether the given token has been #defined earlier in an included file
#ifndef PICAMERA_H
#define PICAMERA_H

//include openCV files
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>


#include <iostream>
#include <thread>

//defines several error codes that are used by the errCode 
enum Err_type{
    NO_ERROR,
    ERR_INIT,
    ERR_EMPTY_FRAME
};

class Camera
{
private:
    struct{
        int camIdx; 
        int camApi;
        bool isOn = false;
    } CamSettings;             // CamSettings is a structure containing camera settings such as the camera index, camera API, and whether the camera is on.

    int errCode;               //errCode is an integer that holds the error code of the camera, which is used for error handling. 
    cv::Mat currentFrame;      // currentFrame is a cv::Mat object that holds the current frame captured by the camera. 
    cv::VideoCapture activeCapture;    //activeCapture is a cv::VideoCapture object that manages the camera capture process.
    std::thread camThread;      //camThread is a std::thread object that handles the camera capture process in a separate thread.
    void camThreadLoop();       

public:
    Camera(int camIdx = 0, int camApi = cv::CAP_ANY);  //Constructor, initializes the camera settings and opens the camera capture
    ~Camera();                                         //Destructure releases the camera capture and stops the camera thread.
    //virtual void hasFrame(cv::Mat frame) = 0;
    void display(); // displays the current frame on the screen.
    void startRecording(); //starts the camera capture thread.
    void stopRecording(); //stops the camera capture thread
    int getErr();         // returns the error code of the camera.     
    
};




#endif /* PICAMERA_H */
