#include <config.h>

void calibrator2(unsigned long now) {
  diffADCVals = 0;
  currentPH = phValues[pHValuesIndex];
  analDicoArrIndex = 0;

  int usedSpace = 0;
  getADCSamples(calibValueArr, calibOccurArr, 100, usedSpace);

  sortData(calibValueArr, calibOccurArr, 100);
  trimMeanArray[trimMeanArrayIndex] = trimmedMean(analDiCoArr, analDiCoArrSize, trimPercADCCalib);
  trimMeanArrayIndex++;
  if (trimMeanArrayIndex == trimMeanArrSize || enoughSamples == true) {
    enoughSamples = true;
    stdDevOfTrim = StdDev(trimMeanArray, trimMeanArrSize);
    trimOfTrim = trimmedMean(trimMeanArray, trimMeanArrSize, trimTrimPercADCCalib);
    mediOfTrim = getMedianValue(trimMeanArray, trimMeanArrSize);
    if (trimMeanArrayIndex == trimMeanArrSize) {
      trimMeanArrayIndex = 0;
    }
    int holder[diffADCVals];
    float holder2[diffADCVals];
    clusterer(clusteredSamplesArray, diffADCVals, mediOfTrim, holder);
    for (int i = 0; i < diffADCVals; i++) {
      if (holder[i] != 0) {
        medianOfTrimCluster = clusteredSamplesArray[i];
      }
      holder[i] = 0;
    }

    calibClusterer(clusteredSamplesArray, diffADCVals, trimOfTrim, holder);
    for (int i = 0; i < diffADCVals; i++) {
      if (holder2[i] != 0) {
        trimOfTrimCluster = clusteredSamplesArray[i];
      }
      holder[i] = 0;
    }
  }
}