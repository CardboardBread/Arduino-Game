#ifndef GAMES_h
#define GAMES_h
#include "Arduino.h"


class GAMES
{
  public:
    GAMES();

    void tiler(int coltile[4]);
    void nodelaytiler(int x,int coltile[4], unsigned long previousMillis, unsigned long currentMillis);
    
    const int enable1   = 5;
    const int enable2   = 9;

};

#endif
