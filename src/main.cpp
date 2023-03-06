#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>  
#include <iostream>

#include "picamera.h"

using namespace cv;
using std::cout; using std::cerr;

int main(int, char**)
{
    Camera camera_pi;

    camera_pi.startRecording();
    camera_pi.stopRecording();

    return 0;
}
