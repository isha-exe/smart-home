#include <Servo.h>
Servo motor;

int const trigPin = 9;
int const echoPin = 10;


void setup() 
{
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  motor.attach(6);
}

void loop() 

// ultrasonic sensor connected servo
{
 long duration, distance;
  digitalWrite(trigPin, HIGH);
  
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  Serial.print(distance);
  Serial.println("CM");
  
  if (distance < 5)
   {
    motor.write(90);
    delay(3000);
    } 
 else 
   {
    motor.write(0);
  }
  delay(160);
 } 
