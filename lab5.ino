/*
* Nancy    
*
* Lab5- Multiple inputs and outputs.  
* 
* 
* This lab is expecting LEDs on pin 13, 11, 10.
* This code sets pins 13, 11, 10 as aoutput.
* It turn on, wait, turn off, waits the pin 3 
* 
* Asumptions - I have no assumptions.
* 
* References - https://www.arduino.cc/en/Tutorial/Blink 
• https://www.arduino.cc/en/Reference/AnalogWrite
• https://www.arduino.cc/en/Reference/Map
• https://www.arduino.cc/en/Reference/AnalogRead
• https://create.arduino.cc/projecthub/SURYATEJA/use-a-buzzer-module-piezo-speakerusing-arduino-uno-89df45
• https://www.arduino.cc/en/Tutorial/toneMelody
• https://www.arduino.cc/en/tutorial/potentiometer
*               
*               
*               
*/
const int pResistor = A0, potentiometer = A2;
const int led1 = 12;
const int led2 = 11;
const int led3 = 10;
const int led4 = 8;
int buzzer = 9; //where the wire will be connected
int potentiometerValue = 0; 
void setup() 
{ 
  Serial.begin(9600);
  pinMode(pResistor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}
void loop() 
{ 
  potentiometerValue = analogRead(potentiometer); //reads the values fron the potentiometer
  tone(buzzer,potentiometerValue);// reads the buzzer tone
  displayBrightness(analogRead(pResistor)); // i called this function to read the resistor 
  delay (1);  
}


//this function is gonna change the lights
void displayBrightness(int value) 
{ 

  // this statement means that the light shoul be lit 
  if (value <= 200) 
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
  
  // this statement means that the light shoul be light 
  else if (value <= 400) 
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }

  
  // this statement means that the light shoul be medium 
  else if (value <= 600) 
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  
  // this statement means that the light shoul be medium
  else if (value <= 800)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  
  // this statement means that the light shoul be dark 
  else
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
}
