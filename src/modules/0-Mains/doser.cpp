#include <config.h>

void doser(unsigned long now) {
  trimMeanGetter(now);
  clusterer(clusterCenters, diffPHVals, trimMeanMedianArray[trimMeanMedianArrayIndex],
            clusteredSamplesArray);
  pHGetter(now, minConsSampleSize, diffPHVals, phValues, clusteredSamplesArray, currentPH, mostSampled);
  pHSetter(now, phase, rollingPH, lastSetterTime, setterCD, runPump, currentPumpTiming,
           pumpTimingOptionsArr);

  // pHSetter(now, phase, currentPH, lastSetterTime, setterCD, runPump, currentPumpTiming,
  // pumpTimingOptionsArr);
  return;
}