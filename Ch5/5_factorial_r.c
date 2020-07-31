/*************************************************/
/*�i�{���W�١j: 5_factorial_r.c                  */
/*�i�{���\��j: ���j���(��)�G�p�� n!            */
/*       ��J : ��� n                           */
/*       ��X : n! ����                          */
/*�i��Ƶ��c�j: ���j                             */
/*************************************************/

#include <stdio.h>

long factorial(long n);

/*----------------------------*/
/*   �H���j�覡�p�� n! ����   */
/*----------------------------*/
long factorial(long n)
{
   if(n == 0)
      return 0;
   if(n == 1)
      return 1;
   if(n > 1)
     	return (n * factorial(n-1)); 
   else 
      printf("\n���~! n �����������!\n");
}

void main(void)
{
   int i;

   clrscr( );
   for(i=0; i <= 10; i++){
      printf("\n==> %d ! = %ld",i,factorial(i));
   }
}
