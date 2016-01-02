#include "Buttonscls.h"
#include "LEDs.h"
#include "GAMES.h"
#include "Arduino.h"

GAMES::GAMES()
{

}

void GAMES:: tiler(int coltile[4]) {
  LEDs ledarray = LEDs();
  int flickerspeed = 1;
  
  digitalWrite (enable1, HIGH);
  digitalWrite (enable2, HIGH);
  
  ledarray.LED_ON(coltile[0], 1);
  delay(flickerspeed);
  ledarray.LED_ON(coltile[1], 2);
  delay(flickerspeed);
  ledarray.LED_ON(coltile[2], 3);
  delay(flickerspeed);
  ledarray.LED_ON(coltile[3], 4);
  delay(flickerspeed);

}
