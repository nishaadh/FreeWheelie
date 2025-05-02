#include <Stepper.h> 
#include <Servo.h>

#define VRX_PIN A1
#define VRY_PIN A0

#define STEPS 64

int max_steps = 64;
int steps_taken = 0;
int speed_ = 0;

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

  if (y > 523)
  {
    stepper_2.setSpeed(100);
    stepper_2.step(1); 
  }

  else if (y < 500)
  {
    stepper_2.setSpeed(100);
    stepper_2.step(-1); 
  }
  /*while (y > 523)
  {
    myservo.write(pos);
    pos += 1;
    delay(15);
    y = analogRead(VRY_PIN);
  }

  while (y < 500)
  {
    myservo.write(pos);
    pos -= 1;
    delay(15);
    y = analogRead(VRY_PIN);
  }*/

  // if the joystick is in the middle ===> stop the motor
  if(  (val > 500) && (val < 523) )
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
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
  }

  else
  {
    // move the motor in the first direction
    while (val >= 523)
    {
      // map the speed between 5 and 500 rpm
      //int speed_ = map(val, 523, 1023, 5, 500);
      speed_ = 100;
      // set motor speed
      stepper.setSpeed(speed_);

      // move the motor (1 step)
      if (steps_taken < max_steps)
      {
        stepper.step(1);
        steps_taken += 1;
      }
      else
      {
        Serial.println("Max positive steps reached");
      }
      val = analogRead(VRX_PIN);
    }

    // move the motor in the other direction
    while (val <= 500)
    {
      // map the speed between 5 and 500 rpm
      //int speed_ = map(val, 500, 0, 5, 500);
      speed_ = 100; 
      // set motor speed
      stepper.setSpeed(speed_);

      // move the motor (1 step)
      if (steps_taken > -max_steps)
      {
        stepper.step(-1);
        steps_taken -= 1;
      }
      else
      {
        Serial.println("Max negative steps reached");
      }

      val = analogRead(VRX_PIN);
    }

  }
  Serial.print("Step count: ");
  Serial.println(steps_taken);
  
}

