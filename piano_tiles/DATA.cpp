#include "Arduino.h"
#include "DATA.h"
#include "EEPROM.h"

DATA::DATA()
{
	
}

void DATA:: highCheck (int currentScore, int readAddress, int currentHigh) {
	
	if (currentScore > currentHigh) {
		Serial.println("Player Score is higher than current High Score");
		Serial.println(currentScore);
		currentHigh = byte(currentScore);
		EEPROM.update(readAddress, byte(currentScore));
		Serial.println("Player Score written to save data");
	} else if (currentScore == currentHigh) {
		Serial.println("Player score equal to high");
		Serial.println(currentScore);
	} else {
		Serial.println("Player score less than high");
		Serial.println(currentScore);
	}
	
}

int DATA:: loadHigh (int readAddress) {
	return int(EEPROM.read(readAddress));
}
