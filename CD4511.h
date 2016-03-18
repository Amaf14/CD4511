#ifndef CD4511_h
#define CD4511_h

#include "Arduino.h"

class CD4511
{
   public:
     CD4511(int A, int B, int C, int D, int LT, int D1, int D2);
     void start();
     void cleardisplay();
     void display(long Z, int poz);
     void test();
     int tobin(int x);
     void binlist();
   private:
     int _A, _B, _C, _D, _LT, _D1, _D2;
     long Z, v[11];
     int poz, x ,r, p;
};

#endif
