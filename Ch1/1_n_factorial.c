/********************************************************/ 
/*�i�{���W�١j: 1_n_factorial.c                         */ 
/*�i�{���\��j: �p��n!                                  */ 
/********************************************************/ 
/*�i�ܼƦW�٤Υγ~�j                                    */ 
/* product: �ΨӰO����X��n!�����G                      */ 
/********************************************************/
  
#include <stdio.h> 

main()
{
 int n;
 int product=1, multiplier;

 scanf(��%d��,&n);

 multiplier = n;
 while ( multiplier >1 )
       {
         product *= multiplier;
         multiplier--;
       }
 printf(��\nThe result of %d factorial = %d��,n, product);

} 
