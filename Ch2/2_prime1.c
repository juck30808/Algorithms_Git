/****************************************************/
/*�i�{���W�١j: 2_prime1.c                          */
/*�i�{���\��j: �L�X���j�� n ���Ҧ����             */
/*       ��J : �j�� 1 ����� n                     */
/*       ��X : ���j�� n ���Ҧ����                 */
/*�i��Ƶ��c�j:                                     */
/****************************************************/
/*�i�ܼƦW�٤Υγ~�j                                */
/* isprime : ���L�ܼ�(true�N���ơAfalse�N��D���)*/
/*   count : �έp����`�Ӽ�                         */
/****************************************************/

#include <stdio.h>

void main(void)
{
   int n, count = 0;
   int i, j;
   enum boolean isprime;
   enum boolean {false,true};

   clrscr();
   printf("�п�J�j�� 1 ����� : ");
   scanf("%d",&n);

   printf("\n���j�� %d ����Ʀ�...\n\n",n);
   /*----------------------------------------------------------*/
   /*  ��ƪ��w�q�G�@�ӥ���ơA���F 1 �M�����H�~�S���O���]��   */
   /*            �G�@�ӥ���ơA���F 1 �M�����H�~����Q��L���� */
   /*              �Ҿ㰣                                      */
   /*----------------------------------------------------------*/
   for(i = 1; i <= n; i++){
      isprime = true;
      switch(i){
         case 1 : 		/* 1 �D���       */
            isprime = false;
            break;
         case 2 :		/* 2 �O�̤p����� */
            break;
         default :
            for(j = 2; j < i; j++){
               if((i % j) == 0){/* i �i�Q j �㰣�A�D��� */
                  isprime = false;
                  break;
               }
               else;
            }
      }
      if(isprime == true){	/* �L�X��� */
         count ++;
         printf("%3d ",i);
         if(count % 15 == 0)    /* �C�L��15�ӽ�ƴN���U�@�� */
	    printf("\n\n");
         else;
      }
      else;
   }
   printf("\n\n==> ���j�� %d ����Ʀ@�� %d ��",n,count);
}