#include <config.h>

void trimMeanGetter(unsigned long now) {
  trimMeanArrayIndex = 0;
  while (trimMeanArrayIndex < trimMeanArrSize) {
    analDicoArrIndex = 0;
    while (analDicoArrIndex < analDiCoArrSize) {
      analDiCoArr[analDicoArrIndex] = sensor();
      analDicoArrIndex++;
    }
    trimMeanArray[trimMeanArrayIndex] = trimmedMean(analDiCoArr, analDiCoArrSize, trimPercADC);
    trimMeanArrayIndex++;
  }
  trimMeanArrSTD = StdDev(trimMeanArray, trimMeanArrSize);
  if (trimMeanArrSTD <= stdLim) {
    trimMeanMedianArray[trimMeanMedianArrayIndex] = getMedianValue(trimMeanArray, trimMeanArrSize);
    trimMeanMedianArrayIndex++;
    if (trimMeanMedianArrayIndex == trimMeanMedianArrSize) {
      trimMeanMedianArrayIndex = 0;
    }
    return;
  } else if (trimMeanArrSTD > stdLim) {
    trimMeanGetter(now);
    return;
  }
}