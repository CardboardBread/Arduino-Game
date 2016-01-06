/*int button_ON(int x) {
  Tiles led = Tiles();
  int buttonstate[4], laststate[4];
  delay(1);
  buttonstate[x] = digitalRead(buttons[x]);


  if (buttonstate[x] == 1) {
    int z = 0;
    while (z < 1) {
      tiler(tilecolumn[0], tilecolumn[1], tilecolumn[2], tilecolumn[3]);
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



  void tiler(int coltile1, int coltile2, int coltile3, int coltile4) {
  delay(50);
  digitalWrite (enable1, HIGH);
  digitalWrite (enable2, HIGH);
  LED_ON(coltile1, 0);
  delay(50);
  LED_ON(coltile2, 1);
  delay(50);
  LED_ON(coltile3, 2);
  delay(50);
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
  }*/