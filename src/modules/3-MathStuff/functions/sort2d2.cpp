#include <config.h>

void sortRow2D(int row, int valArr[diffPHVals][MaxKeySize], int occArr[diffPHVals][MaxKeySize]) {
  for (int i = 0; i < MaxKeySize - 1; i++) {
    for (int j = 0; j < MaxKeySize - i - 1; j++) {
      
      int currentVal = valArr[row][j];
      int nextVal    = valArr[row][j + 1];

      if (nextVal != 0 && (currentVal == 0 || currentVal > nextVal)) {
        
        int tempVal = valArr[row][j];
        valArr[row][j] = valArr[row][j + 1];
        valArr[row][j + 1] = tempVal;

        byte tempOcc = occArr[row][j];
        occArr[row][j] = occArr[row][j + 1];
        occArr[row][j + 1] = tempOcc;
      }
    }
  }
}