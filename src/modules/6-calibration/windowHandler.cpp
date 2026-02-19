#include <config.h>

void windowSetting() {
  largeWindowMult = 0.10;
  mediumWindowMult = 0.36;
  smallWindowMult = 0.50;
  keyWindowMult = 0.60;
  largeWindow = 0;
  mediumWindow = 0;
  smallWindow = 0;
  keyWindow = 0;






  switch (currentWindow) {
  case 0: { // STD
    minSmpls = 1;
    largeWindowMult = 0.10;
    mediumWindowMult = 0.36;
    smallWindowMult = 0.50;
    largeWindow = 0;
    mediumWindow = 0;
    smallWindow = 0;
  } break;
  case 1: { // LARGE
    minSmpls = highestOcc * (largeWindowMult);
    DistToLock = 1;
  } break;
  case 2: { // MEDIUM
    minSmpls = highestOcc * (mediumWindowMult);
    largeWindowMult = (mediumWindowMult);
    DistToLock = 1;
  } break;
  case 3: { // SMALL
    minSmpls = highestOcc * (smallWindowMult);
    largeWindowMult = (smallWindowMult);
    mediumWindowMult = (smallWindowMult);
    DistToLock = 1;
  } break;
  case 4: { // KEY
    minSmpls = highestOcc * (keyWindowMult);
    largeWindowMult = (keyWindowMult);
    mediumWindowMult = (keyWindowMult);
    smallWindowMult = keyWindowMult;
    DistToLock = 1;
  } break;
  default: {
  } break;
  }
}