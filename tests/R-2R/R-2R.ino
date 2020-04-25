
const int Latch = 3;
const int D0 = 4;
const int D1 = 5;
const int D2 = 6;
const int D3 = 7;
const int D4 = 8;
const int D5 = 9;
const int D6 = 10;
const int D7 = 11;

void setup() {
  pinMode(Latch, OUTPUT);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
}

void write_val(uint8_t val) {
  uint8_t p = PORTD;
  p &= 0x0F;
  p |= ((val & 0x0F) << 4);
  PORTD = p;

  p = PORTB;
  p &= 0xF0;
  p |= (val >> 4);
  PORTB = p;

  bitSet(PORTD, PORTD3);
  delay(5);
  bitClear(PORTD, PORTD3);
}

void loop() {
  for (int i = 0; i < 256; i++) {
    write_val(i);
    delay(50);
  }
  delay(200);
}
