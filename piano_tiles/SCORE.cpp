#include "SCORE.h"

SCORE::SCORE()
{
  
}

void SCORE:: printScore (int score)
{
	for (int x = 0; x < score / 10; x++) {
		digitalWrite(A4, HIGH);
		delay(250);
		digitalWrite(A4, LOW);
		delay(250);
		Serial.println(x);
	}
	delay(150);
	for (int x = 0; x < score - (round(score / 10) * 10); x++) {
		digitalWrite(A5, HIGH);
		delay(250);
		digitalWrite(A5, LOW);
		delay(250);
		Serial.println(x);
	}
}
