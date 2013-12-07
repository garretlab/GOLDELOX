#include "GOLDELOX.h"

GOLDELOX oled(&Serial);

char *string = "Hello World !!";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  oled.begin();
  oled.screenSaverTimeout(0);
  oled.clearScreen();
  
  oled.textForegroundColor(0xffff);
  oled.moveCursor(0, 0);
  oled.putString(string);
  
  oled.textForegroundColor(0xf800);
  oled.textBold(true);
  oled.moveCursor(0, 1);
  oled.putString(string);
  
  oled.textForegroundColor(0x07e0);
  oled.textItalic(true);
  oled.moveCursor(0, 2);
  oled.putString(string);
  
  oled.textForegroundColor(0x001f);
  oled.textUnderline(true);
  oled.moveCursor(0, 3);
  oled.putString(string);
  
  oled.textForegroundColor(0xffe0);
  oled.textItalic(true);
  oled.textBold(true);
  oled.moveCursor(0, 4);
  oled.putString(string);
  
  oled.textForegroundColor(0x0000);
  oled.textBackgroundColor(0xffff);
  oled.moveCursor(0, 5);
  oled.putString(string);
  
  oled.textForegroundColor(0xffff);
  oled.textBackgroundColor(0x0000);
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      oled.moveCursor(j, i + 6);
      oled.putCharacter((char)i * 16 + j);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly: 
  
}
