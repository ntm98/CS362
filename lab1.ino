/*
* Nancy  
*
* Lab1 - Get started with Arduino
*
* This lab is expecting LEDs on pin 13, 11, 10.
* This code sets pins 13, 11, 10 as aoutput.
* It turn on, wait, turn off, waits the pin 3 
* References - https://www.arduino.cc/en/Tutorial/Blink
*               
*/

int redPin = 8;
int greenPin = 12;
int bluePin =11;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  digitalWrite(redPin, HIGH);   
  delay(500); 
  digitalWrite(redPin, LOW);  
  delay(500); 
  
  digitalWrite(greenPin, HIGH);
  delay(500); 
  digitalWrite(greenPin, LOW);
  delay(500); 
  
  digitalWrite(bluePin, HIGH);
  delay(500);   
  digitalWrite(bluePin, LOW);
  delay(500);                       // wait for a second
}
