#include <Arduino.h>
#include <functions.h>

void pumper(unsigned long now, bool readyForPump, bool &pumpRunning, unsigned long pumperTimer, unsigned long pumpDesRunTime){
  if(readyForPump == true && pumpRunning == false){
    startPump(now, pumperTimer, pumpRunning);
    readyForPump = false;
  }
  else if(now - pumperTimer >= pumpDesRunTime){
    stopPump(pumpRunning);
  }
}
void startPump(unsigned long now, unsigned long &pumperTime, bool &pumpRunning){
    pumperTime = now;
    pumpRunning = true;
    digitalWrite(7, LOW);   // Relay ON
}
void stopPump(bool &pumpRunning){
    digitalWrite(7, HIGH); // Relay OFF
    pumpRunning = false;
}