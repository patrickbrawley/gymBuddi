//include header files
#include <vector>
#include <array>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <memory>
#include <unistd.h>
#include <iostream>


#include <opencv2/opencv.hpp>

#include "tensorflow_set.h"
#include "pose_comparison.h"
#include "exercise_image.h"


// Define an array to hold angle check results for each image
double angle_image[8]={0,0,0,0,0,0,0,0}; // // angle check for image pose


//Define a unique pointer to hold the PoseEngine object
std::unique_ptr<PoseEngine> s_engine;   

// Define a static array to hold angle check results for the image processor
int ImageProcessor_Process::angle_check[8];

// initializes the processor with the specified input parameters
int32_t ImageProcessor_Initialize::Initialize(const ImageProcessor_Initialize::InputParam& input_param)
{
  
  // Create a new PoseEngine object and initialize it
    s_engine.reset(new PoseEngine());
    if (s_engine->Initialize(input_param.work_dir, input_param.num_threads) != PoseEngine::kRetOk) 
    {
        s_engine->Finalize();
        s_engine.reset();
        return -1;
    }
    return 0;
}


//finalizes the processor and releases any resources it has acquired.
int32_t ImageProcessor_Finalize::Finalize()
{
  // Check if the PoseEngine object has been initialized
    if (!s_engine) 
    {
        
        std::cout<<"Initialisation has Failed\n"<<std::endl; //if s_engine has not been initialized this error message will be printed.
        return -1;
    }
    // Finalize the PoseEngine object
    if (s_engine->Finalize() != PoseEngine::kRetOk) 
    {
        return -1;
    }

    return 0;
}


int32_t ImageProcessor_Command::Command(int32_t cmd)
{
    if (!s_engine) 
    {
      // Check if the PoseEngine object has been initialized
        std::cout<<"Not initialized\n"<<std::endl; // Output an error message
        return -1;
    }
 // Output an error message for unsupported commands
    switch (cmd) 
    {
    case 0:
    default:
        std::cout<<"command "<<cmd<<" is not supported\n"<<std::endl; // Output an error message
        return -1;
    }
}

// Define a list of joint lines for drawing the pose keypoints
static const std::vector<std::pair<int32_t, int32_t>> kJointLineList {
    // face 
    {0, 2},
    {2, 4},
    {0, 1},
    {1, 3},
    // body 
    {6, 5},
    {5, 11},
    {11, 12},
    {12, 6},
    // arm 
    {6, 8},
    {8, 10},
    {5, 7},
    {7, 9},
    // leg 
    {12, 14},
    {14, 16},
    {11, 13},
    {13, 15},
};

static constexpr float kThresholdScoreKeyPoint = 0.2f; // threshold for detecting key points in the image. Key points with a score below this threshold are not displayed.

