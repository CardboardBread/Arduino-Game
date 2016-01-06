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

void GAMES:: nodelaytiler(int x, int coltile[4], unsigned long previousMillis, unsigned long currentMillis) {
  LEDs ledarray = LEDs();
  const long flickerspeed = 1000;



  if (currentMillis - previousMillis  >= flickerspeed) {
    Serial.println(currentMillis) ;
    Serial.println(previousMillis) ;
    Serial.println(flickerspeed) ;

    Serial.println("----") ;

    previousMillis = currentMillis;

    if (x == 0) {
      ledarray.LED_ON(coltile[x], x + 1);
    }
    else if (x == 1) {
      ledarray.LED_ON(coltile[x], x + 1);
    }
    else if (x == 2) {
      ledarray.LED_ON(coltile[x], x + 1);
    }
    else {
      ledarray.LED_ON(coltile[x], x + 1);
    }

  }

}

