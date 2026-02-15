// --- Weighted Mean (Zero-Safe) ---
float calculateWeightedMean(int values[], int occurrences[], int size) {
  long totalSum = 0;
  long totalOccurrences = 0;

  for (int i = 0; i < size; i++) {
    if (occurrences[i] > 0) { // Skip empty slots
      totalSum += (long)values[i] * occurrences[i];
      totalOccurrences += occurrences[i];
    }
  }

  if (totalOccurrences == 0) return 0.0;
  return (float)totalSum / totalOccurrences;
}