#ifndef CNNPROCESSOR_H
#define CNNPROCESSOR_H

#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <stdio.h>
#include <chrono>
#include <thread>

#include "SchedulableLink.h"
#include "gymBuddi.h"
#include "CNNProcessorSettings.h"



//CNNProcessor Class
//used to process the scenes using a neural network TF model within the scenes pipleline.
class CNNProcessor : public SchedulableLink{
public:
    Scene ProcessScene(Scene s); //Takes a Scene as an input and returns a new Scene object that has been processed by the CNN model.
    CNNProcessor(CNNProcessorSettings s); 
    cv::Mat MakeBlob(Scene scene); //Takes a Scene object as input and returns a cv::Mat object that is used as input to the CNN model.
    
protected:
    CNNProcessorSettings settings; //used to configure the CNN model.
    void LoadModel(std::string modelPath);
    cv::dnn::Net net;
};

#endif
