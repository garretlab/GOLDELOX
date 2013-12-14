#include "GOLDELOX.h"
#define NUM 20
#define DISPLAY_XWIDTH 128
#define DISPLAY_YWIDTH 128
#define COLOR_MAG 5000
#define XMIN (-2.3)
#define XMAX ( 0.7)
#define YMIN (-1.5)
#define YMAX ( 1.5)
#define STEP 0.01

GOLDELOX oled(&Serial);
int color = 0;

void setup() {
  // put your setup code here, to run once:
  int color;
  
  Serial.begin(9600);
  oled.begin();
  oled.screenSaverTimeout(0);   // Disable Screen Saver
  oled.clearScreen();           // Clear Screen
  
  for (double x = XMIN; x <= XMAX; x+= STEP) {
    for (double y = YMIN; y <= YMAX; y += STEP) {
      color = mandelbrot(x, y);     
      plot(x, y, color);
    }
  }
}

int mandelbrot(double a, double b) {
  double xn = a, yn = b;
  double xn1, yn1;
  
  for (int i = 0; i < NUM; i++) {
    xn1 = xn * xn - yn * yn + a;
    yn1 = 2.0 * xn * yn + b;
    if (xn1 * xn1 + yn1 * yn1 > 4.0) {
      return i;
    }
    xn = xn1;
    yn = yn1;
  }
  return 0;
}

void plot(double x, double y, int color) {
  double xmag = DISPLAY_XWIDTH / (XMAX - XMIN);
  double ymag = DISPLAY_XWIDTH / (YMAX - YMIN);
  double cmag = COLOR_MAG;
  
  oled.putPixel((uint16_t)((x - XMIN) * xmag),
                (uint16_t)((-y - YMIN) * ymag),
                (uint16_t)(color * cmag));
}

void loop() {
}
