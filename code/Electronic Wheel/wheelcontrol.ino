int speed = 0;
bool brake = 0;
int x = 0;
int y = 0;

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
  speed = 10 ;

  if (y < 400){
    digitalWrite(7, LOW);
    digitalWrite(4, LOW);
    analogWrite(9, speed);
  }

  else if (y > 600){
    digitalWrite(7, LOW);
    digitalWrite(4, HIGH);
    analogWrite(9, speed);
  }

  else {
    digitalWrite(7, HIGH);
  }


}
