void sortData(int values[], int occurrences[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int minIdx = i; // Initialize minIdx to the current position
    
    for (int j = i + 1; j < size; j++) {
      if (values[j] < values[minIdx]) {
        minIdx = j; // Update minIdx if a smaller value is found
      }
    }

    // If minIdx changed, swap the values and their occurrences
    if (minIdx != i) {
      // Swap values
      int tempVal = values[i];
      values[i] = values[minIdx];
      values[minIdx] = tempVal;

      // Swap occurrences
      int tempOcc = occurrences[i];
      occurrences[i] = occurrences[minIdx];
      occurrences[minIdx] = tempOcc;
    }
  }
}