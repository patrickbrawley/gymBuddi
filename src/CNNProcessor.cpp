#include "CNNProcessor.h"

// Load the trained TF model 
void CNNProcessor::LoadModel(std::string modelPath){
    net = cv::dnn::readNetFromTensorflow(modelPath);
}


// Constructor that loads the trained TF model
CNNProcessor::CNNProcessor(CNNProcessorSettings s) : settings(s) {
    LoadModel(settings.ModelPath);
}


// Implementation of the MakeBlob function that extracts a region of interest from a scene and converts it to a blob
cv::Mat CNNProcessor::MakeBlob(Scene scene){
    int x  = scene.regionOfInterest.UpperLeft.x; int y = scene.regionOfInterest.UpperLeft.y; 
    int width = scene.regionOfInterest.LowerRight.x - x; 
    int height = scene.regionOfInterest.LowerRight.y - y;
    cv::Mat roi = scene.frame(cv::Range(y, y+height), cv::Range(x, x+width));
    cv::Mat small;
    cv::resize(roi, small, cv::Size(settings.InputDim_x,settings.InputDim_y));
    cv::Mat blob;
    cv::dnn::blobFromImage(small, blob, (1.0 / 255.0));
    return blob;
}


// Implementation of the ProcessScene function that processes a scene using a trained CNN model
Scene CNNProcessor::ProcessScene(Scene scene){
    if(scene.frame.empty()) return scene; // If the scene is empty, return it without processing
    cv::Mat blob = MakeBlob(scene); // Convert the scene to a blob
    net.setInput(blob); // Set the input for the neural network
    cv::Mat prob = net.forward(); // Forward propagate the blob through the network
    cv::Point classIdPoint;
    double confidence;
    minMaxLoc(prob.reshape(1, 1), 0, &confidence, 0, &classIdPoint);  // Find the class with the highest probability
    int classId = classIdPoint.x; // Get the class ID
    scene.result = gymBuddi::getPoseFromDigit(classId); // Set the desired pose as the result the frame will be searching for.
    return scene; // Return the processed scene to pass along the pipeline
}
