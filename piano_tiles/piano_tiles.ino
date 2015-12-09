const int channelA1 = 3;
const int channelB1 = 4;
const int channelC1 = 5;
const int channelA2 = 6;
const int channelB2 = 7;
const int channelC2 = 8;
const int button1   = 9;
const int button2   = 10;
const int button3   = 11;
const int button4   = 12;
long randnum;
int Led;

void setup() {
  Serial.begin(9600);
  for (int x = 3; x < 9; x++) {
    pinMode(x, OUTPUT);
  }
  for (int x = 9; x < 13; x++) {
    pinMode(x, INPUT);
  }
  randomSeed(analogRead(0));
}

void binarysignal (int lednum) {
  int A, B, C, x = 0 ;
  if (lednum > 7) {
    lednum = lednum - 8;
    x++;
  }
  C = lednum % 2;
  lednum = lednum / 2;
  B = lednum % 2;
  lednum = lednum / 2;
  A = lednum % 2;

  if (x = 0) {
    if (A == 0) {
      digitalWrite(channelA1, LOW);
    } else {
      digitalWrite(channelA1, HIGH);
    }
    if (B == 0) {
      digitalWrite(channelB1, LOW);
    } else {
      digitalWrite(channelB1, HIGH);
    }
    if (C == 0) {
      digitalWrite(channelC1, LOW);
    } else {
      digitalWrite(channelC1, HIGH);
    }
  } else {
    if (A == 0) {
      digitalWrite(channelA2, LOW);
    } else {
      digitalWrite(channelA2, HIGH);
    }
    if (B == 0) {
      digitalWrite(channelB2, LOW);
    } else {
      digitalWrite(channelB2, HIGH);
    }
    if (C == 0) {
      digitalWrite(channelC2, LOW);
    } else {
      digitalWrite(channelC2, HIGH);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  randnum = random(0, 3);
  Serial.println(randnum);

  if (randnum = 0) {
    Led = 0;
  } else if (randnum = 1) {
    Led = 4;
  } else if (randnum = 2) {
    Led = 8;
  } else {
    Led = 12;
  }
  binarysignal(2);
  digitalWrite(5, HIGH);
}
