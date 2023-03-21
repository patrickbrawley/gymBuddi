#include "SchedulableLink.h"
#include "BlockingQueue.cpp"


void SchedulableLink::Run(){
  
    while(isOn){
        Scene s = scheduleQueue.Pop(); 
        Scene out = ProcessScene(s);
        if(!sceneCallback) continue;
        sceneCallback->NextScene(out);
    }
}

void SchedulableLink::Enqueue(Scene s) {
    scheduleQueue.Push(s);
}

bool SchedulableLink::Available() {
    return scheduleQueue.IsEmpty(); //singly threaded for now
}


void SchedulableLink::Start() {
    scheduleWorker = std::thread(&SchedulableLink::Run, this);
}

void SchedulableLink::Stop(){
    isOn = false;
    scheduleWorker.join();
}

void SchedulableLink::NextScene(Scene scene) {
   
    if(scheduleQueue.IsEmpty()) { 
        scheduleQueue.Push(scene);
    }
}
