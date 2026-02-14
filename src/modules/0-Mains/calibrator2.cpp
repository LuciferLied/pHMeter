#include <config.h>

void calibrator2(unsigned long now) {
  diffADCVals = 0;
  currentPH = phValues[pHValuesIndex];
  analDicoArrIndex = 0;
  usedSize = 0;
  getADCSamples(calibValueArr, calibOccurArr, 100, usedSize);

  sortData(calibValueArr, calibOccurArr, 100);
}