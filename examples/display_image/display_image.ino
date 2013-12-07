#include "GOLDELOX.h"

GOLDELOX oled(&Serial);

void setup() {
  // put your setup code here, to run once:
  uint16_t result;
  
  Serial.begin(9600);
  oled.begin();
  oled.screenSaverTimeout(0);   // Disable Screen Saver
  oled.clearScreen();           // Clear Screen
  
  oled.mediaInit(&result);      // Initialize Media
  
  if (result) {
    oled.setSectorAddress(0);   // Set Sector Address
    oled.displayImageRaw(0, 0); // Display Image
  }
}

void loop() {
  // put your main code here, to run repeatedly: 
}
