#include <config.h>

void reader(unsigned long now) {
  if (Serial.available() != 0) {
    incCommand = Serial.readString();
    incCommand.trim();
  }
}