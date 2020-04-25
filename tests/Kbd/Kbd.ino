
const int D0 = 4;
const int D1 = 5;
const int D2 = 6;
const int D3 = 7;

const int Line0 = A2;
const int Line1 = A1;
const int Line2 = A0;

void setup() {
  Serial.begin(115200);

  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);

  digitalWrite(D0, HIGH);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
}

void loop() {
  int d[4] = {D0, D1, D2, D3};
  for (int i = 0; i < 4; i++) {
    digitalWrite(d[i], LOW);
    delay(10);

    if (digitalRead(Line0) == LOW) {
      Serial.print("btn: ");
      Serial.println(i);
    }

    if (digitalRead(Line1) == LOW) {
      Serial.print("btn: ");
      Serial.println(4 + i);
    }

    if (digitalRead(Line2) == LOW) {
      Serial.print("btn: ");
      Serial.println(8 + i);
    }

    digitalWrite(d[i], HIGH);
  }
}
