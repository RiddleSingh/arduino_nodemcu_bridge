/***************************************************************************
 * Created by: Bhagath Cheela, 2021-12-03
  All instructions are on the github repo. https://github.com/ese-detkin-lab/
 ***************************************************************************/
#include <Wire.h>

/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"

// Adafruit Feeds
AdafruitIO_Feed *pulse = io.feed("pulse");


void setup() {
 Serial.begin(9600); /* begin serial for debug */
 Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */

 // connect to io.adafruit.com
 io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
    
  // we are connected
  Serial.println();
  Serial.println(io.statusText());
}

void loop() {
 // io.run(); is required for all sketches.
 // it should always be present at the top of your loop
 // function. it keeps the client connected to
 // io.adafruit.com, and processes any incoming data.
 io.run();

 //Uncomment this to send some information to Arduino
 /*
 Wire.beginTransmission(8); // begin with device address 8 
 Wire.write("Hello Arduino");  // sends hello string 
 Wire.endTransmission();    // stop transmitting
 */
 Wire.requestFrom(8, 1); /* request & read data of size 13 from Node MCU */
 while(Wire.available()){
    int in_pulse = Wire.read();
     //Send the received data to cloud
    pulse->save(in_pulse);
    Serial.print(in_pulse);
    delay(2000);
 }
 
 Serial.println();
 delay(1000);
}
