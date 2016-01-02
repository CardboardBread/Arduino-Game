#ifndef LEDs_h
#define LEDs_h


class LEDs
{
  public:
    LEDs();
    void binarysignal1(int lednum);
    void binarysignal2(int lednum);
    void LED_ON(int col, int row);

    const int channelA1 = 2;
    const int channelB1 = 3;
    const int channelC1 = 4;
    const int enable1   = 5;

    const int channelA2 = 6;
    const int channelB2 = 7;
    const int channelC2 = 8;
    const int enable2   = 9;
};

#endif


