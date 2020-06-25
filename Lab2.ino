/*
* Nancy
* Lab2 - Set up a push button and LED 
*
* This lab is about pressing a button, it should read values
* The pussh buttons will change an internal "3-bit count" 
* The LED's will discplaty the value of this inter "3-bit-count"
* 
* References - https://www.arduino.cc/en/Tutorial/Button
*            - http://www.ladyada.net/learn/arduino/lesson5.html
*               
*/

const int decButtonPin = 2;
const int incButtonPin = 4;

const int bits = 3;
int ledPins[bits] = {7, 8, 12};

int incButtonState = 0;
int decButtonState = 0;
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(incButtonPin, INPUT);
  pinMode(decButtonPin, INPUT);

  pinMode(13, OUTPUT);

  pinMode(ledPins[0], OUTPUT);
  pinMode(ledPins[1], OUTPUT);
  pinMode(ledPins[2], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Read the increment button
  incButtonState = digitalRead(incButtonPin);
  if(incButtonState == HIGH){
    digitalWrite(13, HIGH);

    //Increment the counter
    counter = (counter + 1) % 8;
    
    //Wait for the button to be released
    while(digitalRead(incButtonPin) == HIGH) { }
  }
  else{    
    digitalWrite(13, LOW);
  }
  
  //Read the decrement button
  decButtonState = digitalRead(decButtonPin);
  if(decButtonState == HIGH){
    digitalWrite(13, HIGH);
    
    //Decrement the counter
    counter = (counter - 1) % 8;
    
    //Wait for the button to be released
    while(digitalRead(decButtonPin) == HIGH) { }
  }
  else{    
    digitalWrite(13, LOW);
  }
  
  //Convert the counter to LED binary
  int i = 0; //LED index
  int pos = 1; //Bit position to read
  for(i = 0; i < bits; i++){
     if(counter & pos){ //Checking the bit of counter with pos
        digitalWrite(ledPins[i], HIGH);
     }
     else{
        digitalWrite(ledPins[i], LOW);
     }
     //Shift the masking bit to the left to read the next bit
     pos = pos << 1;
  }
  
  //Pause to eliminate jittery presses
  delay(100);
}
