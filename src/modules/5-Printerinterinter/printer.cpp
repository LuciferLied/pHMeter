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
      linePrinter(now, 601);
      linePrinter(now, 603);
      if(sampleKey == true){
        linePrinter(now, 605);
        linePrinter(now, 604);
      }
      if(showKeyDetails == true){
        linePrinter(now, 606);
      }
      if(showPHKey == true){
        linePrinter(now, 608);
      }
      linePrinter(now, 607);

    }
    linePrinter(now, 999);
    printIteration++;
    //print = false; /////////////// FJERN
  }
};