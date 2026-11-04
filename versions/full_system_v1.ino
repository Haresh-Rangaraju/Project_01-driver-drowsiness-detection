
#include <Wire.h>

const int MPU = 0x68;

int16_t AccX, AccY, AccZ;

// Calibration values (your measured)
int baseX = -300;
int baseY = 300;

int threshold = 3000;

unsigned long tiltStartTime = 0;
bool tiltDetected = false;

// Pins
int greenLED = 7;
int redLED = 8;
int buzzer = 9;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  // Wake up MPU6050
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Read accelerometer data
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);

  AccX = Wire.read() << 8 | Wire.read();
  AccY = Wire.read() << 8 | Wire.read();
  AccZ = Wire.read() << 8 | Wire.read();

  // Debug print
  Serial.print("AccX: "); Serial.print(AccX);
  Serial.print(" | AccY: "); Serial.print(AccY);
  Serial.print(" | AccZ: "); Serial.println(AccZ);

  // Check tilt
  bool tilt = abs(AccX - baseX) > threshold || abs(AccY - baseY) > threshold;

  if (tilt) {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);

    if (!tiltDetected) {
      tiltStartTime = millis();
      tiltDetected = true;
    }

    // Check if tilt persists > 2 sec
    if (millis() - tiltStartTime > 2000) {
      tone(buzzer, 1000);  // Buzzer ON
    }

  } else {
    tiltDetected = false;

    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    noTone(buzzer); // Buzzer OFF
  }

  delay(200);
}