#include <Arduino.h>
#pragma once

int sensor(int analPin,int minADC, int maxADC);
int getMedianValue(int array[], int size);
void clusterer(int arr[], int size, int sample, int outputArray[]);
void decay(unsigned long now, int array[], int size, float decay, unsigned long &decayTimer, unsigned long decayCD);


void pHandler(unsigned long now, int currentPH, int MIN_DESIRED_PH, int MAX_DESIRED_PH, String &phase);

void pHGetter(unsigned long now, int clusteredAmmLimit, int diffPHVals, float phValues[], int clusteredArray[], float &currentPH, int &highest);
void pHSetter(unsigned long now, String phase, float currentPH, unsigned long &setterTime, int setterCD, bool &readyForPump, unsigned long pumpDesRuntime, unsigned long pHSetterArr[]);
void pumper(unsigned long now, bool readyForPump, bool &pumpRunning, unsigned long pumperTime, unsigned long pumpDesRunTime);
void startPump(unsigned long now, unsigned long &pumperTime, bool &pumpRunning);
void stopPump(bool &pumpRunning);

void printer(unsigned long now, int &printIteration, float currentPH, String phase, int clusterCenters[], int clusteredArray[], float phValues[], int diffPHVals, unsigned long &printerTimer, unsigned long printerCD);
void linePrinter(int line, int printIteration, float currentPH, int diffPHVals, int clusteredArray[], float phValues[], int clusterCenters[]);
