#include <config.h>
#include <functions.h>
#include <Timers&cds.h>
#include <data.h>

void setup(){
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  Serial.begin(9600);
}
void loop(){
  unsigned long now = millis();
  if(now - loopTimer >= loopCD){
    int anal5ArrSize = 360;
    int medianArrSize = 10;
    int anal5Array[anal5ArrSize];
    int medianArr[medianArrSize];
    int anal5Index = 0;
    int medianArrIndex = 0;
    while(medianArrIndex < medianArrSize){
      while(anal5Index < anal5ArrSize){
        anal5Array[anal5Index]=sensor(analPin, minADC, maxADC);
        anal5Index++;
      }
      medianArr[medianArrIndex] = getMedianValue(anal5Array, anal5ArrSize);
      medianArrIndex++;
    }
    medMedianArr[medMedianArrIndex] = getMedianValue(medianArr, medianArrSize);
    clusterer(clusterCenters, diffPHVals, medMedianArr[medMedianArrIndex], clusteredArray);
    medMedianArrIndex++; if(medMedianArrIndex == medMedianArrSize){medMedianArrIndex = 0;}
    pHGetter(now, clusteredAmmLimit, diffPHVals, phValues, clusteredArray, currentPH, highest);
    pHSetter(now, phase, currentPH, setterTimer, setterCD, readyForPump, pumpDesRuntime, pHSetterArr);
    printer(now, printIteration, currentPH, phase, clusterCenters, clusteredArray, phValues, diffPHVals, printerTimer,printerCD);
    decay(now, clusteredArray, diffPHVals, decayFactor, decayTimer, decayCD);
  }
}