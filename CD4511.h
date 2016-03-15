#ifndef CD4511_h
#define CD4511_h

#include "Arduino.h"

class CD4511
{
   public:
     CD4511(int A, B, C, D, LT, D1, D2);
     void cleardisplay();
     void display(int const Z, U);
     void test();
   private:
     int A, B, C, D, LT, D1, D2
};

#endif