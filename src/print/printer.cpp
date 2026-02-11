#include <Arduino.h>
#include <functions.h>

void printer(unsigned long now, String mode, unsigned long &printerTimer, unsigned long printerCD, int &printIteration){
  if(now - printerTimer >= printerCD){
    printerTimer = now;
    if(mode == "doser"){
      linePrinter(now, 0);
      linePrinter(now, 1);
      linePrinter(now, 2);
    }
    else if(mode == "calibrater"){
      linePrinter(now, 0);
      //linePrinter(600);
      //linePrinter(601);
      linePrinter(now, 602);
      linePrinter(now, 604);
      linePrinter(now, 603);
      linePrinter(now, 999);
    }
    printIteration++;
  }
};