/***************************************************************************
 * Created by: Bhagath Cheela, 2021-12-03
  All instructions are on the github repo. https://github.com/ese-detkin-lab/
 ***************************************************************************/
#include <Wire.h>

//  Variables
int PulseSensorPurplePin = 0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED13 = 13;   //  The on-board Arduion LED


int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 550;            // Determine which Signal to "count as a beat", and which to ingore.


void setup() {
 pinMode(LED13,OUTPUT);         // pin that will blink to your heartbeat!
 Wire.begin(8);                 // join i2c bus with address 8 
 //Wire.onReceive(receiveEvent); // register receive event 
 Wire.onRequest(requestEvent); // register request event
 Serial.begin(9600);           // start serial for debug
}

void loop() {

 Signal = analogRead(PulseSensorPurplePin);  // Read the PulseSensor's value.
                                              // Assign this value to the "Signal" variable.

   Serial.println(Signal);                    // Send the Signal value to Serial Plotter.


   if(Signal > Threshold){                    // If the signal is above "550", then "turn-on" Arduino's on-Board LED.
     digitalWrite(LED13,HIGH);
   } else {
     digitalWrite(LED13,LOW);                 //  Else, the sigal must be below "550", so "turn-off" this LED.
   }

 delay(100);
}

/* Uncomment if you wish to receive data from Arduino
// function that executes whenever data is received from master
void receiveEvent(int howMany) {
 while (0 <Wire.available()) {
    char c = Wire.read();      // receive byte as a character
    Serial.print(c);           // print the character
  }
 Serial.println();             // to newline
}
*/

// function that executes whenever data is requested from master
void requestEvent() {
// Wire.write("Hello NodeMCU");  /*send string on request */
 Wire.write(Signal);  /*send string on request */
}
