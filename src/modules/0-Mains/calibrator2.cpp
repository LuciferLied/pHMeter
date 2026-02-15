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
  largeWindow = 100;
  medWindow = highestOcc*0.5;
  smallWindow =  - highestOcc*0.75;
}