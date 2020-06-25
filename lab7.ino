
// Lab 7
// Description - turn on the LED of another arduino by pressing a button
// Assumptions - We thought arduinos needed separate code for the buttons but we eneded up just using the same code
// References - Used the tutorial links used in the writeup for the lab


// variables for the lab
const int ledPin = 12;
const int switchPin = 10;
int buttonState;

// messages to hold
byte message = 0;

void setup() {

  Serial.begin(9600);
  
  // set the pin for the LED
  pinMode(ledPin, OUTPUT);

  // set the pin for the switch
  pinMode(switchPin, INPUT);

  // keep track of state of button
  buttonState = digitalRead(switchPin);
}

void loop() {

  // read input value
  int val = digitalRead(switchPin);
  delay(10);
  int val2 = digitalRead(switchPin);

  // check if signal is the same
  if(val == val2) {

    // check if button state has changed
    if(val != buttonState) {

      // if button is pressed
      if(val == LOW) {

        // if other arduino LED is off
        if(message == 0) {
          
          // send value to other arduino to turn on LED
          message = 1;
          Serial.write(message);
        }
        else {

          // send value to other arduino to turn off LED
          message = 0;
          Serial.write(message);
        }
      }
    }
    buttonState = val;
  }

  if(Serial.available()) {
    
    // read in message
    byte receive = Serial.read();
  
    // check message from other arduino
    if(receive == 1) {
      digitalWrite(ledPin, HIGH);
    }
    else {
      digitalWrite(ledPin, LOW);
    }
  }
}
