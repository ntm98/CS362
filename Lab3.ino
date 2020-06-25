/*
Name: Nancy 

 Lab3: Scrolling Output

 Description: Setting up LCD screen for display, pentiometer to adjust brightness, 220 ohms resistor to restrict power, 
             arduino and bread board to build and connect circuits, and an algorithm that splits screen 
             into 16 columns and 2 rows to diaplay name on top and scrolling message at the bottom. Following is
             the detail description of connections made:
              
             LCD RS pin to digital pin 12
             LCD Enable pin to digital pin 11
             LCD D4 pin to digital pin 5
             LCD D5 pin to digital pin 4
             LCD D6 pin to digital pin 3
             LCD D7 pin to digital pin 2
             Vdd to 5V power
             Vss to ground
             V0 to pentiometer
             ground to pentiometer
Assumptions: Connections made shown above should connect the power and pins to LCD screen and 
             petiomenter, resulting in the display of the desired message.
Reference: UIC blackboard course link directed to arduino website that has generic instructions.
           https://www.arduino.cc/en/Tutorial/LiquidCrystalScroll
*/
#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5 ,4,3,2);

 int quoteSize = 0;
String fullName = "Nancy Tacuri", substring [16];

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16,2);
// lcd.print(fullName);
  
}

void loop(){
 scroll("Someday is not a day of the week."); 
 
}
void scroll(String quote){
quoteSize = quote.length();
quote = quote + " ";

 for (int i = 0; i <=quoteSize; i++){
 lcd.setCursor(2,0);  
 lcd.print(fullName);

 lcd.setCursor(0,1);
 lcd.print(quote.substring(i, 16+i));
 
  delay(400);
  }
  
  
  
}
