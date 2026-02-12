#include <config.h>

void phaseHandler(unsigned long now){
    if(now - phaseTimer >= phaseCD){ 
        if(currentPH >= MAX_DESIRED_PH){
            phase = "Lowering";
        }
        else if(currentPH <= MIN_DESIRED_PH){
            phase = "Watching";
            //pumpDesRuntime = 0;
        }
    }
}