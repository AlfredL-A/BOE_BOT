#import <Servo.h>

// define speeds
const int idle = 1500;
const int maxRight = 1300;
const int maxLeft = 1700;
const int minRight = 1700;
const int minLeft = 1300;

// servo setup
Servo servoRight;
Servo servoLeft;

// pins setup
const int rightServoPin = 10;
const int leftServoPin = 11;
const int piezo = 4;

void setup() {
  // setup in/outs
  pinMode(piezo, OUTPUT);
  servoRight.attach(rightServoPin);
  servoLeft.attach(leftServoPin);
  
  // run Z track, input is distance in centimeters
  forward(1000);
  turnRight(1000);
  turnLeft(1000);
  uTurn(1000);
}

void loop() {  

}

void forward(int time) {
  // accelerate servos
  for (int i = 0; i <= 200; i++) {
    servoRight.writeMicroseconds(idle - i);
    servoLeft.writeMicroseconds(idle + i);
    delay(10);
  }
  
  delay(time);
  
  // decelerate servos
  for (int i = 0; i <= 200; i++) {
    servoRight.writeMicroseconds(maxRight + i);
    servoLeft.writeMicroseconds(maxLeft - i);
    delay(10);
  }
}

void turnRight(int time) {
  // accelerate servo
  for (int i = 0; i <= 200; i++) {
    servoLeft.writeMicroseconds(idle + i);
    delay(10);
  }
  
  delay(time);
  
  // decelerate servo
  for (int i = 0; i <= 200; i++) {
    servoLeft.writeMicroseconds(maxLeft - i);
    delay(10);
  }
}

void turnLeft(int time) {
  // accelerate servo
  for (int i = 0; i <= 200; i++) {
    servoRight.writeMicroseconds(idle - i);
    delay(10);
  }
  
  delay(time);
  
  // decelerate servo
  for (int i = 0; i <= 200; i++) {
    servoRight.writeMicroseconds(maxRight + i);
    delay(10);
  }
}

void uTurn(int time) {
  // accelerate servos
  for (int i = 0; i <= 200; i++) {
    servoRight.writeMicroseconds(idle - i);
    servoLeft.writeMicroseconds(idle - i);
    delay(10);
  }
  
  delay(time);
  
  // decelerate servos
  for (int i = 0; i <= 200; i++) {
    servoRight.writeMicroseconds(maxRight + i);
    servoLeft.writeMicroseconds(minLeft + i);
    delay(10);
  }
}
