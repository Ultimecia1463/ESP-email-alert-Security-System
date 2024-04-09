---

# **Arduino Email Alert System**

## **Overview**

The Arduino Email Alert System is a project designed to detect motion using a Passive Infrared (PIR) sensor connected to an ESP32 development board. When motion is detected, the system sends an email alert to a specified recipient using Simple Mail Transfer Protocol (SMTP). Additionally, a buzzer is used to provide audible indication of motion detection.

![Arduino Email Alert System](diagram-img.png)


## **Features**

- Motion detection using a PIR sensor.
- Email alert notification via SMTP.
- Audible alert using a buzzer.
- LED indication for motion detection.
- Configurable WiFi network credentials, SMTP server details, sender email address, and recipient email address.

## **Components**

- ESP32 DevKitC V4 development board
- Passive Infrared (PIR) motion sensor
- Buzzer
- Red LED (for indication)
- Resistor (220 ohms)
- Connecting wires

## **Setup Instructions**

1. Connect the PIR sensor to the specified GPIO pin on the ESP32 board.
2. Connect the buzzer to the specified GPIO pin on the ESP32 board for audible alert.
3. Connect the LED to the specified GPIO pin on the ESP32 board for indication.
4. Configure the WiFi network credentials, SMTP server details, sender email address, and recipient email address in the code.
5. Upload the code to the ESP32 board using the Arduino IDE or compatible software.
6. Power on the ESP32 board and observe the LED for motion detection, and listen for the buzzer for audible alerts.

## **Usage**

- When motion is detected, the LED will turn on, the buzzer will sound, and an email alert will be sent to the specified recipient.
- After sending the email alert, the LED and the buzzer will turn off, indicating the end of the alert process.
- The system will continuously monitor for motion and repeat the alert process as needed.

- Can be easily hosted on Wokwi diagram json file is provided

---
