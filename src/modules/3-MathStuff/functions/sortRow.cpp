#include <config.h>

void sortRow(int rowNumber, int array2D[diffPHVals][maxKeys]) {
  // We loop through the 10 elements
  for (int i = 0; i < 10 - 1; i++) {
    for (int j = 0; j < 10 - i - 1; j++) {
      
      // If the current element is bigger than the next, swap them
      if (array2D[rowNumber][j] > array2D[rowNumber][j + 1]) {
        int temp = array2D[rowNumber][j];
        array2D[rowNumber][j] = array2D[rowNumber][j + 1];
        array2D[rowNumber][j + 1] = temp;
      }
    }
  }
}