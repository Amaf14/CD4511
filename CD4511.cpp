#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include "CD4511.h"

CD4511::CD4511(int const A, B, C, D, LT, D1, D2)
{
   pinMode(A, OUTPUT);
   pinMode(B, OUTPUT);
   pinMode(C, OUTPUT);
   pinMode(D, OUTPUT);
   pinMode(LT, OUTPUT)
   pinMode(D1, OUTPUT);
   pinMode(D2, OUTPUT);
   _A= A;
   _B= B;
   _C= C;
   _D= D;
   _LT= LT;
   _D1= D1;
   _D2= D2;
}

void CD4511::cleardisplay()
{
	_A= 0;
	_B= 0;
	_C= 0;
	_D= 0;
	_LT= 1;
}

void CD4511::display(int Z, U)
{
	digitalWrite(_A, U/1000);
	digitalWrite(_B, U/100%10);
	digitalWrite(_C, U/10%10);
	digitalWrite(_D, U%10);
	digitalWrite(_D2, 1);
	delay(50);
	digitalWrite(_D2, 0);
	digitalWrite(_A, Z/1000);
	digitalWrite(_B, Z/100%10);
	digitalWrite(_C, Z/10%10);
	digitalWrite(_D, Z%10);
	digitalWrite(_D1, 1);
	delay(50);
	digitalWrite(_D1, 0);
}

void CD4511::test()
{
	digitalWrite(_LT, 0);
	delay(100);
	digitalWrite(_LT, 1);
}
