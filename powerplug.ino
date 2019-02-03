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

const char *on_short  = "1011000110111010101011000";
const char *off_short = "1011111011100001001011000";
const char *on_long  = "011011111011001001101000110100110";
const char *off_long = "011111110011010001101101100100110";

const char *ir_arm = "0100011000011001100000010";
const char *ir_dis = "0100011000011001100000100";


#define TXSPEED 115200

/* Use short code for powerplug */
#define SHORT_CODE
/* Use power plug */
#define POWER_PLUG

void setup() 
{
  pinMode(RF_OUT, OUTPUT);
  Serial.begin(TXSPEED);
}

void loop() 
{
  int i;

#ifdef POWER_PLUG
  Serial.println("On");
#ifdef SHORT_CODE
  for (i = 0; i < 4; i++) {
    rfWriteString(RF_OUT, 382, on_short, true);
    delayMicroseconds(382 * 8);
  }
#else
  for (i = 0; i < 4; i++) {
    rfWriteString(RF_OUT, 510, on_long, false);
    delayMicroseconds(510 * 8);
  }
#endif

  delay(3000);

  Serial.println("Off");
#ifdef SHORT_CODE
  for (i = 0; i < 4; i++) {
    rfWriteString(RF_OUT, 382, off_short, true);
    delayMicroseconds(382 * 8);
  }
#else
  for (i = 0; i < 4; i++) {
    rfWriteString(RF_OUT, 510, off_long, false);
    delayMicroseconds(510 * 8);
  }
#endif
#endif
  
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
