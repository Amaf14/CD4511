#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include "CD4511.h"

CD4511::CD4511(int A, int B, int C, int D, int LT, int D1, int D2)
{
   _A= A;
   _B= B;
   _C= C;
   _D= D;
   _LT= LT;
   _D1= D1;
   _D2= D2;
}

void CD4511::start()
{
	pinMode(_A, OUTPUT);
	pinMode(_B, OUTPUT);
    	pinMode(_C, OUTPUT);
    	pinMode(_D, OUTPUT);
    	pinMode(_LT, OUTPUT);
	pinMode(_D1, OUTPUT);
	pinMode(_D2, OUTPUT);
}

void CD4511::cleardisplay()
{
	digitalWrite(_A, 0);
	digitalWrite(_B, 0);
	digitalWrite(_C, 0);
	digitalWrite(_D, 0);
	digitalWrite(_LT, 1);
}

void CD4511::display(long Z, int poz)
{
	digitalWrite(_A, Z/1000%10);
	digitalWrite(_B, Z/100%10);
	digitalWrite(_C, Z/10%10);
	digitalWrite(_D, Z%10);
	if(poz == 1)
	{
		digitalWrite(_D1, 1);
		delay(50);
		digitalWrite(_D1, 0);
	}
	else
	{
		digitalWrite(_D2, 1);
		delay(50);
		digitalWrite(_D2, 0);
	}
}

void CD4511::test()
{
	digitalWrite(_LT, 0);
	delay(100);
	digitalWrite(_LT, 1);
}
