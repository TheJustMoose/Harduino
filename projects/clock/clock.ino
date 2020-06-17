#include <Wire.h>
#include "DS3231.h"

RTClib rtc;

const int line = 4;

const int dp = 2;

const int d0 = 8;
const int d1 = 9;
const int d2 = 10;
const int d3 = 11;

const int a0 = 13;  // yes! it's fail :(
const int a1 = 12;

const int del = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(line, INPUT);

  pinMode(dp, OUTPUT);

  pinMode(d0, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);

  pinMode(a0, OUTPUT);
  pinMode(a1, OUTPUT);
  
  digitalWrite(dp, LOW);

  digitalWrite(d0, LOW);
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);

  digitalWrite(a0, LOW);
  digitalWrite(a1, LOW);

  Serial.begin(115200);
  Serial.println("Start");
  Wire.begin();
}

void set_dig(unsigned int v) {
  digitalWrite(a0, v & 0x01);
  digitalWrite(a1, v & 0x02);
}

void set_num(unsigned int v) {
  digitalWrite(d0, v & 0x01);
  digitalWrite(d1, v & 0x02);
  digitalWrite(d2, v & 0x04);
  digitalWrite(d3, v & 0x08);
}

void set_dp(bool v) {
  digitalWrite(dp, v ? HIGH : LOW);
}

uint8_t pressed_btn_mask = 0;

void read_btn(uint8_t btn) {
/*
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
*/
}

int cnt = 0;
int hh = 0, hl = 0, mh = 0, ml = 0;

void loop() {
  if (cnt > 5) {
    DateTime now = rtc.now();

    hh = now.hour();
    hl = hh % 10;
    hh /= 10;

    mh = now.minute();
    ml = mh % 10;
    mh /= 10;
  }
  else
    cnt++;

  set_dig(3);
  set_num(hh);
  delay(del);

  set_dig(2);
  set_dp(true);
  set_num(hl);
  delay(del);

  set_dig(1);
  set_dp(false);
  set_num(mh);
  read_btn(1);
  delay(del);

  set_dig(0);
  set_num(ml);
  read_btn(0);
  delay(del);
}
