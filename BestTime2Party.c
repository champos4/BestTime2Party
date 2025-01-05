#include <stdio.h>
#include "simpio.h"     /* libraries  */
#include "genlib.h"

#define size 23 /* The size of the array that demonstrates the 24 hours of a day*/

int main()
{
  int i,AF[size],x,AN[size],EMF[size],max,j,pos,counter=0;      /* define variables */
  string ON[size] ;

  printf("Give the number of bands:") ;
  x=GetInteger();
  for(i=0;i<x;i++)
  {
      printf("Give the band's name:");               /* Insert Data */
      ON[i]=GetLine();
      printf("Give the time of the arrival:");
      AF[i]=GetInteger();
      while(AF[i]<=0 || AF[i]>24)
      {
          printf("Please try again: \n") ;      /*Validity Check*/
          AF[i]=GetInteger();
      }
      printf("Give the time of leaving:");
      AN[i]=GetInteger();
      while(AN[i]<=0 || AN[i]>24)
      {
          printf("Please try again: \n") ;      /*Validity Check*/
          AN[i]=GetInteger();
      }
  }
  for(i=0;i<size;i++)
  {
      EMF[i]=0 ;
  }
  for(i=0;i<x;i++)
  {
      for(j=AF[i];j<AN[i];j++)      /* Calculate the number of the bands that will be there at j o'clock*/
      {
              EMF[j]++ ;
      }
  }
 max=EMF[0] ;
 for(i=1;i<size;i++)
 {
    if(EMF[i]>max)           /*Find the moment with the most bands */
    {
        max=EMF[i] ;
        pos=i ;
    }
 }
 for(i=0;i<size;i++)
 {
    if(EMF[i]==max)          /* Check for equallity */
        counter++ ;
 }
 if(counter==1)
 {
    printf("The best time for you to come is at %d:00 where  %d bands will be there",pos,max) ; /*Check the best time without equallity */
 }
 else if(counter>1)
 {
    printf("There are %d momens for you to come \n",counter);
    for(i=0;i<size;i++)
    {
        if(EMF[i]==max)
        {
            printf("One possible moment is at %d:00 where  %d bands will be there. Those are: \n",i,max) ; /*Check the best time with equality*/
            for(j=0;j<size;j++)
            {
                if(AF[j]==i)
                {
                    printf("%s\n",ON[j]); /*Prin the bands in case of equality */
                }
            }
        }
    }
 }

return 0 ; }



