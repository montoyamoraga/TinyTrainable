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

// percentage, between 0.0 and 1.0
float servoChance = 0.5;

int servoPositions[] = {0, 30};

int servoPositionsIndex = 0;

unsigned long timePrevious = 0;
unsigned long timeNow = 0;


// NOTES
// TODO add notes about range of servo, min and max angles between 0 and 180
  // tempo between 10 and 120


void setup() {

   Serial.begin(9600);
  //  while (!Serial);

  // TODO: maybe this step is unnecesary?
  pinMode (servoPin, OUTPUT);

  myServo.attach(servoPin);

}

void loop() {


  // retrieve one
  // int servoPause = bpmToMs(tempos[2]);

   int servoPause = bpmToMs(60);

    servoMoveTo(servoPositions[servoPositionsIndex], servoPause);
    //    delay(servoPause / 2);
    //    delay(servoPause/2 + random(100));

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

void servoMoveTo(int angleNew, int servoPause) {

  
  // myServo.write(angleNew);
  // delay(servoPause / 2);

  // update timeNow
  timeNow = millis();

  // add randomness
  // int randomRange = int(servoPause * tempoRandomness);
  // int randomNumber = random(-randomRange/2, randomRange/2);



  // if enought time has passed
  if (timeNow - timePrevious >= servoPause) {

    // update timePrevious
    timePrevious = timeNow;

    // add chance
    Serial.println(random());
    if (random(1000)/1000.0 < servoChance) {
      servoPositionsIndex = (servoPositionsIndex + 1);
      servoPositionsIndex = servoPositionsIndex % (sizeof(servoPositions)/sizeof(servoPositions[0]));
      myServo.write(angleNew);
    }

  }


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
// we divide by 2 because servo moves twice per cycle
int bpmToMs(int tempo) {
  int ms = 60000 / tempo;
  ms = ms /2;
  return ms;
}
