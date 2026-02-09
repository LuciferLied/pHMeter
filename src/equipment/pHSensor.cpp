#include <config.h>

int sensor(int analPin,int minADC, int maxADC){
  int sensVal = 0;
  sensVal = analogRead(analPin);
  if(sensVal < minADC || sensVal > maxADC){
    sensVal = sensor(analPin, minADC, maxADC);
  }
  return sensVal;
}