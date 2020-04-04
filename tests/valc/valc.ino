// Test code for rotary encoder shield aka valcoder

// hardware:
// 3 tactile button + rotary encoder button
// 74HC139 decoder

// connections:
// pin 12 == PB4 -> A decoder pin
// pin 13 == PB5 -> B decoder pin
// pin A2 == PC2 -> all tactile buttons + pullup
// pin A1 == PC1 -> rotary encoder pin A
// pin A0 == PC0 -> rotary encoder pin B

#include <TimerOne.h>

// Do not use "const byte" here, it's not work
#define ENC_PORT PINC
#define BTN_PORT PINC
#define BTN_BIT  2
#define DEC_PORT PORTB
#define DEC_BIT_A 4
#define DEC_BIT_B 5

// test rgb led pins:
const int pin_b = 3;
const int pin_g = 5;
const int pin_r = 6;

const int dec_a = 12;
const int dec_b = 13;

// returns change in encoder state (-1,0,1)
//
int8_t read_encoder() {
  static int8_t enc_states[] = {0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0};
  static uint8_t old_AB = 0;

  old_AB <<= 2;                   // remember previous state
  old_AB |= ( ENC_PORT & 0x03 );  // add current state
  return (enc_states[( old_AB & 0x0f )]);
}

void set_addr(int addr) {
  // PB4 == A decoder pin
  if (addr & 0x01)
    bitSet(DEC_PORT, DEC_BIT_A);
  else
    bitClear(DEC_PORT, DEC_BIT_A);

  // PB5 == B decoder pin
  if (addr & 0x02)
    bitSet(DEC_PORT, DEC_BIT_B);
  else
    bitClear(DEC_PORT, DEC_BIT_B);
}

int g_addr = 0;
int g_btns_mask = 0;
int g_prev_btns_mask = 0;

void on_tmr() {
  byte val = BTN_PORT;
  boolean vbl = val & _BV(BTN_BIT);
  if (vbl)
    g_btns_mask &= ~(1 << g_addr);
  else
    g_btns_mask |= 1 << g_addr;

  g_addr++;
  if (g_addr >= 4)
    g_addr = 0;
  set_addr(g_addr);
  // now we will wait 2ms :)
}

void setup() {
  // this breaks analogWrite() for digital pins 9 and 10 on Arduino:
  Timer1.initialize(2000); // in us
  Timer1.attachInterrupt(on_tmr);

  Serial.begin(115200);
  Serial.println("Start");
  pinMode(dec_a, OUTPUT);
  pinMode(dec_b, OUTPUT);

  pinMode(pin_r, OUTPUT);
  pinMode(pin_g, OUTPUT);
  pinMode(pin_b, OUTPUT);
  analogWrite(pin_r, 240);
  analogWrite(pin_g, 240);
  analogWrite(pin_b, 240);
}

void clip(int& v) {
  if (v < 0)
    v = 0;
  if (v > 255)
    v = 255;
}

void loop() {
  static int r = 0;
  static int g = 0;
  static int b = 0;

  if (Serial.available()) {
    int c = Serial.read();
    if (c == '0') {
      r = g = b = 0;
      analogWrite(pin_r, 255);
      analogWrite(pin_g, 255);
      analogWrite(pin_b, 255);
    }
    if (c == '1') {
      r = g = b = 255;
      analogWrite(pin_r, 0);
      analogWrite(pin_g, 0);
      analogWrite(pin_b, 0);
    }
    if (c == '2') {
      r = g = b = 55;
      analogWrite(pin_r, 200);
      analogWrite(pin_g, 200);
      analogWrite(pin_b, 200);
    }
  }

  int8_t tmp = read_encoder();
  if (tmp) {
    if (g_btns_mask & 0x08) {
      r += tmp*2;
      clip(r);
      analogWrite(pin_r, 255 - r);
      Serial.println(r);
    }
    if (g_btns_mask & 0x02) {
      g += tmp*2;
      clip(g);
      analogWrite(pin_g, 255 - g);
      Serial.println(g);
    }
    if (g_btns_mask & 0x04) {
      b += tmp*2;
      clip(b);
      analogWrite(pin_b, 255 - b);
      Serial.println(b);
    }
  }

  if (g_btns_mask != g_prev_btns_mask) {
    Serial.println(g_btns_mask);
    g_prev_btns_mask = g_btns_mask;
  }
}
