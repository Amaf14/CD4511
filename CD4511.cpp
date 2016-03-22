#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include "CD4511.h"


CD4511::CD4511(int A, int B, int C, int D, int D1, int nr)
{
   _A= A;
   _B= B;
   _C= C;
   _D= D;
   _D1= D1;//D1 is the first digit chatode
   _nr= nr;//nr is the total number of digits
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
	j=0;
    for(i=_D1;i<=_D1+_nr-1;i++)
      {
		  g[j]=i;
		  pinMode(g[j], OUTPUT);
		  digitalWrite(g[j], HIGH);
          j++;
      }
}

void CD4511::cleardisplay()
{
	digitalWrite(_A, 0);
	digitalWrite(_B, 0);
	digitalWrite(_C, 0);
	digitalWrite(_D, 0);
	//show '0'
}

void CD4511::display(long Z, int poz)
{
	digitalWrite(_A, Z/1000%10);
	digitalWrite(_B, Z/100%10);
	digitalWrite(_C, Z/10%10);
	digitalWrite(_D, Z%10);
	digitalWrite(g[poz], 0);
	delay(3);
	digitalWrite(g[poz], 1);
}

//not done yet
void CD4511::test()
{
	delay(100);
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

//not working again
void CD4511::binlist()
{ 
        long v[]={90000, 91000, 90100, 91100, 90010, 91010, 90110, 91110, 90001, 91001};
}
