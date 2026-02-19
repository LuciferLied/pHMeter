#include <config.h>


int findBestOverallMatch(int* liveKeys, float* livePercs, int liveSize) {
    int bestPHIndex = -1;
    float lowestError = 1000000.0;

    for (int phIdx = 0; phIdx < diffPHVals; phIdx++) {
        float rowError = 0;
        bool liveKeyMatched[63] = {false};

        // 1. Process the Template (Calibration)
        for (int j = 0; j < MaxKeySize; j++) {
            int calibK = calibKeyBundle[phIdx][j];
            if (calibK == 0) continue;

            float minP = calibKeyBundlePerc[phIdx][j][0];
            float maxP = calibKeyBundlePerc[phIdx][j][1];
            float midP = (minP + maxP) / 2.0;

            bool found = false;
            for (int i = 0; i < liveSize; i++) {
                if (liveKeys[i] == calibK) {
                    float p = livePercs[i];
                    // If outside envelope, add the distance to error
                    if (p < minP)      rowError += (minP - p);
                    else if (p > maxP) rowError += (p - maxP);
                    
                    liveKeyMatched[i] = true;
                    found = true;
                    break;
                }
            }

            // If a calibrated key is missing from live data, 
            // the error is the expected percentage (it's a big mismatch).
            if (!found) {
                rowError += midP; 
            }
        }

        // 2. Process "Stranger" Keys (In live data but not in this calibration row)
        for (int i = 0; i < liveSize; i++) {
            if (liveKeys[i] != 0 && !liveKeyMatched[i]) {
                // If a live key isn't in the template, it's an error.
                // We add the percentage it represents because it doesn't belong here.
                rowError += livePercs[i];
            }
        }

        if (rowError < lowestError) {
            lowestError = rowError;
            bestPHIndex = phIdx;
        }
    }
    return bestPHIndex;
}