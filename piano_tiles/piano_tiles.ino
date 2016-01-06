
#include "Arduino.h"
#include "Buttonscls.h"
#include "LEDs.h"
#include "GAMES.h"
#include "SCORE.h"

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
int tilecolumn[4]    	= {1,2, 3, 4};
unsigned long counter 	= 0;

LEDs ledarray 			= LEDs();
Buttonscls pushbutton	= Buttonscls();
GAMES pianotiles 		= GAMES();
SCORE score				= SCORE();


void setup() {
  Serial.begin(9600);
  
  for (int x = 0; x < 10; x++) {
    pinMode(x, OUTPUT);
  }

  for (auto button : buttons) {
    pinMode(buttons[button], INPUT);
  }
  
  randomSeed(analogRead(A5));
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
}


void loop() {
	counter = counter + 1;
	
	if (x >= 4) {
		x = 0;
	}
	
    pianotiles.tiler(tilecolumn);
    a = pushbutton.button_ON(x,tilecolumn);
	
    if (a + 1 == tilecolumn[3]) {
		Serial.println(a);
		shifter(tilecolumn);
		score.printScore();
    }
	
    x++;
	
    if (counter > 1200) {
      digitalWrite(enable1, HIGH);
      digitalWrite(enable2, HIGH);
      exit(0);
    }
}


void shifter(int tiles[4]) {
  tiles[3] = tiles[2];
  tiles[2] = tiles[1];
  tiles[1] = tiles[0];
  tiles[0] = random(1, 5);
}