#ifndef POSECOMPARISON_H_
#define POSECOMPARISON_H_

/* for general */
#include <string>
#include <vector>
#include <array>
#include <iostream>


namespace cv 
{
    class Mat;
};
//This header file is written with the intention to analyse images from pictures and the camera live stream. 
// mat is  a key component of the OpenCV library and represents a matrix (i.e., a two-dimensional array) that can be used to store and manipulate images

class ImageProcessor_Initialize
{   
public:

typedef struct InputParam 
{
    char work_dir[256];
    std::int32_t  num_threads;
} InputParam;

    static int32_t Initialize(const InputParam& input_param);
};

class ImageProcessor_Process // from the camera live stream the angles between the users landmarks
{   
private:
double angle_camera[8]; 
int Learner[12][2];

public:
    static int angle_check[8];
    int32_t Process(cv::Mat& mat);
};


//takes no arguments and returns an integer value.
class ImageProcessor_Finalize
{
public:
    static int32_t Finalize(void);
};


// takes an integer argument and returns an integer value.
class ImageProcessor_Command
{
public:
    static int32_t Command(int32_t cmd);
};


#endif //end of the header file and ensures that the code is not compiled more than once.
