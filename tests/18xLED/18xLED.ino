
void setup() {
  for (int i = 2; i <= 13; i++)
    pinMode(i, OUTPUT);
  for (int i = A0; i <= A5; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  for (int i = 2; i <= 13; i++) {
    digitalWrite(i, HIGH);
    delay(300);
    digitalWrite(i, LOW);
  }
  for (int i = A0; i <= A5; i++) {
    digitalWrite(i, HIGH);
    delay(300);
    digitalWrite(i, LOW);
  }

  PORTB = 0xFF;
  delay(1000);
  PORTB = 0;

  PORTC = 0xFF;
  delay(1000);
  PORTC = 0;

  PORTD = 0xFF;
  delay(1000);
  PORTD = 0;
}
