#include <config.h>

void executePreset(unsigned long now) {
  for (int i = 0; i < maxPreCMDSize; i++) {
    // Only process populated slots
    if (commandArray[i] != "") {
      incCommand = commandArray[i]; // Sync the global buffer
      commander(now);                  // Execute based on current incCommand
    }
  }
}

void clearCommandArray() {
  for (int i = 0; i < maxPreCMDSize; i++) {
    commandArray[i] = "";
  }
}