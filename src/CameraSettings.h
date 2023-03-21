#ifndef SIGNAPSE_CAMERASETTINGS_H
#define SIGNAPSE_CAMERASETTINGS_H



struct CameraSettings{
    CameraSettings(int dID=0){
        deviceID = dID;
    }
    CameraSettings(const CameraSettings& cpy){
        deviceID = cpy.deviceID;
        apiID = cpy.apiID;
    }
   
    int deviceID = 0;
   
    int apiID = 0;
};

#endif 
