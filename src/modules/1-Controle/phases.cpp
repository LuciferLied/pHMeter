#include <config.h>

void phaseHandler(unsigned long now){
    if(now - lastPhaseCheckTime >= phaseCheckCD){ 
        if(currentPH >= MAX_DESIRED_PH){
            phase = "Lowering";
        }
        else if(currentPH <= MIN_DESIRED_PH){
            phase = "Watching";
            //pumpDesRuntime = 0;
        }
    }
}