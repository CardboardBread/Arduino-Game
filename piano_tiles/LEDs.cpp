#include "LEDs.h"
#include "Arduino.h"

LEDs::LEDs()
{

}



////////////////////////////////////////////////////////////////////////////
void LEDs::binarysignal1 (int lednum)
{
  int A, B, C;
  if (lednum >= 8) {
    digitalWrite(enable1, HIGH);
  }
  else {
    digitalWrite(enable1, LOW);
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
  //Signal checker/debuger
  //Serial.println(A) ;
  //Serial.println(B) ;
  //Serial.println(C) ;
  //Serial.println("----") ;

}
/////////////////////////////////////////////////////////////////////////////////

void LEDs::binarysignal2 (int lednum)
{
  int A, B, C;
  if (lednum >= 8) {
    digitalWrite(enable2, HIGH);
  }
  else {
    digitalWrite(enable2, LOW);
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

  //Signal checker/debuger
  Serial.println(A) ;
  Serial.println(B) ;
  Serial.println(C) ;
  Serial.println("----") ;
}


///////////////////////////////////////////////////////////////////////////
void LEDs::LED_ON(int col, int row) {  //column and row must be between 1 and 4
  row = row-1;
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








