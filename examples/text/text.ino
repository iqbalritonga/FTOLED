#include <OLED128.h>
#include <fonts/SystemFont5x7.h>
#include <fonts/Arial14.h>
#include <fonts/Arial_black_16.h>

const byte pin_cs = 2;
const byte pin_dc = 3;
const byte pin_reset = 6;

OLED oled(pin_cs, pin_dc, pin_reset, false);

const char *ARIAL_BLACK_16 = "Arial Black 16";
const char *ARIAL_14 = "Arial 14";
const char *SYSTEM_5_7 = "System 5x7";

void setup() {
  Serial.begin(115200);
  Serial.print("init...");
  oled.initialiseDisplay();

  oled.selectFont(Arial_14);
  oled.drawString(32,32,ARIAL_14,strlen(ARIAL_14),VIOLET,BLACK);

  oled.selectFont(Arial_Black_16);
  oled.drawString(32,64,ARIAL_BLACK_16,strlen(ARIAL_BLACK_16),WHITE,BLACK);

  oled.selectFont(System5x7);
  oled.drawString(32,96,SYSTEM_5_7,strlen(SYSTEM_5_7),RED,BLACK);
}

void loop() {
  return;
  for(int i = 0; i < 128; i++) {
    oled.drawString(i,i,"Hello World",strlen("Hello World"),WHITE,BLACK);
    oled.drawLine(i,i,i+80,i,BLACK);
  }
}
