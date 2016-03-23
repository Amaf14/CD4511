/*********************************************************************
This is an example sketch for a BCD driver.

The driver uses four pins to comunnicate with the Arduino.

Written by Amaf14.
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include<CD4511.h>

CD4511 7segment=(9, 8, 7, 6, 5);//A=9, B=8, C=7, D=6 
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
