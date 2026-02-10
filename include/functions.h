#include <Arduino.h>
#include <vector>
#pragma once


void reader(unsigned long now, String &incCommand);
void commander(unsigned long now, String &incCommand);
void resetter();

void doser(unsigned long now);
void calibrater(unsigned long now);


int sensor(int analPin,int minADC, int maxADC);
int getMedianValue(int array[], int size);
void clusterer(int arr[], int size, int sample, int outputArray[]);
void decay(unsigned long now, int array[], int compArray[], int size, float decay, unsigned long &decayTimer, unsigned long decayCD, unsigned long &compTimer, unsigned long compCD);
void calibDecay(unsigned long now, int adcVals[], int ADCOccurrences[], int medMedvals[], int medMedOcc[], int medMedOccComp[], int medMedCompVals[], int size, unsigned long &decayTimer, unsigned long decayCD, unsigned long compTimer);
float trimmedMean(int *values, int n, float trimFraction);


void pHandler(unsigned long now, int currentPH, int MIN_DESIRED_PH, int MAX_DESIRED_PH, String &phase);
void pHGetter(unsigned long now, int clusteredAmmLimit, int diffPHVals, float phValues[], int clusteredArray[], float &currentPH, int &highest);
void pHSetter(unsigned long now, String phase, float currentPH, unsigned long &setterTime, int setterCD, bool &readyForPump, unsigned long pumpDesRuntime, unsigned long pHSetterArr[]);
void pumper(unsigned long now, bool readyForPump, bool &pumpRunning, unsigned long pumperTime, unsigned long pumpDesRunTime);
void startPump(unsigned long now, unsigned long &pumperTime, bool &pumpRunning);
void stopPump(bool &pumpRunning);

void printer(unsigned long now, String mode, unsigned long &printerTimer, unsigned long printerCD, int &printIteration);
void linePrinter(int line);
void printPadded(int value, int width);
void printFixedFloat(float value, int precision, int width);

void matrixPicker();

void calibrate();
bool stable();
float StdDev(int arr[], int size);
void sortData(int values[], int occurrences[], int size);
void sortAndPadData(int values[], int occurrences[], int size);
void resetter();
