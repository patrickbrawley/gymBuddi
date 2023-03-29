#ifndef SCENE_H
#define SCENE_H


#include <opencv2/core.hpp>


struct Point
{
    int x, y;
    Point() : x(0), y(0) {}
    Point(const Point& cpy) : x(cpy.x), y(cpy.y) {}
    Point(int x, int y) : x(x), y(y) {}
};


struct BoundingBox{
    Point UpperLeft; // The upper-left corner of the bounding box
    Point LowerRight;  // The lower-right corner of the bounding box
    // Default constructor initializes both points to (0, 0)
    BoundingBox():UpperLeft(), LowerRight(){}
    BoundingBox(int upperLeftX, int upperLeftY, int lowerRightX, int lowerRightY): UpperLeft(upperLeftX, upperLeftY),
                                                                                   LowerRight(lowerRightX, lowerRightY) {}
    BoundingBox(Point upperLeft, Point lowerRight): UpperLeft(upperLeft), LowerRight(lowerRight) {}
};

//Holds the data obtained in a single video frame to allow it to be processed and passed down the pipleline
struct Scene{
    Scene(){}
    
    //OpenCV n-dimensional dense array object representing the video frame

    cv::Mat frame;
  
    // A string representing the predicted output from processing with a CNN model, such as "plank"
    std::string result = "";
    
   //the area of the scene that will be processed.
     BoundingBox regionOfInterest; 
};

#endif
