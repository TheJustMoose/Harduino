#define ENC_PORT PINC

/* returns change in encoder state (-1,0,1) */
int8_t read_encoder() {
  static int8_t enc_states[] = {0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0};
  static uint8_t old_AB = 0;

  old_AB <<= 2;                   //remember previous state
  old_AB |= ( ENC_PORT & 0x03 );  //add current state
  return ( enc_states[( old_AB & 0x0f )]);
}

uint8_t pressed_btn_mask = 0;

void read_btn(uint8_t btn) {
  digitalWrite(12, btn & 1);
  digitalWrite(13, btn & 2);

  uint8_t mask = 1 << btn;
  if (digitalRead(A2)) {
    pressed_btn_mask &= 0xFF ^ mask; // reset/release current btn
    return;
  }

  delay(5);
  if (digitalRead(A2))
    return;

  if (!(pressed_btn_mask & mask)) {
    pressed_btn_mask |= mask;
    Serial.print("btn ");
    Serial.print(btn);
    Serial.println(" pressed");
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Start");

  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  static uint8_t counter = 0;      //this variable will be changed by encoder input
  int8_t tmpdata = read_encoder();
  if (tmpdata) {
    counter += tmpdata;
    Serial.print("valc: ");
    Serial.println(counter);
  }

  for (uint8_t i = 0; i < 4; i++)
    read_btn(i);
}
