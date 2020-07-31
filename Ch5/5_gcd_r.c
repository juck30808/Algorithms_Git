/*******************************************************/
/*�i�{���W�١j: 5_gcd_r.c                              */
/*�i�{���\��j: ���j���(��)�G�D�⥿��Ƥ��̤j���]��   */
/*       ��J : ��ӥ����                             */
/*       ��X : �̤j���]��                             */
/*�i��Ƶ��c�j: ���j                                   */
/*******************************************************/
/*�i�ܼƦW�٤Υγ~�j                                   */
/*    divisor : ����                                   */
/*   dividend : �Q����                                 */
/*  remainder : �l��                                   */
/*******************************************************/

#include <stdio.h>

int gcd(int dividend, int divisor);
void swap(int *x, int *y);

/*------------------------------------------*/
/*   �H���j�覡�D�⥿��Ƥ��̤j���]��(GCD)  */
/*------------------------------------------*/
int gcd(int dividend, int divisor)
{
   int remainder;

   if (dividend < divisor)      /* �Q���� = ���j�� */
      swap(&dividend,&divisor); /* ���� = ���p��   */

   if (divisor !=0) {   /* �l�� != 0 */         
      remainder = dividend % divisor;
      return gcd(divisor,remainder);   /* ���^�I�sgcd()��� */
   }
   else
      return dividend;
}  

/*------------------------*/
/*   �N x �P y ���ȥ洫   */
/*------------------------*/
void swap(int *x, int *y)
{
   int temp;

   temp = *x;
   *x = *y;
   *y = temp;
}

void main(void)
{ 
   clrscr( );
   printf("gcd(256,72) = %d\n",gcd(256,72)); 
}