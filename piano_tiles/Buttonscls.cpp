#include "Buttonscls.h"
#include "Arduino.h"

Buttonscls::Buttonscls() {

}

///////////////////////////////////////////////

int Buttonscls::button_ON(int x) {
  int buttonstate[4] = {0,0,0,0};
  delay(1);
  buttonstate[x] = digitalRead(buttons[x]);

  if (buttonstate[x] == 1) {
    int z = 0;
    while (z < 1) {
      delay(1);
      buttonstate[x] = digitalRead(buttons[x]);
      if (buttonstate[x] == 0) {
        z++;
      }
      else {
        z = 0;
      }
    }
    return x + 1;
  }
  else {
    return 7;
  }
}
