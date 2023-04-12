#include "SchedulableLink.h"
#include "BlockingQueue.cpp"


void SchedulableLink::Run(){
  // Loop until Stop() is called
  
    while(isOn){
      // Wait for the next scene to be added to the queue
        Scene s = scheduleQueue.Pop(); 
      // Process the scene and get the output
        Scene out = ProcessScene(s);
       // Pass the output to the next pipeline element (if any)
        if(!sceneCallback) continue;
        sceneCallback->NextScene(out);
    }
}

void SchedulableLink::Enqueue(Scene s) {
  // Add a new scene to the queue
    scheduleQueue.Push(s);
}

bool SchedulableLink::Available() {
   // Check if the queue is empty
    return scheduleQueue.IsEmpty(); 


void SchedulableLink::Start() {
   // Start a new thread to run the scheduling loop
    scheduleWorker = std::thread(&SchedulableLink::Run, this);
}

void SchedulableLink::Stop(){
   // Stop the scheduling loop by setting isOn to false and wait for the thread to finish
    isOn = false;
    scheduleWorker.join();
}

void SchedulableLink::NextScene(Scene scene) {
  //adds a Scene to the scheduleQueue only if it is empty. This ensures that scenes are not lost if they arrive while another scene is being processed.
   
    if(scheduleQueue.IsEmpty()) { 
        scheduleQueue.Push(scene);
    }
}
