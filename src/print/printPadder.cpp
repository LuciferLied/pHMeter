#include <Arduino.h>

// Version for Integers (ADC values, Occurrences)
void printPadded(int value, int width) {
  Serial.print(value);
  int digits = (value <= 0) ? 1 : 0;
  int temp = value;
  while (temp != 0) { temp /= 10; digits++; }
  
  for (int s = 0; s < (width - digits); s++) Serial.print(" ");
}

// Helper function for 2-decimal alignment
void printFixedFloat(float value, int precision, int width) {
    // 1. Print the number
    Serial.print(value, precision);

    // 2. Calculate length: 
    // (Digits before decimal) + (1 for decimal point) + (2 for decimals)
    int length = 0;
    if (value < 0) length++;      // Minus sign
    if (abs(value) < 10) length += 1;
    else if (abs(value) < 100) length += 2;
    else length += 3;             // Supports up to 999.99
    
    length = length + 1 + precision; 

    // 3. Fill the remaining "white space"
    for (int s = 0; s < (width - length); s++) {
        Serial.print(" ");
    }
}

void printPaddedText(const char* text, int width) {
  Serial.print(text);
  int len = strlen(text);
  for (int s = 0; s < (width - len); s++) Serial.print(" ");
}