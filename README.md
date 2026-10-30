# Driver Drowsiness Detection System — Version 1

An Arduino-based embedded prototype that uses an MPU6050 motion sensor to detect predefined head-tilt conditions and provide visual and audible alerts.

## Overview

Driver Drowsiness Detection System — Version 1 is an embedded systems project developed to explore sensor interfacing, I²C communication, microcontroller-based signal processing, and alert control.

The system reads motion data from an MPU6050 accelerometer and gyroscope module using an Arduino Nano. The firmware evaluates sensor readings against predefined calibration values and a tilt threshold to trigger warning outputs.

## Objectives

- Interface an MPU6050 motion sensor with an Arduino Nano using I²C.
- Read and process accelerometer data.
- Implement threshold-based head-tilt detection.
- Control visual indicators and an audible alert using digital outputs.
- Develop practical experience in embedded C/C++ firmware development and hardware–software integration.

## Hardware Components

| Component | Purpose |
|---|---|
| Arduino Nano (ATmega328P) | Microcontroller and firmware execution |
| MPU6050 | Accelerometer and gyroscope measurements |
| Green LED | Visual status indication |
| Red LED | Visual warning indication |
| Active buzzer | Audible alert |
| Current-limiting resistors | LED current limiting |
| Breadboard and jumper wires | Circuit assembly and interconnections |

## System Architecture

```text
Head Movement
      ↓
MPU6050 Motion Sensor
      ↓
I²C Communication
      ↓
Arduino Nano
      ↓
Sensor Data Processing
      ↓
Tilt-Threshold Evaluation
      ↓
LED Indicators + Buzzer
```

## Software and Technologies

- **Programming language:** Arduino C/C++
- **Development environment:** Arduino IDE
- **Microcontroller:** ATmega328P
- **Sensor interface:** I²C
- **Firmware concepts:** Sensor data acquisition, calibration values, threshold-based detection, digital output control

## Firmware Configuration

The firmware includes the following initial configuration values:

| Parameter | Value |
|---|---|
| MPU6050 I²C address | `0x68` |
| Serial communication baud rate | `9600` |
| Green LED output pin | `D7` |
| Red LED output pin | `D8` |
| Buzzer output pin | `D9` |
| Tilt threshold variable | `3000` |

The firmware also contains calibration variables for the accelerometer readings. These values are implementation-specific and may require recalibration depending on sensor orientation and operating conditions.

## Repository Contents

- `n6_drowsiness_full_system_v1.ino` — Integrated Version 1 Arduino firmware.

Additional hardware documentation, wiring diagrams, development notes, and test evidence can be added as they are prepared and verified.

## Engineering Scope

This project demonstrates practical exposure to:

- Microcontroller-based embedded firmware.
- I²C sensor interfacing.
- Accelerometer data acquisition.
- Threshold-based detection logic.
- Digital control of visual and audible indicators.
- Hardware–software integration and prototype development.

These fundamentals are relevant to further learning in automotive embedded electronics, ECU development, firmware debugging, and embedded system validation.

## Limitations

- Detection is based on predefined motion-related conditions, not a validated measurement of driver fatigue.
- Sensor calibration, mounting position, and movement can affect detection behaviour.
- False-positive and false-negative performance has not been established through formal validation.
- The prototype is not qualified for automotive production or safety-critical use.

**This project is an educational embedded systems prototype and must not be relied upon as a driver-safety device.**

## Future Development

Potential future improvements include:

- More robust sensor calibration and filtering.
- Improved detection logic and timing validation.
- Systematic testing under different movement conditions.
- Documented test cases and measured results.
- Further exploration of automotive embedded software and validation practices.
