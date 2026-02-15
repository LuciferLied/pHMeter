#include <config.h>

void calibrator2(unsigned long now) {
  currentPH = phValues[pHValuesIndex];
  usedSize = 0;
  ammSamplesCollected = 0;
  getADCSamples(calibValueArr, calibOccurArr, 100, usedSize);
  sortData(calibValueArr, calibOccurArr, 100);
  syncShiftArrays(calibValueArr, calibOccurArr, 100);
  CalibOccSTDDev = (calibValueArr, calibOccurArr, 100);
  CalibOccMedi = calculateMedian(calibValueArr, calibOccurArr, 100);
  CalibOccTrim = calculateTrimmedMean(calibValueArr, calibOccurArr, 100, 0.25);
  setWindows();
}