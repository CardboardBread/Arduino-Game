#ifndef TIME_h
#define TIME_h

class TIME
{
  public:
    TIME();
    void flashLED();
    int ledChoice;
    int port;
    int actionType;
    int millisInt =  (int) millis;
};

#endif
