const int channelA1 = 2;
const int channelB1 = 3;
const int channelC1 = 4;
const int enable1   = 5;

const int channelA2 = 6;
const int channelB2 = 7;
const int channelC2 = 8;
const int enable2   = 9;

const int button1   = 10;
const int button2   = 11;
const int button3   = 12;
const int button4   = 13;
int Led = 0;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int x = 0; x < 10; x++) {
    pinMode(x, OUTPUT);
  }
}
void loop() {
  for (int Led = 0; Led < 4; Led++) {
    for (int time = 0; time < 3; time++) {
      delay(1000);
      binarysignal1(Led);
      delay(1000);
      binarysignal2(Led + 1);
      delay(1000);
      binarysignal1(Led + 4 + 2);
      delay(1000);

      binarysignal2(Led + 4 + 3);

    }
  }
}
void tiledropper(int col) {
  //for (int Led = 0; Led < 4; Led++) {
  //delay(1000);
  if (col == 1) {
    binarysignal1(Led);
  }
  else if (col == 2) {
    binarysignal2(Led);

  }
  else if (col == 3) {
    binarysignal1(Led + 4);

  }
  else {
    binarysignal2(Led + 4);

  }

  //}
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
