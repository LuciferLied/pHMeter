float calculateTrimmedMean(int values[], int occurrences[], int size, float trimPercent) {
  long totalCount = 0;
  for (int i = 0; i < size; i++) totalCount += occurrences[i];

  // Calculate how many individual readings to skip from each end
  long trimAmount = (long)(totalCount * (trimPercent / 100.0) / 2.0);
  long remainingCount = 0;
  double weightedSum = 0;

  long processedSoFar = 0;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < occurrences[i]; j++) {
      processedSoFar++;
      // Only add to sum if we are past the lower trim and before the upper trim
      if (processedSoFar > trimAmount && processedSoFar <= (totalCount - trimAmount)) {
        weightedSum += values[i];
        remainingCount++;
      }
    }
  }

  return (remainingCount > 0) ? (float)(weightedSum / remainingCount) : 0;
}