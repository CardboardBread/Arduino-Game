#include "Arduino.h"
#include "TIME.h"

TIME::TIME()
{
  
}

void TIME::flashLED()
{
    if (port = 1) {
		ledChoice = A3;  
    } else if (port = 2) {
		ledChoice = A4;
    } else if (port = 3) {
		ledChoice = A5;
    }
    if (actionType = 1) {
		if ((millisInt > 500) == true) {
			digitalWrite(port, HIGH);  
		}
		else if ((millisInt / 700) == true) {
			digitalWrite(port, LOW);
		}
    } else if (actionType = 2) {
		digitalWrite(port, HIGH);
    }
}
