#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);   /* Задаем адрес и размерность дисплея. 
При использовании LCD I2C модуля с дисплеем 20х04 ничего в коде изменять не требуется, cледует только задать правильную размерность */

void setup()
{
  // set up the LCD's number of columns and rows: 
  lcd.begin(); 
  // Print a message to the LCD. 
  // first digit is a column, second is a row
  lcd.setCursor(0,0); 
  lcd.print("LCD Key Shield"); 
  lcd.setCursor(0,1); 
  lcd.print("Press Key:"); 
}

void loop()
{
}
