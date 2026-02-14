#include <config.h>

void syncShiftArrays(int values[], int counts[], int size) {
    int writeIndex = 0;

    for (int readIndex = 0; readIndex < size; readIndex++) {
        // We assume a '0' in the values array is an empty slot
        if (values[readIndex] != 0) {
            // Move the value and its corresponding count
            values[writeIndex] = values[readIndex];
            counts[writeIndex] = counts[readIndex];
            writeIndex++;
        }
    }

    // Fill the remaining tail of both arrays with 0
    while (writeIndex < size) {
        values[writeIndex] = 0;
        counts[writeIndex] = 0;
        writeIndex++;
    }
}