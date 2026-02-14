#include <math.h>

float StdDev(int arr[], int size) {
  if (size <= 0) return 0.0;
  float sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  float mean = sum / size;
  float squareSum = 0;
  for (int i = 0; i < size; i++) {
    squareSum += pow(arr[i] - mean, 2);
  }
  float variance = squareSum / (size - 1);
  return sqrt(variance);
}