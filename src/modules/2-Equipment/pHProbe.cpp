#include <config.h>

int sensor() {
  int sensVal = 0;
  sensVal = analogRead(ANALPIN);
  if (MAXADC < sensVal || sensVal < MINADC) {
    sensVal = sensor();
  }
  return sensVal;
}