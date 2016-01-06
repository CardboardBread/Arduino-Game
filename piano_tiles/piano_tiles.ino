
#include "Arduino.h"
#include "Buttonscls.h"
#include "LEDs.h"
#include "GAMES.h"

//the goody two shoe program

const int channelA1 = 2;
const int channelB1 = 3;
const int channelC1 = 4;
const int enable1   = 5;

const int channelA2 = 6;
const int channelB2 = 7;
const int channelC2 = 8;
const int enable2   = 9;

int buttons[4]      = {A1, A2, 12, 13};
int Led, a, x       = 1;
int tilecolumn[4]   = {1, 2, 3, 4};

unsigned long previousMillis = 0;

LEDs ledarray            = LEDs();
Buttonscls pushbutton    = Buttonscls();
GAMES pianotiles         = GAMES();




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int x = 0; x < 10; x++) {
    pinMode(x, OUTPUT);
  }

  for (auto button : buttons) {
    pinMode(buttons[button], INPUT);
  }
  randomSeed(analogRead(A5));


}


void loop() {
  unsigned long currentMillis = micros();
  //if (x >= 4) {
  //x = ;
  //}
  /*
    pianotiles.tiler(tilecolumn);
    a = pushbutton.button_ON(x,tilecolumn);
    if (a + 1 == tilecolumn[3]) {
    Serial.println(a);
    shifter(tilecolumn);
    }
    x++;*/
  //pianotiles.nodelaytiler(x,tilecolumn,previousMillis,currentMillis);

  const long flickerspeed = (500);



  if (currentMillis - previousMillis  >= flickerspeed) {
    Serial.println(currentMillis) ;
    Serial.println(previousMillis) ;
    Serial.println(flickerspeed) ;
    Serial.println(x) ;

    Serial.println("----") ;

    previousMillis = currentMillis;

    switch (x) {
      case 1:
        x = 2;
        break;
      case 2:
        x = 3;
        break;
      case 3:
        x = 4;
        break;
      case 4:
        x = 1;
        break;
    }

    ledarray.LED_ON(tilecolumn[x - 1], x);
  }


}


void shifter(int tiles[4]) {
  tiles[3] = tiles[2];
  tiles[2] = tiles[1];
  tiles[1] = tiles[0];
  tiles[0] = random(1, 5);
}



