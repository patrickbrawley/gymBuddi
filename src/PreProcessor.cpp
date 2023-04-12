#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

#include "PreProcessor.h"
//This code defines the implementation of the PreProcessor class, which is responsible for preprocessing input scenes in a computer vision pipeline.
//This method handles processing the given scene and calls back to the next pipeline element. 


void PreProcessor::NextScene(Scene scene){
   // Compute the bounding box coordinates for the region of interest based on the input image size and the relative bounding box settings 
   cv::Size sz = scene.frame.size();
   scene.regionOfInterest = BoundingBox((int)(sz.width * settings.relativeBoundingBox[0]),
                                        (int)(sz.height * settings.relativeBoundingBox[1]),
                                        (int)(sz.width * settings.relativeBoundingBox[2]),
                                        (int)(sz.height * settings.relativeBoundingBox[3]));
   
   // Switch the pixel format of the image to BGR to allow OpenCV to use the scene.
   Scene out = switchRGB2BGR(scene);
   // Add a green rectangle to the image at the location of the region of interest
   out = drawBox(scene);
   // Call the next pipeline element with the processed scene
    if(!sceneCallback) return;
   sceneCallback->NextScene(out);
}

//Constructor that takes in PreProcessorSettings to initialize the PreProcessor object.

PreProcessor::PreProcessor(PreProcessorSettings s) : settings(s) {}

//Default constructor that initializes the PreProcessor object with default settings.
PreProcessor::PreProcessor() : settings() {}

//switches the pixel format of the internal frame from RGB to BGR using OpenCV functions.
//returns the scene with the pixel format rearranged
Scene PreProcessor::switchRGB2BGR(Scene s) {
    cv::Mat temp = s.frame;
    cv::cvtColor(temp, s.frame, cv::COLOR_BGR2RGB);
    return s;
}


//Adds a green rectangle to the internal scene frame, highlighting the region of interest for best use of the neural network.
//return the processed scene
Scene PreProcessor::drawBox(Scene s) {
    cv::Mat temp = s.frame;
    int x  = s.regionOfInterest.UpperLeft.x; int y = s.regionOfInterest.UpperLeft.y;
    int width = s.regionOfInterest.LowerRight.x - x;
    int height = s.regionOfInterest.LowerRight.y - y;
   // Add a green rectangle to the image at the location of the region of interest
    cv::Rect rect(x, y, width, height);
    cv::rectangle(temp, rect, cv::Scalar(0,255,0));
    Scene ret = s;
    s.frame = temp;
    return s;
}


//This method is used to set the bounding box each scene is marked with. 
//The bounding box is specified as float values in the range [0-1], indicating fractional coordinates in the image frame.
void PreProcessor::SetBoundingBox(float upperLeftX, float upperLeftY, float lowerRightX, float lowerRightY) {
    settings.relativeBoundingBox[0] = upperLeftX;
    settings.relativeBoundingBox[1] = upperLeftY;
    settings.relativeBoundingBox[2] = lowerRightX;
    settings.relativeBoundingBox[3] = lowerRightY;
    for(int i = 0; i < 4; i++){
        float val = settings.relativeBoundingBox[i];
        if(val > 1.0f){
            settings.relativeBoundingBox[i] = 1.0f;
        }
        else if (val < 0.0f){
            settings.relativeBoundingBox[i] = 0.0f;
        }
    }
}
