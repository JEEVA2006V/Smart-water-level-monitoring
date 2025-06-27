**SMART WATER LEVEL MONITORING**  

**OBJECTIVE**

Design a system using an ultrasonic sensor and Arduino to detect and alert water levels.

**COMPONENTS USED**

1.Arduino Uno  
2.Ultrasonic Sensor (HC-SR04)  
3.16x2 LCD Display with I2C module  
4. 3 LEDs (green, yellow, red)  
5.Buzzer  
6.Breadboard and jumper wires  

**WORKING**

The ultrasonic sensor continuously measures the distance between the sensor and the water surface. Based on the measured water level:

-> Green LED turns on → Low water level  
-> Yellow LED turns on → Medium water level  
-> Red LED and buzzer activate → High water level (tank full alert)  
-> The current water level status is also displayed on the LCD screen.

This system provides both visual (LEDs and LCD) and audio (buzzer) feedback for monitoring tank water levels.

**WHAT I LEARNED**

- Interfacing ultrasonic sensor with Arduino  
- Using I2C LCD display to show real-time data  
- Controlling multiple outputs based on sensor values  
- Simulating real-world conditions in Wokwi

**TOOLS USED**

Wokwi Online Simulator

Blynk IoT Platform


