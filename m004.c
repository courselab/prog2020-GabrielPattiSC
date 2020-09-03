/* m004.c - Binary to decimal.

   This program takes a string read as a command line argument and,
   interpreting it as a positive binary integer, outputs its 
   corresponding value in decimal base.


   E.g.

      command line    : m004 0011 
      expected output : 3

   Directions:

      Please, edit function decimal();
      do no not change function main().

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Return the value in decimal base of the string b, interpreted
   as the a positive binary number. If the string contains any
   characters other than '1's and '0's, truncate the string
   right before the spurious character (eg. truncate 110x001
   into 110); an empty string means zero. */

  float MyPow (int a, int b)
  {
  if (b<0)
    return (1.0/a)*(MyPow(a,b+1));
     else
     if (b==0)
     return 1;
     else
     if (b==1)
     return a;
     else
       return a*MyPow(a,b-1);
       }
  int decimal (char *b) 
  {
  int i;
  int mult;
  int acc=0;
  for (i= strlen(b) - 1, mult = 0; i>=0; i--, mult++) {
  

      if (b[i]=='1') {
   
      acc = acc + MyPow(2,mult);
     }
     }

     return acc;
}
#define USAGE "m004 <string>\n"

/* Do not edit this function. */

int main (int argc, char **argv)
{
  int n;

  if (argc < 2)
    {
      printf (USAGE);
      exit(1);
    }

  n = decimal (argv[1]);

  printf ("%d\n", n);
  
  return 0;
}
 