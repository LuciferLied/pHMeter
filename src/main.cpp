#include <config.h>
#include <vector>

void setup(){
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  Serial.begin(9600);
}
void loop(){
  unsigned long now = millis();
  reader(now, incCommand);
  commander(now, incCommand);
  if(now - loopTimer >= loopCD){
    if(mode == "doser"){
      doser(now);}
    else if(mode == "calibrater"){
      calibrater(now);}
  } 
}