# Keo_Automated_Door_System_ESP32
## Automated Door using PIR motion detector and Ultrasonic sensor for distance Measurement

This Automated door system makes use of PIR Sensor which detects infrared rays ( detects motion ) and accordingly outputs digital signals.
when any movement is occured in front of the PIR sensor, it outputs a HIGH signal.
the ultrasonic sensor is programmed such that it starts detecting the distance when PIR sensor is HIGH.
when the object keeps coming closer, the distance measured by the ultrasonic sensor keeps decreasing.

in this case the servo motor (representing the door) is set to open when the object is at or closure than 10cm from the ultrasonic sensor.

And after some delay, the door closes back and ultrasonic sensor stops calculating the distance until next object is detected by the PIR sensor.


## Connections

PIR sensor Digital Output <-> ESP32-cam Pin GPIO13
Ultrasonic Trig Pin <-> ESP32-cam Pin GPIO2
Ultrasonic Echo Pin <-> ESP32-cam Pin GPIO14
Servo PWM pin <-> ESP32-cam Pin GPIO12

The LED used is the on-board LED which is shorted to the GPIO4 pin.
