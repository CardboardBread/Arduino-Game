/* Blink without Delay

  Turns on and off a light emitting diode (LED) connected to a digital
  pin, without using the delay() function.  This means that other code
  can run at the same time without being interrupted by the LED code.

  The circuit:
   LED attached from pin 13 to ground.
   Note: on most Arduinos, there is already an LED on the board
  that's attached to pin 13, so no hardware is needed for this example.

  created 2005
  by David A. Mellis
  modified 8 Feb 2010
  by Paul Stoffregen
  modified 11 Nov 2013
  by Scott Fitzgerald


  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
*/

// constants won't change. Used here to set a pin number :
const int ledPin =  13;      // the number of the LED pin
const int ledPin2 =  12;
// Variables will change :
int ledState = LOW;             // ledState used to set the LED
int ledState2 = LOW;
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated
unsigned long previousMillis2 = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 1000;           // interval at which to blink (milliseconds)
const long interval2 = 10000;
void setup() {
  Serial.begin(9600);
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time you blinked
  // the LED is bigger than the interval at which you want to
  // blink the LED.

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    Serial.println(previousMillis) ;

    Serial.println(currentMillis) ;
    Serial.println("----") ;

    previousMillis = currentMillis;


    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }


  if (currentMillis - previousMillis2 >= interval2) {
    // save the last time you blinked the LED
    Serial.println(previousMillis2) ;

    Serial.println(currentMillis) ;
    Serial.println("----") ;

    previousMillis2 = currentMillis;


    // if the LED is off turn it on and vice-versa:
    if (ledState2 == LOW) {
      ledState2 = HIGH;
    } else {
      ledState2 = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin2, ledState2);
  }
}
