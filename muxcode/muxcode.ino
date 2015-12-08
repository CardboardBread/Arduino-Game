const int muxEnable = 5;
int muxSignal[3];
int buttonPins[4];

void setup() {
  for (int x = 2; x < 5; x++) {
    muxSignal[x - 2] = x;  
  }
  for (int x = 6; x <10; x++) {
    buttonPins[x - 6] = x;
  }
  pinMode(muxEnable, OUTPUT);
}

void loop() {
  
}
