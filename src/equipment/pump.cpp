#include <Arduino.h>
#include <functions.h>

void pumper(unsigned long now, bool readyForPump, bool &pumpRunning, unsigned long &pumperTimer, unsigned long pumpDesRunTime){
  if(readyForPump == true && pumpRunning == false){
    readyForPump = false;
    pumpRunning = true;
    startPump(now, pumperTimer, pumpRunning);
  }
  else if(now - pumperTimer >= pumpDesRunTime){
    stopPump(pumpRunning);
  }
}
void startPump(unsigned long now, unsigned long &pumperTimer, bool &pumpRunning){
    pumperTimer = now;
    digitalWrite(7, LOW);   // Relay ON
}
void stopPump(bool &pumpRunning){
    digitalWrite(7, HIGH); // Relay OFF
    pumpRunning = false;
}


void pump(unsigned now, int time){
    digitalWrite(7, LOW);   // Relay ON
    delay(time);
    digitalWrite(7, HIGH); // Relay OFF

}