int32_t ImageProcessor_Process::Process(cv::Mat& mat) // details of analyzing the image pose processes
{
    if (!s_engine)
    {
       // Check if the PoseEngine object has been initialized
        std::cout<<"Not initialized\n"<<std::endl;
        return -1;
    }
    
    PoseEngine::Result pose_result;
    if (s_engine->Process(mat, pose_result) != PoseEngine::kRetOk) 
    {
        return -1;
    }

    // Display target area 
    cv::rectangle(mat, cv::Rect(pose_result.crop.x, pose_result.crop.y, pose_result.crop.w, pose_result.crop.h), cv::Scalar(0, 0, 0), 2);

    // Display detection result and keypoint 
    for (size_t i = 0; i < 1; i++) 
    {

        // Display joint lines 
        const auto& keypoint = pose_result.keypoint_list[i];
        const auto& keypoint_score = pose_result.keypoint_score_list[i];

        /* Angle calculation */
        for (int k = 0; k < 12; k++)
        {
            Learner[k][0]=keypoint[k+5].first;
            Learner[k][1]=keypoint[k+5].second;
        }
        
        double* prt=new double[8]; // define dynamic pointer

        for(int k =0; k<2; k++)
        {
            *(prt+k)=Learner[k][0];
            *(prt+k+2)=Learner[k+4][0];
            *(prt+k+4)=Learner[k][1];
            *(prt+k+6)=Learner[k+4][1];
        }

        for(int k=0;k<2;k++)
        {
            Learner[k][0]=*(prt+k+2);
            Learner[k+4][0]=*(prt+k);
            Learner[k][1]=*(prt+k+6);
            Learner[k+4][1]=*(prt+k+4);
        }
        
        // Calculating the pose angles from images and users then comparing them to see if users form is correct.
         //If the user pose is correct, then the joint lines will show in green, else the joint lines will show in red.
        

        for (int k = 0; k < 8; k++)
        {
            double line1=sqrt((Learner[k][0]-Learner[k+2][0])*(Learner[k][0]-Learner[k+2][0])+(Learner[k][1]-Learner[k+2][1])*(Learner[k][1]-Learner[k+2][1]));
            double line2=sqrt((Learner[k+2][0]-Learner[k+4][0])*(Learner[k+2][0]-Learner[k+4][0])+(Learner[k+2][1]-Learner[k+4][1])*(Learner[k+2][1]-Learner[k+4][1]));
            double line3=sqrt((Learner[k][0]-Learner[k+4][0])*(Learner[k][0]-Learner[k+4][0])+(Learner[k][1]-Learner[k+4][1])*(Learner[k][1]-Learner[k+4][1]));
            *(prt+k)=acos((line1*line1+line2*line2-line3*line3)/(2*line1*line2))*180.0/3.14;
            if (camera_show::Thread_num==1)
            {
                angle_camera[k]=*(prt+k);
            }
            else if (camera_show::Thread_num==2)
            {
                angle_image[k]=*(prt+k);  
            }
        }
       
      
        for (int n = 0; n < 8; n++)
        {   
            // the tolarant of the users' poses is plus and minus 20 degree
            if ((angle_camera[n]<(angle_image[n]-20)) || (angle_camera[n]>(angle_image[n]+20)))
            {
                angle_check[n]=n+1;
            }
            else{
                angle_check[n] = 0;
            }   
        }

        for (const auto& jointLine : kJointLineList) 
        {
            if (keypoint_score[jointLine.first] >= kThresholdScoreKeyPoint && keypoint_score[jointLine.second] >= kThresholdScoreKeyPoint) {
                int32_t x0 = keypoint[jointLine.first].first;
                int32_t y0 = keypoint[jointLine.first].second;
                int32_t x1 = keypoint[jointLine.second].first;
                int32_t y1 = keypoint[jointLine.second].second;
                cv::line(mat, cv::Point(x0, y0), cv::Point(x1, y1), cv::Scalar(0, 255, 0), 6);
            }
            
            //mark wrong joint lines
            if (camera_show::Thread_num==1)
            {
                for (int k = 0; k <8; k++)
                {
                    if(angle_check[k]!=0)
                    {
                    cv::line(mat, cv::Point(Learner[k+2][0], Learner[k+2][1]), cv::Point(Learner[k][0], Learner[k][1]), cv::Scalar(0, 0, 255), 6);
                    cv::line(mat, cv::Point(Learner[k+2][0], Learner[k+2][1]), cv::Point(Learner[k+4][0], Learner[k+4][1]), cv::Scalar(0, 0, 255), 6);
                    }
                }
            }
            
            
        }

        // Display joints
        for (size_t j = 0; j < keypoint.size(); j++) {
            if (keypoint_score[j] >= kThresholdScoreKeyPoint) {
                const auto& p = keypoint[j];
                cv::circle(mat, cv::Point(p.first, p.second), 5, cv::Scalar(0, 255, 0),2);
            }
            //mark wrong joints
            if (camera_show::Thread_num==1)
            {
                for(int k=0; k<8; k++)
                {
                    if(angle_check[k] !=0)
                    {
                    cv::circle(mat, cv::Point(Learner[k+2][0], Learner[k+2][1]), 5, cv::Scalar(0, 0, 255),2);
                    }
                }
            }
            
            
        }
        delete []prt; // delete the pointer to release the memory
    }
    
    return 0;
}
