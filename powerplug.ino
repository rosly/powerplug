/*
Released under Creative Commons Attribution 4.0
by bitluni 2016
https://creativecommons.org/licenses/by/4.0/
Attribution means you can use it however you like as long you
mention that it's base on my stuff.
I'll be pleased if you'd do it by sharing http://youtube.com/bitlunislab
*/

#include "RF.h"

const int RF_OUT = 2; //PIN for amplitude modulation

const int BIT_LEN_US = 999; //Length of bit in us

const char *on_string  = "0000000000000000000000000";
const char *off_string = "0000000000000000000000000";

#define TXSPEED 115200

void setup() 
{
  pinMode(RF_OUT, OUTPUT);
  Serial.begin(TXSPEED);
}

void loop() 
{
  int i;

  Serial.println("On");
  for (i = 0; i < 4; i++) {
    rfWriteString(RF_OUT, BIT_LEN_US, on_string, true);
    delayMicroseconds(BIT_LEN_US * 8);
  }

  delay(3000);

  Serial.println("Off");
  for (i = 0; i < 4; i++) {
    rfWriteString(RF_OUT, BIT_LEN_US, off_string, true);
    delayMicroseconds(BIT_LEN_US * 8);
  }
  
  delay(3000);
}
