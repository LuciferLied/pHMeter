#include <Arduino.h>
#include <functions.h>

void printer(unsigned long now, int &printIteration, float currentPH, String phase, int clusterCenters[], int clusteredArray[], float phValues[], int diffPHVals, unsigned long &printerTimer, unsigned long printerCD){
  if(now - printerTimer >= printerCD){
    printerTimer = now;
    linePrinter(0, printIteration, currentPH, diffPHVals, clusteredArray, phValues, clusterCenters);
    linePrinter(1, printIteration, currentPH, diffPHVals, clusteredArray, phValues, clusterCenters);
    linePrinter(2, printIteration, currentPH, diffPHVals, clusteredArray, phValues, clusterCenters);
    printIteration++;
  }
};