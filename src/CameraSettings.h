#ifndef CAMERASETTINGS_H
#define CAMERASETTINGS_H

// A struct that holds camera settings such as the device ID and API ID

struct CameraSettings{
    // Constructor that takes a device ID and initializes the settings with it
    CameraSettings(int dID=0){
        deviceID = dID;
    }
    // Copy constructor that initializes the settings with another CameraSettings object
    CameraSettings(const CameraSettings& cpy){
        deviceID = cpy.deviceID;
        apiID = cpy.apiID;
    }
   // The device ID used to access the camera
    int deviceID = 0;
   // The ID of the camera API used to access the camera
    int apiID = 0;
};

#endif 
