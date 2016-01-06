#include "Arduino.h"
#include "DATA.h"
#include "EEPROM.h"

DATA::DATA()
{
	
}

void highCheck (int currentScore, int readAddress) {
	byte highScore = EEPROM.read(readAddress);
	
	if (currentScore > highScore) {
		Serial.println("Player Score is higher than current High Score.");
		highScore = currentScore;
		EEPROM.update(readAddress, currentScore);
		Serial.println("Player Score written to save data.");
	} else {
		Serial.println("The player's score is less than the High Score!");
	}
	
}
