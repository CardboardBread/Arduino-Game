#include "TIME.h"

TIME::TIME()
{
  
}

void TIME::flashLED(int ledChoice, int actionType)
{
	int port;
	if (ledChoice = 1) {
		port = A3;
	} else if (ledChoice = 2) {
		port = A4;
	} else if (ledChoice = 3) {
		port = A5;
	}
	
	if (actionType = 1) {
		if ((timeElapsed / 500) == true) {
			digitalWrite(port, HIGH);
		} else if ((timeElapsed / 700) == true) {
			digitalWrite(port, LOW);
		}
	} else if (actionType = 2) {
		digitalWrite(port, HIGH);
	} else if (actionType = 3) {
		digitalWrite(port, LOW);
	}
}
