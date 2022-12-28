/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground through 220 ohm resistor

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInOutSerial
*/

// These constants won't change. They're used to give names to the pins used:
//const int analogInPin ;  // Analog input pin that the potentiometer is attached to
const int analogOutPin =A0; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 500;        // value output to  (analog out) 

void setup() {
  // initialize serial communications at 9600 bps:
  SerialUSB.begin(9600);
}

void loop() {
 analogWriteResolution(10);   //for M0 0-1023
 //analogWriteResolution(12);// for DUE 0- 4095
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  //Serial.print("sensor = ");
  //delay(500);
  //Serial.print(sensorValue);
  SerialUSB.print("\t output = ");
  delay(500);
  SerialUSB.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2000);
  outputValue=outputValue + 2;
  if (outputValue >= 1023)outputValue=500;
}
