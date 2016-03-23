#include<CD4511.h>

CD4511 7segment=(9, 8, 7, 6, 5);
int k;

void setup()
{
   7sgment.start();
   7segmen.binlist();
}

void loop()
{
   for(k=0 ; k<=9 ; k++)
   {
      7segment.display(v[k], D1);
      delay(1000);
   }
}
