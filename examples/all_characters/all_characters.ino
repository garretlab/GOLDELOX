#include "GOLDELOX.h"

GOLDELOX oled(&Serial);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  oled.begin();
  oled.screenSaverTimeout(0);
  oled.clearScreen();
  oled.textForegroundColor(0xffff);
  oled.textBackgroundColor(0x0000);
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      oled.moveCursor(j, i);
      oled.putCharacter((char)i * 16 + j);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly: 
  
}
