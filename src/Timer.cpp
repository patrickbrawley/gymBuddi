#include "Timer.h"
#include <stdio.h>
#include "iostream"


int Timer::Gainz(std::string result, std::string task){
    // if user is in the correct pose with good form the counter will count up. 
    if(task == result){
        count++;
    }
    //The count variable times of the user performing an excersise, and is returned as the output of the function.
    return count;
}

void Timer::NewGainz(){
    //this method resets the timer to zero. allows a new excerise to be performed or the user needs to start over.
    count = 0;
}



