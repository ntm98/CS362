/*
Name: Nancy 

 Lab3: Scrolling Output

 Description: This lab is combine two interruots and one LCD display,
              it wil show a real time, but when the button is pressed it has 
              to stop and show a mesage to display and wait for the second button  
              
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
Assumptions: No assumptions
Reference: UIC blackboard course link directed to arduino website that has generic instructions.
           https://www.arduino.cc/en/Tutorial/LiquidCrystalScroll

*/

#include <LiquidCrystal.h>
#include <TimeLib.h>


/*intialiize the library by associating any needed LCD interface qith the arduino pin number*/
const int rs =12, en =11, d4 = 8, d5 = 7, d6 = 6, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// variables will change:

const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  12;      // the number of the LED pin
const int buttonPin2 = 3;   // the number o the interruptor

int buttonState = 2;         // variable for reading the pushbutton status
//const int buttonState2 = 0; // variable for reading the second interuptor 
time_t start;
time_t secnds;

time_t elapsed(){
  time_t e = now()-start;
  Serial.print("We have been waiting for ");
  Serial.print(e);
  Serial.println(" seconds");
  return e;
}

/*sets up the time to a real time*/
void updateTime(){
  start = now();  
}
/*this function will read when button was pressed*/
boolean buttonPressed(int button){
  boolean pressed = false;
  if (digitalRead(button)){
    while(digitalRead(button)){}
    pressed = true;
      }
    return pressed;
}
/*this function displays the message and seconds in the LCD*/
void button2(){
  buttonState = 2;
}

/*this function does the same that button 2*/
void button1(){
  buttonState = 1;
 

  //Serial.println("Interrupt received! Press button 2 to continue");
}
  /*it will wait until the button2 is pressed*/
  void waitButton(){
    if (buttonState == 2){
      while(!digitalRead(buttonPin)){
        button2();
      }
      button1();
    }
}


/*read when the button is interrupted*/
void interruptMode(){
  if(buttonState ==1){
    while(!buttonPressed(buttonPin2)){}//wait for button 2
    updateTime();
    button2();
  }
}

void setup() {
  // initialize the LED pin as an output:
 // pinMode(ledPin, LOW);
//  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("We have been waiting for ");
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), button1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buttonPin2), button2, CHANGE); 
  updateTime();
  delay(500);
}

void loop() {
  //waitButton();
  // read the state of the pushbutton value:
 // buttonState = digitalRead(buttonPin);
 // buttonState2 = digitalRead(buttonPin2);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  //interruptMode();
  /*if (buttonState == LOW) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else if(buttonState2 == HIGH){
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }*/
  if(buttonState == 2){
  time_t e = elapsed();
  if(e != secnds){
    secnds = e;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Waiting for");
    lcd.setCursor(0,1);
    lcd.print(e);
    lcd.print("seconds");
    
    }
  
  }
  if (buttonState == 1){
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Interrupt received!");
  lcd.setCursor(0,1);
  lcd.print("Press button 2 to continue");
    updateTime();
}
}
