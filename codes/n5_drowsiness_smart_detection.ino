#include <Wire.h>

const int MPU = 0x68;

int16_t AccX, AccY, AccZ;

int baseX = -300;
int baseY = 300;

int threshold = 3000;

unsigned long tiltStartTime = 0;
bool tiltDetected = false;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  pinMode(13, OUTPUT);
}

void loop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);

  AccX = Wire.read() << 8 | Wire.read();
  AccY = Wire.read() << 8 | Wire.read();
  AccZ = Wire.read() << 8 | Wire.read();

  if (abs(AccX - baseX) > threshold || abs(AccY - baseY) > threshold) {

    if (!tiltDetected) {
      tiltStartTime = millis();
      tiltDetected = true;
    }

    if (millis() - tiltStartTime > 2000) {
      digitalWrite(13, HIGH);
    }

  } else {
    tiltDetected = false;
    digitalWrite(13, LOW);
  }

  delay(200);
}
