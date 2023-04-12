#include <stdio.h>
#include "gymBuddi.h"

#define MOBNET_V2_INPUT_DIM_X 224
#define MOBNET_V2_INPUT_DIM_Y 224
#define MOBNET_V2_PATH "models/pose-mobilenetv2.pb"


//default configurations for CNNProcessor settings. Provides default values for the CNNProcessor class's constructor parameters, so that the CNNProcessor object can be easily created with default configurations.

struct CNNProcessorSettings {
    CNNProcessorSettings(std::string network = "mobnetv2"){
        if(network == "mobnetv2") {
            ModelPath = MOBNET_V2_PATH;
            InputDim_x = MOBNET_V2_INPUT_DIM_X;
            InputDim_y = MOBNET_V2_INPUT_DIM_Y;
        }
        else{
            ; //space for more default network setups
        }
    } 
    
    
            
    //copy constructor used to create a new scene as a copy of an existing object to allow the scene to be passed down the pipeline and later be processed by the Neural Network
    
    CNNProcessorSettings(const CNNProcessorSettings& cpy){
        ModelPath = cpy.ModelPath;
        InputDim_x = cpy.InputDim_x;
        InputDim_y = cpy.InputDim_y;
    }
    std::string ModelPath = "";
    int InputDim_x = 0;
    int InputDim_y = 0;
};
