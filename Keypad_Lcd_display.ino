#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int i=0;

const char rows = 4;
const char columns = 4;

char row_pins[rows] = {2, 3, 4, 5};
char columns_pins[columns] = {6, 7, 8, 9};

char array[rows][columns] = { 

  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
  };

Keypad k = Keypad(makeKeymap(array),row_pins , columns_pins, rows, columns);

void setup() {
 Serial.begin(9600);
 lcd.init();
 lcd.backlight();
}

void loop() {
 char key_pressed = k.getKey();
if(key_pressed)
{
  Serial.println(key_pressed);
  lcd.setCursor(i, 0);
  lcd.print(key_pressed);
  i=i+1;
}

}
