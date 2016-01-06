#include "Arduino.h"
#include "SCORE.h"


SCORE::SCORE()
{
	
}

void SCORE::printScore()
{
	playerScore = playerScore + 1;
	tempScore = playerScore;
	scoreA = tempScore % 2;
	tempScore = tempScore / 2;
	scoreB = tempScore % 2;
	tempScore = tempScore / 2;
	scoreC = tempScore % 2;
	
	digitalWrite(A3, scoreA);
	digitalWrite(A4, scoreB);
	digitalWrite(A5, scoreC);     
}
