const int line0 = 9;
const int line1 = A3;

const int a0 = 12;
const int a1 = 13;

void setup() {
  pinMode(line0, INPUT);
  pinMode(line1, INPUT);

  pinMode(a0, OUTPUT);
  pinMode(a1, OUTPUT);
  
  digitalWrite(a0, LOW);
  digitalWrite(a1, LOW);

  Serial.begin(115200);
  Serial.println("Start");
}

void set_dig(unsigned int v) {
  digitalWrite(a0, v & 0x02);
  digitalWrite(a1, v & 0x01);
}

const int del = 20;

uint8_t pressed_btn_mask = 0;
const int line_pin[2] = {line0, line1};

void read_btn(uint8_t row, int col) {
  uint8_t mask = 1 << (row + col*4);
  int pin = line_pin[col];

  if (digitalRead(pin)) {
    pressed_btn_mask &= 0xFF ^ mask; // reset/release current btn
    return;
  }

  delay(5);
  if (digitalRead(pin))
    return;

  if (!(pressed_btn_mask & mask)) {
    pressed_btn_mask |= mask;
    Serial.print("btn: ");
    Serial.print(row);
    Serial.print(" x ");
    Serial.print(col);
    Serial.println(" pressed");
  }
}

void loop() {
  for (int row = 0; row < 4; row++) {
    set_dig(row);
    read_btn(row, 0);
    read_btn(row, 1);
    delay(del);
  }
}
