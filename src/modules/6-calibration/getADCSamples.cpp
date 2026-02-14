#include <config.h>

void getADCSamples(int values[], int occurrences[], int size, int &usedSpace) {
  int sampleBatches = 36;
  int sammpleIndex = 0;
  for (int i = 0; i < size; i++) {
    values[i] = 0;
    occurrences[i] = 0;
  }

  for (int i = 0; i < sampleBatches; i++) {
    analDicoArrIndex = 0;
    while (analDicoArrIndex < analDiCoArrSize) {
      analDiCoArr[analDicoArrIndex] = sensor();
      analDicoArrIndex++;
    }
    for (int i = 0; i < analDiCoArrSize; i++) {
      if (sammpleIndex == size) {
        break;
      }
      bool exists = false;
      for (int k = 0; k < sammpleIndex; k++) {
        if (analDiCoArr[i] == values[k]) {
          occurrences[k]++;
          k = size;
          exists = true;
          break;
        }
      }
      if (exists == false) {
        values[sammpleIndex] = analDiCoArr[i];
        occurrences[diffADCVals] = 1;
        sammpleIndex++;
      }
    }
  }
  usedSpace = sammpleIndex;
  return;
}