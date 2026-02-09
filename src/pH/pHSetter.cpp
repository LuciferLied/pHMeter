#include <Arduino.h>

void pHSetter(unsigned long now, String phase, float currentPH, unsigned long &setterTime, int setterCD, bool &readyForPump, unsigned long pumpDesRuntime, unsigned long pHSetterArr[]){
  if(phase == "Lowering"){
    if(now - setterTime >= setterCD){
      setterTime = now;
      readyForPump = true;
      if(7.0 >= currentPH && currentPH >= 6.5){pumpDesRuntime=pHSetterArr[0]*500;}
      if(6.5 > currentPH && currentPH >= 6.0){pumpDesRuntime=pHSetterArr[1]*500;}
      if(6.0 > currentPH && currentPH >= 5.8){pumpDesRuntime=pHSetterArr[2]*500;}
      if(5.8 > currentPH && currentPH >= 5.6){pumpDesRuntime=pHSetterArr[3]*500;}
      if(5.6 > currentPH && currentPH >= 5.5){pumpDesRuntime=pHSetterArr[4]*500;}
    }
  }
}