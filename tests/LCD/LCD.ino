
#include <LiquidCrystal.h>

const int E = 2;
const int RS = 7;

const int D4 = 8;
const int D5 = 9;
const int D6 = 10;
const int D7 = 11;

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);

  delay(100);
  lcd.clear();
  lcd.print("Hello");
  lcd.setCursor(0, 1);
  lcd.write("world!");
}

void loop() {
  if (Serial.available()) {
    delay(100);
    lcd.clear();
    while (Serial.available() > 0) {
      lcd.write(Serial.read());
    }
  }
}
