#include <Arduino.h>
#include <functions.h>

void pHSetter(unsigned long now, String phase, float currentPH, unsigned long &setterTimer, int setterCD, bool &readyForPump, unsigned long &pumpDesRuntime, unsigned long pHSetterArr[]){
  if(phase == "Lowering"){
    if(now - setterTimer >= setterCD){
      setterTimer = now;
      readyForPump = true;
          if(7.4 >= currentPH && currentPH >= 7.0){pumpDesRuntime=pHSetterArr[0]*1000;}
      else if(7.0 > currentPH && currentPH >= 6.5){pumpDesRuntime=pHSetterArr[0]*1000;}
      else if(6.5 > currentPH && currentPH >= 6.0){pumpDesRuntime=pHSetterArr[1]*1000;}
      else if(6.0 > currentPH && currentPH >= 5.8){pumpDesRuntime=pHSetterArr[2]*1000;}
      else if(5.8 > currentPH && currentPH >= 5.6){pumpDesRuntime=pHSetterArr[3]*1000;}
      else if(5.6 > currentPH && currentPH >= 5.5){pumpDesRuntime=pHSetterArr[4]*1000;}
    }
  }
} 