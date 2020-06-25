/*
Name: Nancy 

 Lab4: Convert analog sensor input to digital inforamtion.

 Description:
              We have to incorporate the light sensitive photocell
              and display revelant information about the photcell
              value onto 16x2 dispaly 
 Assumption:   Photo resistor can be placed in any direction. WRONG must have a set direction and reading must
//             Be read from analog pins
//             Strings work very similarly to that of C codes which is true.
 
 References:
            https://www.instructables.com/id/How-to-use-a-photoresistor-or-photocell-Arduino-Tu/
            https://www.arduino.cc/reference/en/language/functions/communication/serial/print/  
            https://playground.arduino.cc/Learning/PhotoResistor/

* Simple test of the functionality of the photo resistor
Connect the photoresistor one leg to pin 0, and pin to +5V
Connect a resistor (around 10k is a good value, higher
values gives higher readings) from pin 0 to GND. (see appendix of arduino notebook page 37 for schematics).
----------------------------------------------------
           PhotoR     10K
 +5    o---/\/\/--.--/\/\/---o GND
                  |
 Pin 0 o-----------
----------------------------------------------------
*/
#include <LiquidCrystal.h>
#include <stdio.h>

//int lightPin = A0;  //define a pin for Photo resistor

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int ledPin =9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


int pResistor = A0;
int value;


void setup(){
// pinMode(ledPin, OUTPUT);  // Set lepPin - 9 pin as an output
// pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
 lcd.begin(16,2);
 Serial.begin(9600);

}

void loop(){
  value = analogRead(pResistor);
  lcd.setCursor(0,0);
  Serial.println(value);
  //You can change value "25"
  if (value <= 300){
        lcd.print("dark");
        //digitalWrite(ledPin,LOW);
  }
  else if (value <= 400){
        lcd.print("partially dark");
    
  }
  else if (value <= 500){
        lcd.print("medium");
    
  }
  else if (value <= 600){
        lcd.print("partially light");
    
  }
  else if (value <= 800){
        lcd.print("fully lit");
    
  }
  else{
      lcd.print("fully lit");    
    }
  
  delay(250); //Small delay
  lcd.clear();
}
