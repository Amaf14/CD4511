#ifndef CD4511_h
#define CD4511_h

#include "Arduino.h"

class CD4511
{
   public:
   CD4511::CD4511(int A, int B, int C, int D, int D1, int nr);
   //for a single digit
   //CD4511(int A, int B, int C, int D, int D1);
   void start();
   void cleardisplay();
   void display(long Z, int poz);
   void test();
   int tobin(int x);
   void binlist();
   
   private:
   int _A, _B, _C, _D, _D1, _D2, g[5], _nr;
   long Z, _v[11], p;
   int poz, i, j;
};

#endif
