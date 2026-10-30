# Driver Drowsiness Detection System — Version 1

## Overview

Driver Drowsiness Detection System — Version 1 is an embedded systems prototype developed to explore sensor-based driver head-movement monitoring and warning indication.

The system uses an Arduino Nano and an MPU6050 motion sensor to acquire movement data, process sensor readings, and activate visual and audible indicators based on predefined detection conditions.

## Objectives

* Interface a motion sensor with a microcontroller using I2C.
* Acquire and process sensor data for head-movement monitoring.
* Implement embedded detection logic using Arduino firmware.
* Integrate LED indicators and an active buzzer for warning outputs.
* Practise hardware interfacing, firmware development, and system integration.

## Hardware Components

* Arduino Nano V3.0
* MPU6050 accelerometer and gyroscope
* Red and green LEDs
* Current-limiting resistors
* Active buzzer
* Breadboard and jumper wires

## System Architecture

Head Movement → MPU6050 Sensor → I2C Communication → Arduino Nano → Detection Logic → LED Indicators and Buzzer

## Working Principle

The MPU6050 measures acceleration and angular velocity associated with head movement. The Arduino Nano reads the sensor data and evaluates it using the implemented detection logic. The output indicators provide visual and audible feedback when the configured warning condition is detected.

This project is a prototype for learning and experimentation. It is not a validated automotive safety system.

## Repository Structure

* `Codes/` — Firmware source code and development stages.
* `Data/` — Project data and recorded observations.
* `Hardware/` — Component information, setup images, and wiring diagrams.
* `Notes/` — Development notes and implementation records.
* `Versions/` — Saved firmware versions and experimental stages.
* `Working video` — Video demonstrating the project and its operation.

## Engineering Focus

* Embedded C/C++ firmware development
* Microcontroller and sensor interfacing
* I2C communication
* Sensor-data acquisition
* Embedded detection logic
* Hardware–software integration
* Debugging and iterative development

## Project Status

Version 1 was developed as a working prototype to explore sensor-based head-movement detection and embedded warning outputs.

## Future Scope

Potential future improvements include more robust detection logic, additional testing, improved sensor calibration, and further evaluation of the system's limitations.

## Disclaimer

This prototype is intended for educational and engineering development purposes. It has not been validated for production automotive use or as a reliable driver-safety device.
