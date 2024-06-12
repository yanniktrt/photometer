const int ldr=A5;
 int ldrwert;

int led=13;

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
 Serial.begin (9600);
 
 pinMode(led,OUTPUT);
 
}


void loop()
{

  digitalWrite (led,HIGH);

  ldrwert=analogRead(ldr);
  Serial.println (ldrwert);
  
  float voltwert=ldrwert*(5.0 / 1023.0);
 
  lcd.init();                      
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print(voltwert);
  lcd.print(" Volt");
 
}
