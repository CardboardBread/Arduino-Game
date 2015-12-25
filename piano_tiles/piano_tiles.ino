//the goody two shoe program
const int channelA1 = 2;
const int channelB1 = 3;
const int channelC1 = 4;
const int enable1   = 5;

const int channelA2 = 6;
const int channelB2 = 7;
const int channelC2 = 8;
const int enable2   = 9;

const int pushbutton1   = A1;
const int pushbutton2   = A2;
const int pushbutton3   = 12;
const int pushbutton4   = 13;
int Led = 0;
int tilecolumn[4] = {2, 3, 4, 1};



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int x = 0; x < 10; x++) {
    pinMode(x, OUTPUT);
  }
  pinMode(pushbutton1, INPUT);
  pinMode(pushbutton2, INPUT);
  pinMode(pushbutton3, INPUT);
  pinMode(pushbutton4, INPUT);

  randomSeed(analogRead(A5));

}
void loop() {


  tiler(tilecolumn[0], tilecolumn[1], tilecolumn[2], tilecolumn[3]);
  shifter(tilecolumn);
}

void shifter(int tiles[4]) {
  tiles[3] = tiles[2];
  delay(1);
  tiles[2] = tiles[1];
  delay(1);
  tiles[1] = tiles[0];
  delay(1);
  tiles[0] = random(1, 5);
  delay(1);

}

void tiler(int coltile1, int coltile2, int coltile3, int coltile4) {
  //for (int time = 0; time < 100; time++) {
  int x = 0;
  while (x < 1) {
    delay(1);
    digitalWrite (enable1, HIGH);
    digitalWrite (enable2, HIGH);
    LED_ON(coltile1, 0);
    delay(1);
    LED_ON(coltile2, 1);
    delay(1);
    LED_ON(coltile3, 2);
    delay(1);
    LED_ON(coltile4, 3);
    x = Buttons(coltile4);
  }
}

int Buttons (int correctled) {
  int tap;
  if (correctled == 4) {
    tap = pushbutton4;
  }
  else if (correctled == 3) {
    tap = pushbutton3;
  }
  else if (correctled == 2) {
    tap = pushbutton2;
  }
  else {
    tap = pushbutton1;
  }

  int x = 0;
  //while ( x < 1) {
  delay(1);

  int buttonState = digitalRead(tap);

  if (buttonState == 0) {
    Serial.println(buttonState);
    delay(10);
    int buttonState = digitalRead(tap);
    if (buttonState == 1) {
      Serial.println("tapped");
      Serial.println(correctled);
      x = 1;
    }
    else {
      x = 0;
    }
  }
  else {
    x = 0;
  }
  //}
  return x;
}

void LED_ON(int col, int row) {

  if (row > 3) {
    row = 8;
  }
  else {
    row = row;
  }
  if (col == 1) {
    binarysignal1(row);
  }
  else if (col == 2) {
    binarysignal2(row);

  }
  else if (col == 3) {
    binarysignal1(row + 4);

  }
  else {
    binarysignal2(row + 4);

  }
}


void binarysignal2 (int lednum) {
  int A, B, C;
  if (lednum >= 8) {
    digitalWrite (enable2, HIGH);
  }
  else {
    digitalWrite (enable2, LOW);
  }
  A = lednum % 2;
  lednum = lednum / 2;
  B = lednum % 2;
  lednum = lednum / 2;
  C = lednum % 2;

  if (A == 0) {
    digitalWrite(channelA2, LOW);
  }
  else {
    digitalWrite(channelA2, HIGH);
  }
  if (B == 0) {
    digitalWrite(channelB2, LOW);
  }
  else {
    digitalWrite(channelB2, HIGH);
  }
  if (C == 0) {
    digitalWrite(channelC2, LOW);
  }
  else {
    digitalWrite(channelC2, HIGH);
  }
}

void binarysignal1 (int lednum) {
  int A, B, C;
  if (lednum >= 8) {
    digitalWrite (enable1, HIGH);
  }
  else {
    digitalWrite (enable1, LOW);
  }
  A = lednum % 2;
  lednum = lednum / 2;
  B = lednum % 2;
  lednum = lednum / 2;
  C = lednum % 2;

  if (A == 0) {
    digitalWrite(channelA1, LOW);
  }
  else {
    digitalWrite(channelA1, HIGH);
  }
  if (B == 0) {
    digitalWrite(channelB1, LOW);
  }
  else {
    digitalWrite(channelB1, HIGH);
  }
  if (C == 0) {
    digitalWrite(channelC1, LOW);
  }
  else {
    digitalWrite(channelC1, HIGH);
  }

}
