  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include "CD4511.h"

//for two digits
CD4511::CD4511(int A, int B, int C, int D, int D1, int D2)
{
   _A= A;
   _B= B;
   _C= C;
   _D= D;
   _D1= D1;
   _D2= D2;
}

//proto
CD4511::CD4511(int A, int B, int C, int D, int D1, int nr)
{
   _A= A;
   _B= B;
   _C= C;
   _D= D;
   j=0;
   for(i=D1;i<=D1+nr;i++)
      {
          _g[j]=i;
          j++;
      }
}

//for a single digit
CD4511::CD4511(int A, int B, int C, int D, int D1)
{
   _A= A;
   _B= B;
   _C= C;
   _D= D;
   _D1= D1;
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
        while(_v[i]!=0)
           {
              pinMode(_v[i], OUTPUT);
              i++;
           }
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

//not working yet for some reason
int CD4511::tobin(int x)
{
	int r=1000;
	long p=90000;
	while(x!=0)
	{
		p+=x%2*r;
		r/=10;
		x/=2;
	}
	return p;
}

//working 
void CD4511::binlist()
{ 
        long v[]={90000, 91000, 90100, 91100, 90010, 91010, 90110, 91110, 90001, 91001};
}
