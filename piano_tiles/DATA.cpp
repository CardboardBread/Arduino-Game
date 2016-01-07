#include "Arduino.h"
#include "DATA.h"
#include "EEPROM.h"

DATA::DATA()
{
	
}

void DATA:: highCheck (int currentScore, int readAddress) {
	byte highScore = EEPROM.read(readAddress);
	
	if (currentScore > int(highScore)) {
		Serial.println("Player Score is higher than current High Score.");
		highScore = byte(currentScore);
		EEPROM.update(readAddress, byte(currentScore));
		Serial.println("Player Score written to save data.");
	} else {
		Serial.println("The player's score is less than the High Score.");
	}
	
}
