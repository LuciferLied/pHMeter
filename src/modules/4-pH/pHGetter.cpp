#include <config.h>
void pHGetter(unsigned long now, int clusteredAmmLimit, int diffPHVals, float phValues[],
              int clusteredArray[], float &currentPH, int &highest) {
  if (now < 1000)
    return;
  int threshold = clusteredAmmLimit / 6;
  if (threshold < 1)
    threshold = 1;
  int bestIndex = -1;
  int bestCount = threshold;
  for (int i = 0; i < diffPHVals; i++) {
    int c = clusteredArray[i];
    if (c > bestCount) {
      bestCount = c;
      bestIndex = i;
    }
  }
  if (bestIndex >= 0) {
    currentPH = phValues[bestIndex];
    highest = clusteredArray[bestIndex];
    if (now - lastRollPHTime >= rollPHCD) {
      rollingPHArr[rollingPHArrIndex] = currentPH;
      rollingPHArrIndex++;
      if (rollingPHArrIndex == rollingArrSize) {
        rollingPHReady = true;
        rollingPHArrIndex = 0;
      }
      if (rollingPHReady == true) {
        rollingPH = trimmedMean(rollingPHArr, rollingArrSize, rollTrimPerc);
      }
    }
  }
}
