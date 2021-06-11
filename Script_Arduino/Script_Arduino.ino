#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2);

int motorpin1 = 2;
int motorpin2 = 3;

int highSensor = 4;
int lowSensor = 5;
void setup() 
{
  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);

  pinMode(highSensor, INPUT);
  pinMode(lowSensor, INPUT);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hola :D ");
  lcd.setCursor(0, 1);
  lcd.print("Team Amarrilo - SP");
}

void loop() 
{

} 

void clearDisplay(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hola :D ");
  lcd.setCursor(0, 1);
  lcd.print("Team Amarrilo - SP");
}
void setMessage(String m1, String m2){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(m1);
  lcd.setCursor(0, 1);
  lcd.print(m2);
}

void openDoor(){
  int valsensor = 1;
  while(valsensor != 0){
  valsensor = digitalRead(highsensor);
  digitalWrite(motorpin1, HIGH);
  digitalWrite(motorpin2, LOW);
  }
  delay(100);
}

void closeDoor(){
  int valsensor = 1;
  while(valsensor != 0){
  valsensor = digitalRead(highsensor);
  digitalWrite(motorpin1, LOW);
  digitalWrite(motorpin2, HIGH);
  }
  delay(100);
}