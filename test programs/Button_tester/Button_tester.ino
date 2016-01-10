//the goody two shoe program
const int channelA1 = 2;
const int channelB1 = 3;
const int channelC1 = 4;
const int enable1   = 5;

const int channelA2 = 6;
const int channelB2 = 7;
const int channelC2 = 8;
const int enable2   = 9;

int buttons[4] = {A1, A2, 12, 13};
int Led, a, x = 0;
int tilecolumn[4] = {2, 3, 4, 1};



void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  for (int x = 0; x < 10; x++) {
    pinMode(x, OUTPUT);
  }

  for (auto button : buttons) {
    pinMode(buttons[button], INPUT);
  }
  randomSeed(analogRead(A5));

}
void loop() {
  if (x >= 4) {
    x = 0;
  }
  digitalWrite(enable1, HIGH);
  digitalWrite(enable2, HIGH);

  a = button_ON(x);
  if (a + 1 == 1) {
    LED_ON(1, 0);
    delay(50);
  }
  else if (a + 1 == 2) {
    LED_ON(2, 0);
    delay(50);
  }
  else if (a + 1 == 3) {
    LED_ON(3, 0);
    delay(50);
  }
  else if (a + 1 == 4) {
  LED_ON(4, 0);
    delay(50);
  }
  else {
    digitalWrite(enable1, HIGH);
    digitalWrite(enable2, HIGH);
  }
  x++;
}


int button_ON(int x) {
  int buttonstate[4], laststate[4];
  delay(1);
  buttonstate[x] = digitalRead(buttons[x]);


  if (buttonstate[x] == 1) {
    int z = 0;
    while (z < 1) {
      //tiler(tilecolumn[0], tilecolumn[1], tilecolumn[2], tilecolumn[3]);
      delay(1);
      buttonstate[x] = digitalRead(buttons[x]);
      if (buttonstate[x] == 0) {
        z++;
      }
      else {
        z = 0;
      }
    }
    return x;
  }
  else {
    return 7;
  }
}

void shifter(int tiles[4]) {
  tiles[3] = tiles[2];
  tiles[2] = tiles[1];
  tiles[1] = tiles[0];
  tiles[0] = random(1, 5);
}

void tiler(int coltile1, int coltile2, int coltile3, int coltile4) {
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

}



void LED_ON(int col, int row) {

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
  Serial.println(A);
  Serial.println(B);
  Serial.println(C);
  Serial.println("--------");
}
