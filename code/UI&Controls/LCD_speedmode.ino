/*#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x26, 20, 4); // I2C address ??? , 16 column and 4 rows

void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();
  lcd.print("test");
}

void loop()
{
  lcd.clear();                 // clear display
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)  column, row
  lcd.print("Arduino");        // print message at (0, 0)
  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  lcd.print("Test");            // print message at (2, 1)
  delay(2000);                 // display the above for two seconds
}
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x26, 20, 4); 
const int buttonpin = 2;
int buttonstate = 0;
int systemON = 0;
int presscount = 0;
//string mode;
unsigned long startmillis, currentmillis, time;

void setup()
{

  // initialize the LCD
	lcd.init();
	lcd.backlight();
  Serial.begin(9600);
  pinMode(buttonpin, INPUT); //initialize input button
  startmillis = millis();
}
void loop()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    buttonstate = digitalRead(buttonpin);
    currentmillis = millis();

    Serial.println(buttonstate);
    
    if (buttonstate){
      systemON = !systemON;
      presscount = (presscount == 2) ? 0 : presscount + 1;
      startmillis = currentmillis;
    }

    time = (currentmillis - startmillis)/6000; //time since mode has been switched
    if (presscount == 1){
      LCD("ON", "SLOW", time);
    }

    else if (presscount == 2){
      LCD("ON", "FAST", time);
    }

    else{
      lcd.print("System Status: OFF");
    }

    delay(1000);
}

void LCD(String STATUS, String MODE, unsigned long TIME)
{
  lcd.print("System Status: ");
  lcd.print(STATUS);
  lcd.setCursor(0,2);
  lcd.print("Mode:");
  lcd.setCursor(12,2);
  lcd.print("Op Time:");
  lcd.setCursor(0, 3);
  lcd.print(MODE);
  lcd.setCursor(12,3);
  lcd.print(time);
  lcd.print(" min");
}








