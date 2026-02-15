float calculateMedian(int values[], int occurrences[], int size) {
  long totalCount = 0;
  for (int i = 0; i < size; i++) totalCount += occurrences[i];
  
  if (totalCount == 0) return 0;

  float middle = (totalCount + 1) / 2.0;
  long cumulativeCount = 0;

  for (int i = 0; i < size; i++) {
    cumulativeCount += occurrences[i];
    if (cumulativeCount >= middle) {
      return (float)values[i];
    }
  }
  return 0;
}