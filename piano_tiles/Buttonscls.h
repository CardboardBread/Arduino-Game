#ifndef Buttonscls_h
#define Buttonscls_h
#include "Arduino.h"


class Buttonscls
{
  public:
    Buttonscls();

    int button_ON(int x, int tilecolumn[4]);
    
    int buttons[4] = {A1, A2, 12, 13};


};

#endif


