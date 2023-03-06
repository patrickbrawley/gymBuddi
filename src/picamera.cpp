//The camera.h file is a header file that contains the declarations for the Camera class.

#include "picamera.h"


//This is the constructor for the Camera class. It takes two arguments: camIdx and camApi. These arguments specify the camera index and backend API to be used, respectively.
Camera::Camera(int camIdx, int camApi)
{
    
    //These lines set the values of the CamSettings member variable of the Camera class to the values passed in as arguments to the constructor.
    CamSettings.camIdx = camIdx;
    CamSettings.camApi = camApi;

   //This line creates a cv::VideoCapture object called capture that is used to capture frames from the camera. The arguments camIdx and camApi are used to specify the camera index and backend API to be used.
    cv::VideoCapture capture(camIdx, camApi);
    if (!capture.isOpened()) //This block of code checks whether the capture object was successfully opened. If the capture object is not opened, the errCode member variable of the Camera class is set to ERR_INIT and an error message is printed to the console.
    {
        errCode = ERR_INIT;
        std::cerr << "ERROR "<< errCode <<": Can't initialize camera capture" << std::endl;
    }
    activeCapture = capture; //This line sets the activeCapture member variable of the Camera class to the capture object created earlier.

    
    
    
    //These lines print the frame width, frame height, and capturing frames per second (FPS) to the console.
    std::cout << "Frame width: " << capture.get(cv::CAP_PROP_FRAME_WIDTH) << std::endl;
    std::cout << "     height: " << capture.get(cv::CAP_PROP_FRAME_HEIGHT) << std::endl;
    std::cout << "Capturing FPS: " << capture.get(cv::CAP_PROP_FPS) << std::endl;
}

//This is a member function of the Camera class that displays the current frame in a window called "Frame".
void Camera::display(){
    cv::imshow("Frame", currentFrame);
}

 

//This is the main loop of the Camera class. It runs in a separate thread and captures frames from the camera as long as the isOn member variable of the CamSettings member variable is true. The read() function of the activeCapture member variable is used to read the current frame, which is stored in the currentFrame member variable. If the currentFrame is empty, an error message is printed to the console and the loop exits. Otherwise, the display() member function is called to display the current frame in a window. The loop waits for a key press, and if the key is the "ESC" key, the loop exits.
void Camera::camThreadLoop(){
    while(CamSettings.isOn){
        activeCapture.read(currentFrame);

        if (currentFrame.empty()) {
            errCode = ERR_EMPTY_FRAME;
            std::cerr << "ERROR: "<< ERR_EMPTY_FRAME << " blank frame grabbed\n";
            return;
        }

        //  function is called to display the current frame on the "Frame" window. 
        //A keyboard listener is also set up to detect if the "ESC" key is pressed, in which case the loop is terminated.
        display();
        int key = cv::waitKey(1);
        if (key == 27/*ESC*/){break;}
    }
}


//startRecording(), stopRecording(), and getErr() functions are utility methods that respectively start the camera thread, 
//stop the camera thread, and return the error code that is set when an error occurs during camera initialization or frame capture.

void Camera::startRecording(){
    CamSettings.isOn = true;
    if(!activeCapture.open(CamSettings.camIdx, CamSettings.camApi)){
        errCode = ERR_INIT;
        std::cerr << "ERROR "<< errCode <<": Can't initialize camera capture" << std::endl;
    }
    
   //This function is executed on a separate thread when the startRecording() method is called. 
    //It runs continuously until CamSettings.isOn is set to false. Within this loop, it reads frames from the camera using the activeCapture.read() function.
    //If the captured frame is empty, an error is thrown and the loop is terminated.
  
    camThread = std::thread(&Camera::camThreadLoop, this);
    
}

void Camera::stopRecording(){
    // CamSettings.isOn = false;
    camThread.join();
}

int Camera::getErr(){
    return errCode;
}

Camera::~Camera()
{
    CamSettings.isOn = false;
    activeCapture.release();
}
