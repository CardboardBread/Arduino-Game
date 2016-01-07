#ifndef DATA_h
#define DATA_h
#include "EEPROM.h"

class DATA {
	public:
		DATA();
   
		void highCheck (int currentScore, int readAddress, int currentHigh);
		int loadHigh (int readAddress);
};

#endif

