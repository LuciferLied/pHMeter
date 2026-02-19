#include <config.h>

void printResults() {
  Serial.println("// --- START GENERATED CODE ---");

  for (int i = 0; i < diffPHVals; i++) {
    // Pull actual float from your array
    float phLabel = phValues[i];
    
    // Extract parts for naming (e.g., 5.4 -> whole 5, decimal 4)
    int whole = (int)phLabel;
    int decimal = (int)((phLabel - (float)whole) * 10.0f + 0.5f);

    // --- 1. ADC Keys ---
    Serial.print("inline int PH_VAL_");
    Serial.print(whole); Serial.print("_"); Serial.print(decimal);
    Serial.print("["); Serial.print(MaxKeySize); Serial.print("] = {");
    
    for (int j = 0; j < MaxKeySize; j++) {
      Serial.print(calibKeyBundle[i][j]);
      if (j < MaxKeySize - 1) Serial.print(",");
    }
    Serial.println("};");

    // --- 2. HI/LO Percentages ---
    Serial.print("inline float PH_PERC_");
    Serial.print(whole); Serial.print("_"); Serial.print(decimal);
    Serial.print("["); Serial.print(MaxKeySize); Serial.print("][2] = {");
    
    for (int j = 0; j < MaxKeySize; j++) {
      Serial.print("{");
      Serial.print(calibKeyBundlePerc[i][j][0], 2); // HI%
      Serial.print(",");
      Serial.print(calibKeyBundlePerc[i][j][1], 2); // LO%
      Serial.print("}");
      if (j < MaxKeySize - 1) Serial.print(",");
    }
    Serial.println("};");
    
    Serial.println(); 
  }
  Serial.println("// --- END GENERATED CODE ---");
}