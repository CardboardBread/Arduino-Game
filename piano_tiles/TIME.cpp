#include "TIME.h"

TIME::TIME()
{
  
}

void TIME::flashLED(int port, int actionType)
{
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
