#ifndef GAMES_h
#define GAMES_h
#include "Arduino.h"


class GAMES {
  public:
    GAMES();

    void tiler(int coltile[4]);
    
    const int enable1   = 5;
    const int enable2   = 9;


};

#endif
