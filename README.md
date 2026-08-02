# IoT-Application

## Smart Fire Detection & Alert System (ESP32 + Blynk IoT)

A real-time IoT-based fire detection system built using ESP32, a flame sensor, a buzzer, and the Blynk Cloud platform. The system instantly detects fire, triggers an on-device alarm, and sends high-priority mobile notifications (sound and vibration) through the Blynk IoT platform.

---

## Project Overview

This project focuses on creating a simple, low-cost, and effective early fire-alert system that can be deployed in homes, hostels, offices, and small buildings.

The system continuously monitors for fire using a flame sensor. When a flame is detected:

- A buzzer is activated as a local alarm
- A high-priority mobile notification is sent to the user
- The alert helps people respond quickly before the fire spreads

This demonstrates how IoT can significantly improve safety and emergency responsiveness.

---

## Features

**Fire Detection**
Uses a digital flame sensor to detect fire quickly and accurately.

**Local Alarm**
Activates a buzzer immediately when a flame is detected.

**Real-Time Push Notifications**
- Sends instant alerts using Blynk Events
- Includes sound, vibration, and popup for urgent warnings

**Wi-Fi Connected (ESP32)**
- ESP32 connects to Blynk Cloud via Wi-Fi hotspot or router
- Real-time updates and monitoring from anywhere

**Auto-Reset Alert System**
- Alerts trigger again each time a new fire is detected
- Smart state-change detection ensures no spamming

---

## Tech Stack

### Hardware
- ESP32 Development Board
- Flame Sensor Module
- Passive Buzzer
- Jumper Wires + Breadboard
- USB Power Supply

### Software
- Arduino IDE
- C/C++ for ESP32 firmware
- Blynk IoT Platform (Cloud + Mobile App)

---

## System Workflow

1. Flame sensor continuously monitors the environment
2. Sensor output is sent to the ESP32
3. ESP32 triggers:
   - Buzzer alarm
   - Blynk event notification
4. User receives a real-time alert on the mobile app
5. System resets when the flame disappears and is ready for the next event

---

## Demo

1. Flame is brought near the sensor
2. Buzzer sounds immediately
3. Mobile app delivers a critical alert notification (sound + vibration)
4. Flame is removed, system returns to normal state

---

## Future Enhancements

- Add smoke sensor and temperature sensor
- Add water pump and relay for automatic fire suppression
- Add SMS or WhatsApp message alerts
- Add battery backup for power failure
- Add cloud data logging and analytics dashboard
- Integrate with emergency services

---

## License

This project is open source. Feel free to use, modify, and distribute it with attribution.
