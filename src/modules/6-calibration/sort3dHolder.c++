#include <config.h>

void sortKeyHolder() {
  for (int i = 0; i < 63 - 1; i++) {
    for (int j = 0; j < 63 - i - 1; j++) {
      
      int currentVal = calibSampleKeyHolder[0][j];
      int nextVal    = calibSampleKeyHolder[0][j + 1];

      // Standard sort: Move 0s to the end, sort ADC values ascending
      if (nextVal != 0 && (currentVal == 0 || currentVal > nextVal)) {
        
        // Loop through all 3 dimensions to swap the entire "vertical column"
        for (int dim = 0; dim < 3; dim++) {
          int temp = calibSampleKeyHolder[dim][j];
          calibSampleKeyHolder[dim][j] = calibSampleKeyHolder[dim][j + 1];
          calibSampleKeyHolder[dim][j + 1] = temp;
        }
      }
    }
  }
}