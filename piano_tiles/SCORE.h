#ifndef SCORE_h
#define SCORE_h
#include "Arduino.h"


class SCORE
{
	public:
		SCORE();
		
		void printScore();
		
		int scoreA = 0;
		int scoreB = 0;
		int scoreC = 0;
		int playerScore = 0;
		int tempScore = 0;
    
};

#endif
