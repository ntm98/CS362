/*
Name: Nancy 

 Lab9: Graphic sensor data on a PC. 

  Description: Connect two analog devices to the Arduino and plot 
  the data received on the computer using the
  Processing software.
  Data could be displayed in two separate graphs or both on one graph.



  Assumption: no assumptions

  References: the Processing Software to display Arduino information
https://www.processing.org/download/?processing
https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing#introduction
https://www.arduino.cc/en/Tutorial/Graph
*/


import processing.serial.*;

  Serial myPort;        // The serial port
  int xPos = 1;         // horizontal position of the graph
  float inByte = 0;

  void setup () {
    // set the window size:
    size(800, 600);

    // List all the available serial ports
    println(Serial.list());

  
   
    // Open whatever port is the one you're using.
    myPort = new Serial(this, Serial.list()[0], 9600);

    // don't generate a serialEvent() unless you get a newline character:
    myPort.bufferUntil('\n');

    // set initial background:
    background(0);
  }

  void draw () {
    // draw the line:
    stroke(127, 34, 255);
    line(xPos, height, xPos, height - inByte);

    // at the edge of the screen, go back to the beginning:
    if (xPos >= width) {
      xPos = 0;
      background(0);
    } else {
      // increment the horizontal position:
      xPos++;
    }
  }

  void serialEvent (Serial myPort) {
    // get the ASCII string:
    String inString = myPort.readStringUntil('\n');

    if (inString != null) {
      // trim off any whitespace:
      inString = trim(inString);
      // convert to an int and map to the screen height:
      inByte = float(inString);
      println(inByte);
      inByte = map(inByte, 0, 1023, 0, height);
    }
  }
