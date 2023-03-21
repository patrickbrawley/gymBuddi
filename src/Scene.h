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
    Point UpperLeft;
    Point LowerRight;
    BoundingBox():UpperLeft(), LowerRight(){}
    BoundingBox(int upperLeftX, int upperLeftY, int lowerRightX, int lowerRightY): UpperLeft(upperLeftX, upperLeftY),
                                                                                   LowerRight(lowerRightX, lowerRightY) {}
    BoundingBox(Point upperLeft, Point lowerRight): UpperLeft(upperLeft), LowerRight(lowerRight) {}
};


struct Scene{
    Scene(){}
  
    cv::Mat frame;
  
    std::string result = "";
   
     BoundingBox regionOfInterest;
};

#endif
