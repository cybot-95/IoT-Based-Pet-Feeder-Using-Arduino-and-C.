# IoT-Based-Pet-Feeder-Using-Arduino-and-C.

Introduction:

The objective of this project is to design an automatic pet feeder using the internet of things (IoT) that can detect the motion of the pet and dispense food at predetermined intervals. This system can be operated in both manual and automatic modes.

Components Used:

Nodemcu esp8266
Ultrasonic sensor
RTC DS3231 module
Servo motor
Working:

The system operates in two modes - Automatic and Manual.

Automatic Mode:
In Automatic mode, the Ultrasonic sensor detects the motion of the pet at predefined time intervals set through the RTC module. If motion is detected, the dispenser dispenses the food, and if no motion is detected, the food is retained in the dispenser. The time intervals can be set using the Blynk app connected to the RTC module through the internet.

Manual Mode:
In Manual mode, the owner can operate the dispenser through the Blynk app connected via the internet medium to dispense the food. The owner can control the dispenser and dispense food whenever required. The manual mode can be selected using the switch provided on the feeder.

The feeder consists of a servo motor and a container to hold the pet food. The servo motor is connected to the container and is used to dispense the food when motion is detected or when the manual mode is selected. The Ultrasonic sensor is used to detect the motion of the pet and is connected to the Nodemcu esp8266. The RTC module is connected to the Nodemcu esp8266 and is used to set the time intervals for automatic mode.

The Blynk app is used to control the system through the internet. The app displays the status of the feeder and the food levels in the container. The owner can select the manual mode through the app and operate the dispenser to dispense food whenever required.

Conclusion:

In conclusion, an automatic pet feeder using IoT has been designed, which can detect the motion of the pet and dispense food at predetermined intervals. The system can be operated in both automatic and manual modes and can be controlled through the internet using the Blynk app. The system provides convenience to pet owners, enabling them to ensure that their pets are fed on time and with the right amount of food. This system can be further improved by adding additional features such as a camera to monitor the pet's activities and health.
