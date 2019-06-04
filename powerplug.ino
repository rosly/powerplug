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

const char *on_short   = "1011111110101100010111000";
const char *off_short  = "1011001101101000100011000";

const char *ir_arm = "0100011000011001100000010";
const char *ir_dis = "0100011000011001100000100";


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
    rfWriteString(RF_OUT, 382, on_short, true);
    delayMicroseconds(382 * 8);
  }

  delay(3000);

  Serial.println("Off");

  for (i = 0; i < 4; i++) {
    rfWriteString(RF_OUT, 382, off_short, true);
    delayMicroseconds(382 * 8);
  }
  
  delay(3000);

  Serial.println("IrArm");
  for (i = 0; i < 10; i++) {
    rfWriteString(RF_OUT, 445, ir_arm, false);
    delayMicroseconds(445 * 32);
  }

  delay(3000);

  Serial.println("IrDisarm");
  for (i = 0; i < 10; i++) {
    rfWriteString(RF_OUT, 445, ir_dis, false);
    delayMicroseconds(445 * 32);
  }

  delay(3000);
}
