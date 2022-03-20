#include<ESP32Servo.h>

int servopin = 12;
int angle = 0;
int led = 4;                // the pin that the LED is atteched to
int sensor = 13;              // the pin that the sensor is atteched to
int trigPin=2;
int echoPin=14;
Servo servo;

int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(servopin);
  Serial.begin(9600);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    float duration = pulseIn(echoPin,HIGH);
    float distance = duration*0.034/2;    
    Serial.println(distance);
    Serial.print("cm");
    Serial.println(" ");
    delay(100);                // delay 100 milliseconds 

    if (distance < 10) {
      servo.write(100);
      delay(500);
    }
      if (state == LOW) {
        Serial.println("Motion detected!"); 
        state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      digitalWrite(trigPin,LOW);
      servo.write(0);
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}
