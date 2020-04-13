
#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif

const int RX = 2;
const int Latch = 3;
const int Pwm2 = 5;
const int Pwm1 = 6;
const int M1p = 8;
const int M1m = 9;
const int M2p = 10;
const int M2m = 11;

const int threshold = 20;

enum DIR {FWD, BWD, STP};

// connect receiver to pin 2
RH_ASK driver(2000, RX);

bool get_xy(int& x, int& y) {
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN + 1];
  uint8_t buflen = RH_ASK_MAX_MESSAGE_LEN;
  for (int i = 0; i <= RH_ASK_MAX_MESSAGE_LEN; i++)
    buf[i] = 0;

  if (driver.recv(buf, &buflen)) { // Non-blocking
    sscanf(buf, "%d %d", &x, &y);
    return true;
  }

  return false;
}

int cx = 0;
int cy = 0;

void init_cxcy() {
  for (int i = 0; i < 10; i++) {
    int x, y;
    while (!get_xy(x, y))
      ;
    cx += x;
    cy += y;
  }

  cx /= 10;
  cy /= 10;
}

void setup() {
  Serial.begin(38400);  // Debugging only
  if (!driver.init())
    Serial.println("init failed");
  else
    Serial.println("RH OK");

  pinMode(Latch, OUTPUT);
  digitalWrite(Latch, LOW);

  pinMode(Pwm1, OUTPUT);
  pinMode(Pwm2, OUTPUT);
  analogWrite(Pwm1, 255);
  analogWrite(Pwm2, 255);

  pinMode(M1p, OUTPUT);
  pinMode(M1m, OUTPUT);
  pinMode(M2p, OUTPUT);
  pinMode(M2m, OUTPUT);
  digitalWrite(M1p, LOW);
  digitalWrite(M1m, LOW);
  digitalWrite(M2p, LOW);
  digitalWrite(M2m, LOW);

  digitalWrite(Latch, HIGH);
  delay(1);
  digitalWrite(Latch, LOW);

  init_cxcy();
  Serial.print("cx: ");
  Serial.print(cx);
  Serial.print(", cy: ");
  Serial.print(cy);
  Serial.print("\n");
}

void set_dir(DIR dir) {
  switch (dir) {
    case FWD: {
      digitalWrite(M1p, LOW);
      digitalWrite(M1m, HIGH);
      digitalWrite(M2p, LOW);
      digitalWrite(M2m, HIGH);
    } break;
    case BWD: {
      digitalWrite(M1p, HIGH);
      digitalWrite(M1m, LOW);
      digitalWrite(M2p, HIGH);
      digitalWrite(M2m, LOW);
    } break;
    case STP: {
      digitalWrite(M1p, LOW);
      digitalWrite(M1m, LOW);
      digitalWrite(M2p, LOW);
      digitalWrite(M2m, LOW);
    } break;
  }

  digitalWrite(Latch, HIGH);
  delay(1);
  digitalWrite(Latch, LOW);
}

void clip(int& val) {
  if (val < 0)
    val = 0;
  else if (val > 255)
    val = 255;
}

void loop() {
  int x = 0, y = 0;
  if (!get_xy(x, y)) {
    delay(20);
    return;
  }

  bool bwd = true; // direction
  y -= cy;
  x -= cx;
  if (y < 0) {
    y = -y;
    bwd = false;
  }

  if (y < threshold) {
    set_dir(STP);
    return;
  }

  set_dir(bwd ? FWD : BWD);

  int left, right;
  if (x > 0) {
    left = y;
    right = y - x;
  }
  else {
    left = y + x;
    right = y;
  }

  // now left & right values have range 0-511
  // so convert it into pwm range 0-255
  left /= 2;
  right /= 2;

  clip(left);
  clip(right);

  analogWrite(Pwm1, left);
  analogWrite(Pwm2, right);
  Serial.print(left);
  Serial.print(" : ");
  Serial.print(right);
  Serial.print("\n");
}
