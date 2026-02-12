#include <config.h>

void setup(){
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  Serial.begin(9600);
}

void loop(){
  unsigned long now = millis();
  phaseHandler(now);
  pumper(now, readyForPump, pumpRunning, pumperTimer, pumpDesRuntime);
  reader(now, incCommand);
  if(incCommand != ""){
    commander(now, incCommand);}
  if(now - loopTimer >= loopCD){
    if(mode == "Doser"){
      doser2(now);}
    else if(mode == "Calibrator"){
      calibrater(now);}
  }
  incCommand = "";
}