/*************************************************/
/*�i�{���W�١j: 5_2powern_r.c                    */
/*�i�{���\��j: ���j���(��)�G�p�� 2 �� n ����   */
/*       ��J : ��� n                           */
/*       ��X : 2 �� n ����                      */
/*�i��Ƶ��c�j: ���j                             */
/*************************************************/

#include <stdio.h>

long two_power_n(long n);

/*------------------------------------*/
/*   �H���j�覡�p�� 2 �� n ���褧��   */
/*------------------------------------*/
long two_power_n(long n)
{
   if(n == 0)
      return 1;   
   if(n == 1)
      return 2;
   if(n > 1)
     	return (2 * two_power_n(n-1)); 
   else 
      printf("\n���~! n �����������!\n");
}

void main(void)
{
   int i;

   clrscr( );
   for(i=0; i <= 5; i++){
      printf("\n==> 2 �� %d ���� = %ld",i,two_power_n(i));
   }
}