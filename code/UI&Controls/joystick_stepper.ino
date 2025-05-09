#include <Stepper.h> 

#define VRX_PIN A1
#define VRY_PIN A0

#define STEPS 64

int max_steps = 64;
int steps_taken = 0;
int speed_ = 0;
int speed2 = 0;
int x_val;

int max_reached = 0;;

#define IN1  7
#define IN2  6
#define IN3  5
#define IN4  4

#define IN1b 11
#define IN2b 10
#define IN3b 9
#define IN4b 8

Stepper stepper(STEPS, IN1, IN2, IN3, IN4);
Stepper stepper_2(STEPS, IN1b, IN2b, IN3b, IN4b);

//Servo myservo;
//int pos = 0;
int turn = 0;

void setup()
{
  Serial.begin(9600);
  //myservo.attach(9);
}

void loop()
{
  // read analog value from the potentiometer
  int val = analogRead(VRX_PIN);
  int y = analogRead(VRY_PIN);

  Serial.println(y);

  while (y > 523)
  {
    stepper_2.setSpeed(500);
    turning(val);
    stepper_2.step(1);
    val = analogRead(VRX_PIN);
    y = analogRead(VRY_PIN);
  }

  while (y < 500)
  {
    stepper_2.setSpeed(500);
    turning(val);
    stepper_2.step(-1); 
    val = analogRead(VRX_PIN);
    y = analogRead(VRY_PIN);
  }

  while (y > 500 && y < 523)
  {
    digitalWrite(IN1b, LOW);
    digitalWrite(IN2b, LOW);
    digitalWrite(IN3b, LOW);
    digitalWrite(IN4b, LOW);
    turning(val);
    val = analogRead(VRX_PIN);
    y = analogRead(VRY_PIN);
  }

}

void turning(int x_val)
{
  if (x_val >= 523)
  {
    speed_ = 100;

    // move the motor (1 step)
    if (steps_taken < max_steps)
    {
      stepper.setSpeed(speed_);
      stepper.step(1);
      steps_taken += 1;
    }
    else
    {
      Serial.println("Max positive steps reached");
      //stepper.step(0);
      stepper_2.setSpeed(200);
      /*
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);*/
    }
  }

  if (x_val <= 500)
  {
    speed_ = 100; 
    // move the motor (1 step)
    if (steps_taken > -max_steps)
    {
      stepper.setSpeed(speed_);
      stepper.step(-1);
      steps_taken -= 1;
    }
    else
    {
      Serial.println("Max negative steps reached");
    }
  }

  if((x_val > 500) && (x_val < 523) )
  { 
    speed_ = 100; 
    if (steps_taken > 0)
    {
      stepper.setSpeed(speed_);
      stepper.step(-1);
      steps_taken -= 1;
    }

    else if (steps_taken < 0)
    {
      stepper.setSpeed(speed_);
      stepper.step(1);
      steps_taken += 1;
    }

    else
    {
      //stepper_2.setSpeed(100);
      Serial.println("Original position");
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
  }
}


