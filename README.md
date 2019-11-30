# Fire_Fighting_Bot
## BASIC IDEA
In the event of a fire breakout, to rescue people and to put out the fire we are forced to use human resources which are not safe. With the advancement of technology especially in Robotics it is very much possible to replace humans with robots for fighting the fire.
## Material Used
Arduino NANO, 
Fire sensor or Flame sensor (3 Nos), 
Servo Motor (SG90), 
L293D motor Driver module, 
Small Breadboard, 
Robot chassis with motors and wheel (any type), 
A small can, 
Connecting wires, 
## Design and Working
The main brain of this project is the Arduino, but in-order to sense fire we use the Fire sensor module (flame sensor) . These sensors have an IR Receiver (Photodiode) which is used to detect the fire. When fire burns, it emits a small amount of Infra-red light, this light will be received by the IR receiver on the sensor module. Then we use an Op-Amp to check for change in voltage across the IR Receiver, so that if a fire is detected the output  pin (DO) will give 0V(LOW) and if the is no fire the output pin will be 5V(HIGH). 
## How to run
use Arduino IDE to upload this code in arduino.
