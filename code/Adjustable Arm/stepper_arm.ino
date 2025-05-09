#include <Stepper.h>

// change this to the number of steps on your motor
//#define STEPS 200

// create an instance of the stepper class, specifying
const int stepsPerRevolution = 200;

#define button1pin 7
#define button2pin 12
//int button3pin = 2;
int val1 = 0;
int val2 = 0;
Stepper mystepper(stepsPerRevolution, 8, 9, 10, 11);
// the number of steps of the motor and the pins it's
// attached to
//Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
//int previous = 0;

void setup() {
  // set the speed of the motor to 30 RPMs
  mystepper.setSpeed(300); //Was 60
  Serial.begin(9600);
  pinMode(button1pin, INPUT);
  pinMode(button2pin, INPUT);
  //pinMode(button3pin, OUTPUT);
}

void loop() {
  // get the sensor value
  //int val = analogRead(0);
  //Serial.println("clockwise");
  //mystepper.step(stepsPerRevolution);
  delay(100);
  //bool button1state = digitalRead(button1pin);
  //bool button2state = digitalRead(button2pin);
  val1 = digitalRead(button1pin);
  val2 = digitalRead(button2pin);

  while (val1 == HIGH)
  {
    Serial.println("counterclockwise ");
    mystepper.step(-1);
    delay(15);
    val1 = digitalRead(button1pin);
  }

  while (val2 == HIGH) {
    Serial.println("clockwise ");
    mystepper.step(1);
    delay(15);
    val2 = digitalRead(button2pin);
  }

  /*else if (val2 == HIGH){
    Serial.println("clockwise ");
    mystepper.step(stepsPerRevolution);
    delay(15);
    val2 = digitalRead(button2pin);
  }*/

  if (!val1 || !val2) {
    Serial.println("stop ");
    /*mystepper.step(0);
    val1 = digitalRead(button1pin);
    val2 = digitalRead(button2pin); */
    delay(15);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }

//Serial.println("clockwise ");
//
//
}

  /*int step=map(val, 0, 1023, 0, STEPS);

  // move a number of steps equal to the change in the
  // sensor reading
  stepper.step(val - previous);

  // remember the previous value of the sensor
  previous = val;
}*/
