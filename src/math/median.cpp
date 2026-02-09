int getMedianValue(int array[], int size){
  if (size <= 0) return 0;
  if (size == 1) return array[0];
  for (int i = 0; i < size - 1; i++){
    for (int j = 0; j < size - i - 1; j++){
      if (array[j] > array[j + 1]){
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
  if (size % 2 != 0){
    return array[size / 2];
  } 
  else{
    return (array[(size / 2) - 1] + array[size / 2]) / 2;
  }
}