#include <math.h>

void clusterer(int arr[], int size, int sample, int outputArray[]){
    int low = 0, high = size - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < sample)
            low = mid + 1;
        else
            high = mid;
    }
    int inds[3];
    int vals[3];
    int n = 0;
    if (low > 0) {
        inds[n] = low - 1;
        vals[n++] = abs(arr[low - 1] - sample);
    }
    inds[n] = low;
    vals[n++] = abs(arr[low] - sample);
    if (low < size - 1) {
        inds[n] = low + 1;
        vals[n++] = abs(arr[low + 1] - sample);
    }
    int minDist = vals[0];
    for (int i = 1; i < n; i++)
        if (vals[i] < minDist)
            minDist = vals[i];
    for (int i = 0; i < n; i++){
        if (vals[i] == minDist){
        outputArray[inds[i]]++;
        }
    } 
}