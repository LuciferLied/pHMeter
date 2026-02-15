#include <config.h>

void syncShiftArrays(int values[], int occurrences[], int size) {
  highestOcc = 0;
  int tempMax = 0; // Local tracker to find the new highest

  // If shifting left (removing the oldest element at index 0):
  for (int i = 0; i < size - 1; i++) {
    values[i] = values[i + 1];
    occurrences[i] = occurrences[i + 1];

    // Check if this moved value is the new highest
    if (occurrences[i] > tempMax) {
      tempMax = occurrences[i];
    }
  }

  // Clear the last slot for new data
  values[size - 1] = 0;
  occurrences[size - 1] = 0;

  // Update the global variable
  highestOcc = tempMax;
}

void setWindows() {
  largeWindow = highestOcc * largeWindowMult;
  mediumWindow = highestOcc * mediumWindowMult;
  smallWindow = highestOcc * smallWindowMult;
}

void countSamples() {
  for (int i = 0; i < calibValArrSize; i++) {
    if (calibValueArr[i] != 0 && calibOccurArr[i] != 0) {
      ammSamplesCollected += calibOccurArr[i];
    }
  }
}

void findKey() {
  keyStart = 0;
  keyEnd = 0;
  for (int i = 0; i < calibValArrSize; i++) {
    if (MAXADC > calibValueArr[i] && calibValueArr[i] > MINADC) {
      if (calibValueArr[i] >= smallWindow) {
        keyStart = i;
        for (int k = i; k < calibValArrSize; k++) {
          if (calibValueArr[i] < smallWindow) {
            break;
          }
        }
        keyEnd = i;
        break;
      }
    }
  }
}