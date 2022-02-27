#include <LiquidCrystal.h>
const int led = 40;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(led, OUTPUT);
  // Print a message to the LCD.
  lcd.print("HI Teri!");
}

void loop() {
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("ON");
  digitalWrite(led, HIGH);
  delay(2000);
  lcd.clear();
  lcd.print("OFF");
  digitalWrite(led, LOW);
  delay(2000);
  lcd.clear();
}
