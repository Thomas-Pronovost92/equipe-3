#ifndef _MOTOR_H_
#define _MOTOR_H_

#define MOTOR_1_FORWARD 3
#define MOTOR_1_BACKWARD 4
#define MOTOR_2_FORWARD 8
#define MOTOR_2_BACKWARD 9

#define EN_1 A5
#define EN_2 A4

void setupMotors() {
  pinMode(MOTOR_1_FORWARD, OUTPUT);
  pinMode(MOTOR_2_FORWARD, OUTPUT);

  pinMode(MOTOR_1_BACKWARD, OUTPUT);
  pinMode(MOTOR_2_BACKWARD, OUTPUT);

  pinMode(EN_1,   OUTPUT);
  pinMode(EN_2, OUTPUT);

  analogWrite(EN_1, 600); //ENB pin
  analogWrite(EN_2, 600); //(Optional)
}

void moveMotor1Forward() {
  digitalWrite(MOTOR_1_BACKWARD, LOW);
  digitalWrite(MOTOR_1_FORWARD, HIGH);
}

void moveMotor2Forward() {
  digitalWrite(MOTOR_2_BACKWARD, LOW);
  digitalWrite(MOTOR_2_FORWARD, HIGH);
}

void moveMotor1Backward() {
  digitalWrite(MOTOR_1_FORWARD, LOW);
  digitalWrite(MOTOR_1_BACKWARD, HIGH);

}

void moveMotor2Backward() {
  digitalWrite(MOTOR_2_FORWARD, LOW);
  digitalWrite(MOTOR_2_BACKWARD, HIGH);
}

void stopAllMotors() {
  digitalWrite(MOTOR_1_FORWARD, LOW);
  digitalWrite(MOTOR_2_BACKWARD, LOW);
  digitalWrite(MOTOR_2_FORWARD, LOW);
  digitalWrite(MOTOR_1_BACKWARD, LOW);
}

void moveForward(){
  stopAllMotors();
  delay(500);
  moveMotor1Forward();
  moveMotor2Forward();
}

void moveBackward(){
  stopAllMotors();
  delay(500);
  moveMotor1Backward();
  moveMotor2Backward();
}

void turnLeft() {
  stopAllMotors();
  delay(500);
  moveMotor1Backward();
  moveMotor2Forward();
  delay(500);
  stopAllMotors();
}

void turnRight() {
  stopAllMotors();
  delay(500);
  moveMotor1Forward();
  moveMotor2Backward();
  delay(500);
  stopAllMotors();
}

#endif
