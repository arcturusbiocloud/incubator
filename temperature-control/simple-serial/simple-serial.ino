/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  
  // serial setup
  Serial.begin(9600); 
  Serial.println("Arcturus Incubator and lights controller connected");
  Serial.setTimeout(25);
}

// the loop function runs over and over again forever
void loop() {
  char buffer[64];
  size_t length = 64;
   
  length = Serial.readBytes(buffer, length);
  
  // Send back the value read
  // read an input pin
  if (length > 0) {
    Serial.write((uint8_t*)buffer, length);
  }
}
