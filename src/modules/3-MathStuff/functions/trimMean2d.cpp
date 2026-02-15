
//(Zero-Safe)
float calculateTrimmedMean(int values[], int occurrences[], int size, float trimPercent) {
  long totalCount = 0;
  for (int i = 0; i < size; i++) totalCount += occurrences[i];

  if (totalCount == 0) return 0.0;

  long trimAmount = (long)(totalCount * (trimPercent / 100.0) / 2.0);
  double weightedSum = 0;
  long remainingCount = 0;
  long cumulativeProcessed = 0;

  for (int i = 0; i < size; i++) {
    if (occurrences[i] == 0) continue; // Skip empty slots

    for (int j = 0; j < occurrences[i]; j++) {
      cumulativeProcessed++;
      // Only count if within the non-trimmed range
      if (cumulativeProcessed > trimAmount && cumulativeProcessed <= (totalCount - trimAmount)) {
        weightedSum += values[i];
        remainingCount++;
      }
    }
  }

  return (remainingCount > 0) ? (float)(weightedSum / remainingCount) : 0;
}