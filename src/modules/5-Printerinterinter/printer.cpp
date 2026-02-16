#include <config.h>

void printer(unsigned long now, String mode, unsigned long &printerTimer, unsigned long printerCD,
             int &printIteration) {
  if (now - printerTimer >= printerCD && print == true) {
    printerTimer = now;
    linePrinter(now, 0);
    if (mode == "Doser") {
      linePrinter(now, 1);
      linePrinter(now, 2);
    } else if (mode == "Calibrator") {
      //linePrinter(now, 600);
      linePrinter(now, 601);
      //linePrinter(now, 602);
      linePrinter(now, 603);
    }
    linePrinter(now, 999);
    printIteration++;
    //print = false; /////////////// FJERN
  }
};