#include <Servo.h>

Servo myServo;
int servoPin = 9;

int angleMin = 30;
int angleMax = 180;

int angleCurrent = 0;
int angleDirection = 1;
int angleDelta = 30;

int timeDelta = 1000;

int tempos[] = {60, 120, 240};

int servoPositions[] = {0, 30};

// NOTES
// TODO add notes about range of servo, min and max angles between 0 and 180

void setup() {

  //  Serial.begin(9600);
  //  while (!Serial);
  //  Serial.println("hello world");

  // TODO: maybe this step is unnecesary?
  pinMode (servoPin, OUTPUT);

  myServo.attach(servoPin);

  // move to angle 0 at beginning?
  servoInitialize(0);
}

void loop() {

  //  Serial.println("another loop");

  // retrieve one
  int servoPause = bpmToMs(tempos[0]);

  for (int i = 0; i < 2; i++) {
    servoMoveTo(servoPositions[i], servoPause);
    //    delay(servoPause / 2);
    //    delay(servoPause/2 + random(100));
  }


  //    for (int i = 0; i < 6; i++) {
  //      servoMoveTo(30 * i);
  //      delay(2000);
  //    }



  //  angleCurrent = angleCurrent + angleDelta * angleDirection;
  //
  //  if (angleCurrent <= angleMin) {
  //    angleCurrent = angleMin;
  //    angleDirection = 1;
  //  }
  //  else if (angleCurrent >= angleMax) {
  //    angleCurrent = angleMax;
  //    angleDirection = -1;
  //  }
  //
  //  Serial.println(angleCurrent);
  //  myServo.write(angleCurrent);
  //  delay(2000);

}

void servoInitialize(int initAngle) {
  //  Serial.println("start servoInitialize");
  myServo.write(initAngle);
  delay(2000);
  //  Serial.println("end servoInitialize");

}

void servoMoveTo(int angleNew, int servoPause) {

  myServo.write(angleNew);
  delay(servoPause / 2);





  // update
  //  angleCurrent = myServo.read();

  //  // move forwards
  //  while (angleCurrent < angleNew) {
  //    angleCurrent = angleCurrent + 1;
  //    myServo.write(angleCurrent);
  //    delay(10);
  //  }
  //  // move backwards
  //  while (angleCurrent > angleNew) {
  //    angleCurrent = angleCurrent - 1;
  //    myServo.write(angleCurrent);
  //    delay(10);
  //  }

}

// function for converting from tempo in bpm to milliseconds
int bpmToMs(int tempo) {
  int ms = 60000 / tempo;
  return ms;
}
