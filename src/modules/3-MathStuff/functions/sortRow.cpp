#include <config.h>

void sortRow(int rowNumber, int array2D[diffPHVals][MaxKeySize]) {
  // Use MaxKeySize instead of the hard-coded 10
  for (int i = 0; i < MaxKeySize - 1; i++) {
    for (int j = 0; j < MaxKeySize - i - 1; j++) {
      
      if (array2D[rowNumber][j] > array2D[rowNumber][j + 1]) {
        int temp = array2D[rowNumber][j];
        array2D[rowNumber][j] = array2D[rowNumber][j + 1];
        array2D[rowNumber][j + 1] = temp;
      }
    }
  }
}