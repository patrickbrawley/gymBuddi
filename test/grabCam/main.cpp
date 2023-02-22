// Include Libraries
#include <opencv2/opencv.hpp>
#include <iostream>
 
// Namespace to nullify use of cv::function(); syntax
using namespace std;
using namespace cv;

int main()

{
  // initialize a video capture object
  VideoCapture vid_capture(0);
 
  // Print error message if the stream is invalid
  if (!vid_capture.isOpened())
  {
    cout << "Error opening video stream or file" << endl;
  }
 
  else
  {
    // Obtain fps and frame count by get() method and print
    // You can replace 5 with CAP_PROP_FPS as well, they are enumerations
    int fps = vid_capture.get(5);
    cout << "Frames per second :" << fps;
 
    // Obtain frame_count using opencv built in frame count reading method
    // You can replace 7 with CAP_PROP_FRAME_COUNT as well, they are enumerations
    int frame_count = vid_capture.get(7);
    cout << "  Frame count :" << frame_count;
  }
  // Read the frames to the last frame
  while (vid_capture.isOpened())
  {
    // Initialise frame matrix
    Mat frame;
 
      // Initialize a boolean to check if frames are there or not
    bool isSuccess = vid_capture.read(frame);
 
    // If frames are present, show it
    if(isSuccess == true)
    {
      //display frames
      imshow("Frame", frame);
    }
 
    // If frames are not there, close it
    if (isSuccess == false)
    {
      cout << "Video camera is disconnected" << endl;
      break;
    }
     
    //wait 20 ms between successive frames and break the loop if key q is pressed
    int key = waitKey(20);
    if (key == 'q')
    {
      cout << "q key is pressed by the user. Stopping the video" << endl;
      break;
    }
 
 
  }
  // Release the video capture object
  vid_capture.release();
  destroyAllWindows();
  return 0;
}
