const int muxEnable1 = 5;
const int muxEnable2;
int muxSignal1[3];
int muxSignal2[3];
int buttonPins[4];
int randChoose = 0;

void setup() {
  for (int x = 2; x < 5; x++) {
    muxSignal[x - 2] = x;  
  }
  for (int x = 6; x <10; x++) {
    buttonPins[x - 6] = x;
  }
  pinMode(muxEnable, OUTPUT);
}

void writeToMultiplexer (int ledPos) {
  int bit1, bit2, bit3, mux = 0;
  
  bit3 = ledPos % 2;
  ledPos = ledPos / 2;
  bit2 = ledPos % 2;
  ledPos = ledPos / 2;
  bit1 = ledPos % 2;
    
  if (ledPos > -1 && ledPos < 4) {
    mux = 1;
  } else if (ledPos > 7 && ledPos < 12) {
    mux = 1;
  } else if (ledPos > 3 && ledPos < 8) {
    mux = 2;
  } else if (ledPos > 11 && ledPos < 16) {
    mux = 2;
  }
  
  if (mux == 1) {
    if (bit1 == 0) {
      digitalWrite(muxSignal1[1], LOW);
    } else if (bit1 == 1) {
      digitalWrite(muxSignal1[1], HIGH);
    }
    if (bit2 == 0) {
      digitalWrite(muxSignal1[2], LOW);
    } else if (bit2 == 1) {
      digitalWrite(muxSignal1[2], HIGH);
    }
    if (bit3 == 0) {
      digitalWrite(muxSignal1[3], LOW);
    } else if (bit3 == 1) {
      digitalWrite(muxSignal1[3], HIGH);
    }
  } else if (mux == 2) {
    if (bit1 == 0) {
      digitalWrite(muxSignal2[1], LOW);
    } else if (bit1 == 1) {
      digitalWrite(muxSignal2[1], HIGH);
    }
    if (bit2 == 0) {
      digitalWrite(muxSignal2[2], LOW);
    } else if (bit2 == 1) {
      digitalWrite(muxSignal2[2], HIGH);
    }
    if (bit3 == 0) {
      digitalWrite(muxSignal2[3], LOW);
    } else if (bit3 == 1) {
      digitalWrite(muxSignal2[3], HIGH);
    }
  }
}

void loop() {
  writeToMultiplexer(2);
}
