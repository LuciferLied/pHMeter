#include <math.h>
#include <functions.h>

// --- Standard Deviation (Zero-Safe) ---
float calculateStdDev(int values[], int occurrences[], int size) {
  long totalCount = 0;
  for (int i = 0; i < size; i++) {
    totalCount += occurrences[i]; 
  }

  if (totalCount < 2) return 0.0; 

  float mean = calculateWeightedMean(values, occurrences, size);
  double sumSquaredDiffs = 0;

  for (int i = 0; i < size; i++) {
    if (occurrences[i] > 0) { // Skip empty slots
      float diff = (float)values[i] - mean;
      sumSquaredDiffs += (double)occurrences[i] * (diff * diff);
    }
  }

  return sqrt(sumSquaredDiffs / totalCount);
}