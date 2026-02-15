#include <math.h>
#include <functions.h>

float calculateStdDev(int values[], int occurrences[], int size) {
  double totalCount = 0; // Use double for counts to keep math consistent
  for (int i = 0; i < size; i++) {
    totalCount += occurrences[i];
  }

  // Standard deviation requires at least two data points
  if (totalCount < 2) return 0.0; 

  float mean = calculateWeightedMean(values, occurrences, size);
  double sumSquaredDiffs = 0;

  for (int i = 0; i < size; i++) {
    if (occurrences[i] > 0) {
      // Use double for the difference to ensure the square doesn't overflow
      double diff = (double)values[i] - (double)mean;
      sumSquaredDiffs += (double)occurrences[i] * (diff * diff);
    }
  }

  double variance = sumSquaredDiffs / totalCount;
  return (float)sqrt(variance);
}