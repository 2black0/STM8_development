#include <Arduino.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
// The instance name "lcd" is *within* the brackets
LiquidCrystal (lcd,PA1,PA2, PA3,PD2,PD3,PD4);

void setup() {
  lcd_begin(16, 2);
  lcd_print_s("hello, world!");
}


void loop() {
  lcd_setCursor(0, 1);
  lcd_print_u(millis() / 1000);
}
