#include <config.h>

void calibrator2(unsigned long now) {
  currentPH = phValues[pHValuesIndex];
  usedSize = 0;
  getADCSamples(calibValueArr, calibOccurArr, 100, usedSize);
  sortData(calibValueArr, calibOccurArr, 100);
  syncShiftArrays(calibValueArr, calibOccurArr, 100);
  calculateStdDev(calibValueArr, calibOccurArr, 100);
  CalibOccMedi = calculateMedian(calibValueArr, calibOccurArr, 100);
  CalibOccTrim = calculateTrimmedMean(calibValueArr, calibOccurArr, 100, 0.25);
  largeWindow = highestOcc*0.05;
  medWindow = highestOcc*0.36;
  smallWindow = highestOcc*0.60;
}