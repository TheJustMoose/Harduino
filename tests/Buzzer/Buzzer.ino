
void setup() {
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
}

void loop() {
  digitalWrite(3, HIGH);
  delay(100);
  digitalWrite(3, LOW);
  delay(200);
  digitalWrite(3, HIGH);
  delay(100);
  digitalWrite(3, LOW);
  delay(2000);
}
