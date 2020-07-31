/*************************************************/
/*�i�{���W�١j: 5_fib_nr.c                       */
/*�i�{���\��j: �H�D���j�覡�C�L�X�O��ƦC       */
/*       ��J : ��� n                           */
/*       ��X : �C�L�X�� n ���O���              */
/*�i��Ƶ��c�j:                                  */
/*************************************************/

#include <stdio.h>

long fib_nr(long n);

/*-------------------------------------*/
/*   �H�D���j�覡�C�L�X�� n ���O���   */
/*-------------------------------------*/
long fib_nr(long n)
{
   long fn1, fn2, fn;
   int i;

   if(n == 0)
      return 0; 
   if(n == 1)
      return 1;
   if(n > 1){
      fn1 = 0;
      fn2 = 1;
      for(i = 2; i <= n; i++){
         fn = fn1 + fn2;
         fn1 = fn2;
         fn2 = fn;
      }
      return fn;
   }
   else 
      printf("\n���~! n �������j�� 0 �����!");
 }

void main(void)
{
   int i;

   clrscr( );
   printf("\n�� 0 ���ܲ� 12 ���O��Ƭ� : ");
   for(i=0; i <= 12; i++)
      printf("%ld  ",fib_nr(i));
}