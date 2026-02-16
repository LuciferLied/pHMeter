#include <config.h>

void syncShiftArrays(int values[], int occurrences[], int size) {
  highestOcc = 0;
  int tempMax = 0;

  for (int i = 0; i < size - 1; i++) {
    values[i] = values[i + 1];
    occurrences[i] = occurrences[i + 1];

    if (occurrences[i] > tempMax) {
      tempMax = occurrences[i];
    }
  }
  values[size - 1] = 0;
  occurrences[size - 1] = 0;

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
  int i = 0;
  for (i; i < calibValArrSize; i++) {
    if (calibOccurArr[i] >= smallWindow) {
      if (keyStart == 0) {
        keyStart = i;
      }
      if (keyStart != 0) {
        keyEnd = i;
      }
    }
  }
}

void largestKey(){
    currLargestKey = 0;
    for (int i = 0; i < diffPHVals; i++)
    {
        int counter = 0;
        for (int k = 0; k < maxKeys; k++)
        {
            if(calibKeyBook[i][k] != 0){
                counter++;
            } else break;            
        }
        if(counter > currLargestKey)
            currLargestKey = counter;
    }
    
}
