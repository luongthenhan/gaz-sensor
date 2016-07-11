/*-----( Import needed libraries )-----*/
#include <Wire.h>  // Comes with Arduino IDE
// Get the LCD I2C Library here: 
// www.4tronix.co.uk/arduino/sketches/LiquidCrystal_V1.2.1.zip
// Move any other LCD libraries to another folder or delete them
// See Library "Docs" folder for possible commands etc.
#include <LiquidCrystal_I2C.h>

/*-----( Declare Constants )-----*/
const int buzzer = 9; //buzzer to arduino pin 9
const int analogPin = A0;

/*-----( Declare objects )-----*/
// set the LCD address to 0x27 for a 16 chars 2 line display
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

/*-----( Declare Variables )-----*/
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  analogWrite(buzzer, 255);
  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight
  lcd.backlight(); // finish with backlight on
  lcd.setCursor(0, 0); //Start at character 0 on line 0
  lcd.print("Hello!");
  lcd.setCursor(0, 1); //Start at character 0 on line 1
  lcd.print("Setup ...");
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin);
  lcd.clear();
  lcd.setCursor(0, 0);
  if (val > 200) {
    lcd.print("NGUY HIEM !!!");
    analogWrite(buzzer, 0);
  } else {
    lcd.print("Gaz Index:");
    analogWrite(buzzer, 255);
  }
  lcd.setCursor(0, 1);
  lcd.print(val);
  delay(1000);    
}
