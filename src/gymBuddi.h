#ifndef GYMBUDDI_H
#define GYMBUDDI_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "iostream"
#include "gymBuddi.h"

#define MODEL_PATH "models/pose-mobilenetv2.pb"
#define NR_TASKS 5
namespace {

    class gymBuddi {
    public:
        
        static std::vector <std::string> results;
        
      
        static void welcomeMessage() {
            printf(" gymBuddi");
        }
      
        static std::string getLetterFromDigit(int digit) {
            return results[digit % results.size()];
        }
       
        static std::string makeTask() {
            int task_int = rand() % NR_TASKS;
            return getLetterFromDigit(task_int);
        }
      
        static void randSeed(){
            srand((unsigned) time(NULL));
        }
      
        static std::string getModelPath() {
            return MODEL_PATH;
        }
    };
   
    std::vector <std::string> gymBuddi::results = {"Downdog", "Goddess", "Plank", "Tree", "Warrior2"};
}

#endif
