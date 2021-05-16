#include "Adafruit_ThinkInk.h"
#include <SPI.h>

#define SD_CS       5
#define SRAM_CS     -1
#define EPD_CS      9
#define EPD_DC      10
#define EPD_RESET   -1
#define EPD_BUSY    -1

ThinkInk_290_Grayscale4_T5 display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);

#define COLOR1 EPD_BLACK
#define COLOR2 EPD_LIGHT
#define COLOR3 EPD_DARK

void setup() {
  // put your setup code here, to run once:
  displayText("ceci est un test*test*test2 -3-4*test3");
}

void loop() {
 
}
