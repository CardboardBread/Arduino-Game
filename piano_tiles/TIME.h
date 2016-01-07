#ifndef TIME_h
#define TIME_h
#include "Arduino.h"

class TIME
{
	public:
		TIME();
		void flashLED(int ledChoice, int actionType);
		int timeElapsed = (int) millis;
};

#endif
