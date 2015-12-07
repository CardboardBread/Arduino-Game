const int ledCount = 4;
const int buzzerPin = 10;
int ledPins[4];
int buttonPins[4];
int timer = 0;
int buttonDown = 0;
int randLed = 0;
int score = 0;

void setup() {
  for (int x = 2; x < ledCount + 2; x++) {
    pinMode(x, OUTPUT);
    ledPins[x - 2] = x;
  }
  for (int x = 6; x < 10; x++) {
    pinMode(x, INPUT);
    buttonPins[x - 6] = x;
  }
  Serial.begin(9600);
  for (int x = 0; x < 4; x++) {
    Serial.println(ledPins[x]);
    Serial.println(buttonPins[x]);
  }
  #include "pitches.h"
}

int advance(int playerChoice) {
  randLed = random(4) + 1;
  digitalWrite(randLed + 2, HIGH);
  while (buttonDown == 1) {
    if (playerChoice == randLed) {
      score = score + 1;
      Serial.println("Point awarded to score.");
      Serial.println(score);
      tone(buzzerPin, NOTE_E4);
    } else {
    Serial.println("Game Loss, Resetting Score...");
    tone(buzzerPin, NOTE_D3);   
    score = 0;
    }
  }
  playerChoice = 0;
}


void loop() {
  while (digitalRead(buttonPins[0]) == HIGH || digitalRead(buttonPins[1]) == HIGH || digitalRead(buttonPins[2]) == HIGH || digitalRead(buttonPins[3]) == HIGH) {

    if (digitalRead(buttonPins[0]) == HIGH) {
      digitalWrite(ledPins[0], HIGH);
      tone(buzzerPin, 277, 150);
      Serial.println("Button 1, HIGH");
      buttonDown = 1;
      advance(1);
    } else if (digitalRead(buttonPins[1]) == HIGH) {
      digitalWrite(ledPins[1], HIGH);
      tone(buzzerPin, 277, 150);
      Serial.println("Button 2, HIGH");
      buttonDown = 1;
      advance(2);
    } else if (digitalRead(buttonPins[2]) == HIGH) {
      digitalWrite(ledPins[2], HIGH);
      tone(buzzerPin, 277, 150);
      Serial.println("Button 3, HIGH");
      buttonDown = 1;
      advance(3);
    } else if (digitalRead(buttonPins[3]) == HIGH) {
      digitalWrite(ledPins[3], HIGH);
      tone(buzzerPin, 277, 150);
      Serial.println("Button 4, HIGH");
      buttonDown = 1;
      advance(4);
    } else {
      buttonDown = 0;
    }
    
    timer = timer + 1;

    if (timer > 200) {
      for (int x = 2; x < ledCount + 2; x++) {
        digitalWrite(x, LOW);
      }
      timer = 0;
    }
  }
}
