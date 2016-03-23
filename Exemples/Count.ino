#include<CD4511.h>

CD4511 7segment=(9, 8, 7, 6, 5);
//uses a single digit display
//the function for a single digit isn't done yet
int k;

void setup()
{
   7sgment.start();//making the selected pins outputs
   7segmen.binlist();//a list with numbers from 0 to 9 in binary code
}

void loop()
{
   for(k=0 ; k<=9 ; k++)
   {
      7segment.display(v[k], D1);//display the number 
      delay(1000);//wait one second
   }
}
