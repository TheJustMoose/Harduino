
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

void setup() {
  Serial.begin(38400);    // Debugging only
  if (!driver.init())
    Serial.println("init failed");
}

void loop() {
  int x = analogRead(A2);
  if (x >= 1024)
    x = 1024;
  int y = analogRead(A3);
  if (y >= 1024)
    y = 1024;

  char buf[20];
  sprintf(buf, "%d %d", x, y);
  Serial.println(buf);
  driver.send(buf, strlen(buf));
  driver.waitPacketSent();
  delay(200);
}
