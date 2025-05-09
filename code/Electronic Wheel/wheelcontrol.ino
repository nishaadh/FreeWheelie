int speed = 0;
bool brake = 0;
int x = 0;
int y = 0;

const int buttonpin = 2;
int buttonstate = 0;
int presscount = 0;
int speed1 = 5;
int speed2 = 50 ;

int lastButtonState = LOW;   
unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9, OUTPUT); //speed
  pinMode(4,OUTPUT); //direction
  pinMode(7, OUTPUT); //brake
  pinMode(A4, INPUT); //RY
  pinMode(A5, INPUT);  //RX
}

void loop() {
  // put your main code here, to run repeatedly:

  y = analogRead(A4);
  x = analogRead(A5);
;
  int b_read = digitalRead(buttonpin);

  // If the button state has changed
  if (b_read != lastButtonState) {
    lastDebounceTime = millis();  // Reset the debounce timer
  }

  // If the state has been stable longer than debounceDelay
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (b_read != buttonstate) {
      buttonstate = b_read;

      // Only toggle the LED when the new state is HIGH (button pressed)
      if (buttonstate == HIGH) {
        presscount = (presscount == 2) ? 0 : presscount + 1;
      }
    }
  }

  lastButtonState = b_read;

  //if (buttonstate){
  //    presscount = (presscount == 2) ? 0 : presscount + 1;
  //  }

  if (y < 400){
    digitalWrite(7, LOW);
    digitalWrite(4, LOW);
    if (presscount == 0)
    {
      digitalWrite(7, HIGH);
    }
    else if (presscount == 1){
      analogWrite(9, speed1);
    }
    else if (presscount == 2){
      analogWrite(9, speed2);
    }
  }

  else if (y > 600){
    digitalWrite(7, LOW);
    digitalWrite(4, HIGH);
    if (presscount == 0)
    {
      digitalWrite(7, HIGH);
    }
    else if (presscount == 1){
      analogWrite(9, speed1);
    }
    else if (presscount == 2){
      analogWrite(9, speed2);
    }
  }

  else {
    digitalWrite(7, HIGH);
  }

  Serial.println(presscount);


}
