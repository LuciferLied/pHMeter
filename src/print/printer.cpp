#include <Arduino.h>
#include <functions.h>

void printer(unsigned long now, String mode, unsigned long &printerTimer, unsigned long printerCD, int &printIteration){
  if(now - printerTimer >= printerCD){
    printerTimer = now;
    if(mode == "doser"){
      linePrinter(0);
      linePrinter(1);
      linePrinter(2);
    }
    else if(mode == "calibrater"){
      linePrinter(0);
      linePrinter(600);
      linePrinter(601);
      linePrinter(602);
      linePrinter(603);
      linePrinter(999);

    }
    printIteration++;
  }
};