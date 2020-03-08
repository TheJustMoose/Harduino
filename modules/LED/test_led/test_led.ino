
const int line = 8;

const int a0 = 12;
const int a1 = 13;

const int d0 = 4;
const int d1 = 5;
const int d2 = 6;
const int d3 = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(line, INPUT);

  pinMode(d0, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);

  pinMode(a0, OUTPUT);
  pinMode(a1, OUTPUT);
  
  digitalWrite(d0, LOW);
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);

  digitalWrite(a0, LOW);
  digitalWrite(a1, LOW);

  Serial.begin(115200);
  Serial.println("Start");
}

void set_dig(unsigned int v) {
  digitalWrite(a0, v & 0x02);
  digitalWrite(a1, v & 0x01);
}

void set_num(unsigned int v) {
  digitalWrite(d0, v & 0x01);
  digitalWrite(d1, v & 0x02);
  digitalWrite(d2, v & 0x04);
  digitalWrite(d3, v & 0x08);
}

const int del = 2;

uint8_t pressed_btn_mask = 0;

void read_btn(uint8_t btn) {
  uint8_t mask = 1 << btn;
  if (digitalRead(line)) {
    pressed_btn_mask &= 0xFF ^ mask; // reset/release current btn
    return;
  }

  delay(5);
  if (digitalRead(line))
    return;

  if (!(pressed_btn_mask & mask)) {
    pressed_btn_mask |= mask;
    Serial.print("btn ");
    Serial.print(btn);
    Serial.println(" pressed");
  }
}

void loop() {
  set_dig(3);
  set_num(0);
  delay(del);

  set_dig(2);
  set_num(1);
  delay(del);

  set_dig(1);
  read_btn(1);
  set_num(2);
  delay(del);

  set_dig(0);
  read_btn(0);
  set_num(3);
  delay(del);
}
