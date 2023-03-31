#include "Timer.h"
#include <stdio.h>
#include "iostream"


int Timer::GetProgress(std::string result, std::string task){
    if(task == result){
        count++;
    }
    
    return count;
}

void Timer::ResetProgress(){
    count = 0;
}



