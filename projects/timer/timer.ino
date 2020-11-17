#include <TimerOne.h>
#include <EEPROM.h>

// hardware:
// 3 tactile button + rotary encoder button
// 74HC139 decoder

// connections:
// pin 12 == PB4 -> A0 pcb -> 13 (A1|B) decoder pin
// pin 13 == PB5 -> A1 pcb -> 14 (A0|A) decoder pin
// pin A2 == PC2 -> all tactile buttons + pullup
// pin A1 == PC1 -> rotary encoder pin A
// pin A0 == PC0 -> rotary encoder pin B
// pin 8-11 == PB0-3 -> 74LS247 pins A-D
// pin 2 -> decimal point

// Do not use "const byte" here, it's not work
// Input ports
#define ENC_PORT PINC
#define BTN_PORT PINC
#define BTN_BIT  2

// Output ports
#define DIG_PORT PORTB
#define DIG_BIT_B 4  // 74HC139
#define DIG_BIT_A 5

#define NUM_PORT PORTB
#define NUM_BIT_0 0  // 74LS247
#define NUM_BIT_1 1
#define NUM_BIT_2 2
#define NUM_BIT_3 3

const int dp = 2;  // decimal point
const int buzzer = 3;
const int line = 4;  // buttons state
const int mosfet1 = 5;

const int d0 = 8;
const int d1 = 9;
const int d2 = 10;
const int d3 = 11;

const int a0 = 13;  // yes! it's fail :(
const int a1 = 12;

const int del = 5; // delay ms

uint8_t btn_was_pressed[4] = {0, 0, 0, 0};
uint8_t btn_pressed[4] = {0, 0, 0, 0};
uint8_t LED[4] = {0, 0, 0, 0}; // the numbers on the LED
uint8_t digit = 0; // current processed digit | button
boolean in_edit = true;
uint16_t counter = 0;  // how many times timer interrupt was called
int16_t rest_of_time = 0;
bool should_update = false;

void set_addr(uint8_t addr) {
  // PB5 == A decoder pin
  if (addr & 0x01)
    bitSet(DIG_PORT, DIG_BIT_A);
  else
    bitClear(DIG_PORT, DIG_BIT_A);

  // PB4 == B decoder pin
  if (addr & 0x02)
    bitSet(DIG_PORT, DIG_BIT_B);
  else
    bitClear(DIG_PORT, DIG_BIT_B);
}

void set_number(uint8_t number) {
  if (number & 0x01)
    bitSet(NUM_PORT, NUM_BIT_0);
  else
    bitClear(NUM_PORT, NUM_BIT_0);

  if (number & 0x02)
    bitSet(NUM_PORT, NUM_BIT_1);
  else
    bitClear(NUM_PORT, NUM_BIT_1);

  if (number & 0x04)
    bitSet(NUM_PORT, NUM_BIT_2);
  else
    bitClear(NUM_PORT, NUM_BIT_2);

  if (number & 0x08)
    bitSet(NUM_PORT, NUM_BIT_3);
  else
    bitClear(NUM_PORT, NUM_BIT_3);
}

void on() {
  digitalWrite(mosfet1, HIGH);
  Serial.println("ON");
}

void off() {
  digitalWrite(mosfet1, LOW);
  Serial.println("OFF");
}

void beep() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(buzzer, HIGH);
    delay(150);
    digitalWrite(buzzer, LOW);
    delay(200);
  }
}

void check_buttons() {
  byte val = BTN_PORT;
  boolean vbl = val & _BV(BTN_BIT);
  if (!vbl) {
    if (btn_was_pressed[digit])
      btn_pressed[digit] = true;
    else
      btn_was_pressed[digit] = true;
  } else {
    btn_pressed[digit] = false;
    btn_was_pressed[digit] = false;
  }
}

/* returns change in encoder state (-1,0,1) */
int8_t read_encoder() {
  static int8_t enc_states[] = {0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0};
  static uint8_t old_AB = 0;

  old_AB <<= 2;                   // remember previous state
  old_AB |= ( ENC_PORT & 0x03 );  // add current state
  return (enc_states[( old_AB & 0x0f )]);
}

void on_tmr() {
  digit++;
  if (digit >= 4)
    digit = 0;

  set_addr(digit);
  set_number(LED[digit]);
  check_buttons();

  if (in_edit)
    return;

  counter++;
  if (counter < 1000)
    return;

  counter = 0;
  rest_of_time--;
  should_update = true;
}

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize(1000); // in us
  Timer1.attachInterrupt(on_tmr);

  pinMode(line, INPUT);

  pinMode(dp, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(mosfet1, OUTPUT);

  pinMode(d0, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);

  pinMode(a0, OUTPUT);
  pinMode(a1, OUTPUT);

  
  digitalWrite(dp, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(mosfet1, LOW);

  digitalWrite(d0, LOW);
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);

  digitalWrite(a0, LOW);
  digitalWrite(a1, LOW);

  Serial.begin(115200);
  Serial.println("Start");

  rest_of_time = load();
  update_led();
}

void save(uint16_t val) {
  uint8_t low = val & 0xFF;
  EEPROM.write(0, low);

  uint8_t high = val >> 8;
  EEPROM.write(1, high);
}

uint16_t load() {
  uint8_t low = EEPROM.read(0);
  uint8_t high = EEPROM.read(1);
  return (high << 8) + low;
}

void update_led() {
  int t = rest_of_time;
  LED[0] = t % 10;
  t /= 10;
  LED[1] = t % 10;
  t /= 10;
  LED[2] = t % 10;
  t /= 10;
  LED[3] = t % 10;
  t /= 10;
}

void edit() {
  int8_t zoom = btn_pressed[3] ? 10 : 1;
  int8_t tmp = read_encoder()*zoom;
  if (tmp) {
    Serial.print(tmp);
    Serial.print(" ");
    rest_of_time += tmp;
    if (rest_of_time < 0)
      rest_of_time = 0;
    if (rest_of_time > 9999)
      rest_of_time = 9999;
    Serial.println(rest_of_time);
    update_led();
  }
  
  if (btn_pressed[2]) {
    if (rest_of_time) {
      save(rest_of_time);
      counter = 0;
      in_edit = false;
      on();
    }
    Serial.println("Start");
    return;
  }
  
  if (btn_pressed[1]) {
    Serial.println("btn 1 pressed");
  }
  
  if (btn_pressed[2]) {
    Serial.println("btn 2 pressed");
  }
}

void timer() {
  if (btn_pressed[1]) {
    off();
    in_edit = true;
    rest_of_time = load();
    update_led();
    return;
  }

  if (!should_update)
    return;

  if (!rest_of_time) {
    off();
    in_edit = true;
    update_led();
    beep();
    rest_of_time = load();
  }
  
  update_led();
  should_update = false;
}

void loop() {
  if (in_edit)
    edit();
  else
    timer();
}
