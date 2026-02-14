#include <config.h>

void calibrator(unsigned long now) {
  diffADCVals = 0;
  currentPH = phValues[pHValuesIndex];
  analDicoArrIndex = 0;
  while (analDicoArrIndex < analDiCoArrSize) {
    analDiCoArr[analDicoArrIndex] = sensor();
    analDicoArrIndex++;
  }
  stdDevOfADC = StdDev(analDiCoArr, analDiCoArrSize);
  for (int i = 0; i < analDiCoArrSize; i++) {
    if (diffADCVals == diffPHVals) {
      break;
    }
    bool exists = false;
    for (int k = 0; k < diffPHVals; k++) {
      if (analDiCoArr[i] == clusteredSamplesArray[k]) {
        clusteredSamplesCompArray[k]++;
        k = diffPHVals;
        exists = true;
        break;
      }
    }
    if (exists == false) {
      clusteredSamplesArray[diffADCVals] = analDiCoArr[i];
      clusteredSamplesCompArray[diffADCVals]=1;
      diffADCVals++;
    }
  }

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
    for (int i = 0; i < diffADCVals; i++)
    {
      if(holder[i] != 0){
        medianOfTrimCluster = clusteredSamplesArray[i];
      }
      holder[i] = 0;
    }
    
    calibClusterer(clusteredSamplesArray, diffADCVals, trimOfTrim, holder);
    for (int i = 0; i < diffADCVals; i++)
    {
      if(holder2[i] != 0){
        trimOfTrimCluster = clusteredSamplesArray[i];
      }
      holder[i] = 0;
    }
 

  }
}