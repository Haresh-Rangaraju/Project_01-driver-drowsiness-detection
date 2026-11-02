#include <Wire.h>

const int MPU = 0x68;

int16_t AccX, AccY, AccZ;

// Baseline values (from your data)
int baseX = -300;
int baseY = 300;

int threshold = 3000;

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

  Serial.print("AccX: "); Serial.print(AccX);
  Serial.print(" | AccY: "); Serial.print(AccY);
  Serial.print(" | AccZ: "); Serial.println(AccZ);

  if (abs(AccX - baseX) > threshold || abs(AccY - baseY) > threshold) {
    digitalWrite(13, HIGH); // Alert
  } else {
    digitalWrite(13, LOW);
  }

  delay(500);
}
