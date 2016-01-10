#include "Arduino.h"
#include "Buttonscls.h"
#include "LEDs.h"
#include "GAMES.h"
#include "SCORE.h"
#include "DATA.h"
#include "EEPROM.h"

//the goody two shoe program
const int channelA1 	= 2;
const int channelB1 	= 3;
const int channelC1 	= 4;
const int enable1   	= 5;

const int channelA2 	= 6;
const int channelB2 	= 7;
const int channelC2	 	= 8;
const int enable2   	= 9;

int buttons[4]      	= {A1, A2, 12, 13};
int Led, a, x        	= 0;
int tilecolumn[4]    	= {1, 2, 3, 4};

unsigned long limit;
unsigned long starttime, gametime;

int playerScore       = 0;
int saveLocation      = 1;
int currentHighScore  = 0;

boolean gamesetup     = false;

LEDs ledarray 			  = LEDs();
Buttonscls pushbutton	= Buttonscls();
GAMES pianotiles      = GAMES();
SCORE score         	= SCORE();
DATA data 		    		= DATA();

void setup() {
  //Serial.begin(9600);

  for (int x = 0; x < 10; x++) {
    pinMode(x, OUTPUT);
  }

  for (auto button : buttons) {
    pinMode(buttons[button], INPUT);
  }

  randomSeed(analogRead(A0));
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  //EEPROM.update(1, 2);

  currentHighScore = data.loadHigh(1);
  Serial.println("The high score is:");
  Serial.println(currentHighScore);
}

void shifter(int tiles[4]) {
  tiles[3] = tiles[2];
  tiles[2] = tiles[1];
  tiles[1] = tiles[0];
  tiles[0] = random(1, 5);
}

void loop() {
  // game setup
  if (gamesetup == false) {
    if (x >= 4) {
      x = 0;
    }
    a = pushbutton.button_ON(x);

    switch (a) {
      case 1:
        limit = 10000;
        break;
      case 2:
        limit = 15000;
        break;
      case 3:
        limit = 30000;
        break;
      case 4:
        limit = 45000;
        break;
      default :
        limit = 0;
        break;
      
    }
    if (limit != 0) {
      gamesetup = true;
      starttime = millis();
    }
    else {
      x++;
      gamesetup = false;
    }
  }

  if (gamesetup == true)
  {
    //game

    gametime = millis() - starttime;

    if (x >= 4) {
      x = 0;

      if (gametime < (limit) && (gametime > ((3 * limit) / 4))) {
        if ((digitalRead(A3) != LOW) || (digitalRead(A4) != LOW) || (digitalRead(A5) != LOW)) {
          digitalWrite(A3, LOW);
          digitalWrite(A4, LOW);
          digitalWrite(A5, LOW);
        }
      } else if ((gametime > (limit / 2)) && (gametime < ((3 * limit) / 4))) {
        if ((digitalRead(A3) != HIGH) || (digitalRead(A4) != LOW) || (digitalRead(A5) != LOW)) {
          digitalWrite(A3, HIGH);
          digitalWrite(A4, LOW);
          digitalWrite(A5, LOW);
        }
      } else if ((gametime > (limit / 4)) && (gametime < (limit / 2))) {
        if ((digitalRead(A3) != HIGH) || (digitalRead(A4) != HIGH) || (digitalRead(A5) != LOW)) {
          digitalWrite(A3, HIGH);
          digitalWrite(A4, HIGH);
          digitalWrite(A5, LOW);
        }
      } else if (gametime < (limit / 4)) {
        if ((digitalRead(A3) != HIGH) || (digitalRead(A4) != HIGH) || (digitalRead(A5) != HIGH)) {
          digitalWrite(A3, HIGH);
          digitalWrite(A4, HIGH);
          digitalWrite(A5, HIGH);
        }
      } else {
        //Stuff goes here
      }
    }

    pianotiles.tiler(tilecolumn);
    a = pushbutton.button_ON(x);

    if (a == tilecolumn[3]) {
      Serial.println(a);
      shifter(tilecolumn);
      playerScore = playerScore + 1;
      Serial.println("Point Awarded.");
    }

    x++;
    if (gametime >= limit) {
      Serial.println(gametime);
      data.highCheck(playerScore, saveLocation, currentHighScore);
      digitalWrite(enable1, HIGH);
      digitalWrite(enable2, HIGH);
      delay(500);
      score.printScore(playerScore);
      delay(100);
      exit(0);
    }
  }
}


