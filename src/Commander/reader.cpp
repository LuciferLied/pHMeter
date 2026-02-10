#include <Arduino.h>

void reader(unsigned long now, String &incCommand){
  if(Serial.available() != 0){
    incCommand = Serial.readString();
    incCommand.trim();
  }
}