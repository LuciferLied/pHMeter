#include <config.h>

void calibrator2(unsigned long now) {
  diffADCVals = 0;
  currentPH = phValues[pHValuesIndex];
  analDicoArrIndex = 0;
  usedSize = 0;
  getADCSamples(calibValueArr, calibOccurArr, 100, usedSize);
  sortData(calibValueArr, calibOccurArr, 100);
  syncShiftArrays(calibValueArr, calibOccurArr, 100);
  CalibOccMedi = calculateMedian(calibValueArr, calibOccurArr, 100);
  CalibOccTrim = calculateTrimmedMean(calibValueArr, calibOccurArr, 100, 0.25);
  // largeWindow = highestOcc*0.20;
  // medWindow = highestOcc*0.36;
  // smallWindow = highestOcc*0.60;
  largeWindow = 1;
  medWindow = 1;
  smallWindow = 1; 
  for (int i = 0; i < 100; i++)
  {
    if(calibOccurArr[i]> highestOcc*0.60){
    Serial.print(calibValueArr[i]);
    Serial.print(" - ");
    Serial.println(calibOccurArr[i]);
    }
  }
}