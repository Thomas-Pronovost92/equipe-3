#include "motor.h"

#define LED_PIN jkl13


int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo

bool nextMove = false;

float measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  long duration = pulseIn(echoPin, HIGH);

  // Convert the time into a distance
  float distance_cm = (duration / 2) / 29.1;   // Divide by 29.1 or multiply by 0.0343
  return distance_cm;
}

void setup() {
  setupMotors();
  stopAllMotors();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, HIGH);

  Serial.begin(9600);

  moveForward();
}

void randomlyChangeDirection(){
  if(nextMove){
      turnLeft();
  }else{
    turnRight();
  }
  nextMove = !nextMove;
}

void loop() {
  float distance = measureDistance();

  if (distance < 20.0) {
      moveBackward();
      delay(500);
      randomlyChangeDirection();
  } else {
    moveForward();
  }
}
