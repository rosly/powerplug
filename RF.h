/*
Released under Creative Commons Attribution 4.0
by bitluni 2016
https://creativecommons.org/licenses/by/4.0/
Attribution means you can use it however you like as long you
mention that it's base on my stuff.
I'll be pleased if you'd do it by sharing http://youtube.com/bitlunislab
*/

//Works with BH9938 with t=200

inline void rfPreamble(int pin, int t)
{
	digitalWrite(pin, 1);
	delayMicroseconds(t);
	digitalWrite(pin, 0);
	delayMicroseconds(t * 6);
}

inline void rfWriteBit(int pin, int t, int b)
{
	if(b)
	{
		digitalWrite(pin, 1);
		delayMicroseconds(t * 3);
		digitalWrite(pin, 0);
		delayMicroseconds(t);
	}
	else
	{
		digitalWrite(pin, 1);
		delayMicroseconds(t);
		digitalWrite(pin, 0);
		delayMicroseconds(t * 3);
	}
}

void rfWriteCode(int pin, int t, int code, int data)
{
	rfPreamble(pin, t);
	for(int i = 0; i < 20; i++)
	{
		rfWriteBit(pin, t, code & 1);
		code >>= 1;
	}
	for(int i = 0; i < 4; i++)
	{
		rfWriteBit(pin, t, data & 1);
		data >>= 1;
	}
}

void rfWriteString(int pin, int t, const char *code, bool pream)
{
  int len = strlen(code);
  
  if (pream)
    rfPreamble(pin, t);
    
  for(int i = 0; i < len; i++)
  {
    rfWriteBit(pin, t, code[i] == '1' ? 1 : 0);
  }
}
