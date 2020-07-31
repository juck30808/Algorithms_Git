/****************************************************/
/*�i�{���W�١j: 2_prime2.c                          */
/*�i�{���\��j: �L�X���j�� n ���Ҧ����             */
/*       ��J : �j�� 1 ����� n                     */
/*       ��X : ���j�� n ���Ҧ����                 */
/*�i��Ƶ��c�j: �}�C���c                            */
/****************************************************/
/*�i�ܼƦW�٤Υγ~�j                                */
/* isprime : ���L�ܼ�(true�N���ơAfalse�N��D���)*/
/* prime[N] : �Ȧs���j�� n ���Ҧ����               */
/*   count : �έp����`�Ӽ�                         */
/****************************************************/

#include <stdio.h>
#include <math.h>
#define N 120

int find_prime(int *prime, int n);

void main(void)
{  
   int i, n, count = 0;
   int prime[N] = {0};

   clrscr();
   printf("�п�J�j�� 1 ����� : ");
   scanf("%d",&n);

   printf("\n���j�� %d ����Ʀ�...\n\n",n);
   /*-----------------------------*/
   /*   ��X���j�� n ���Ҧ����   */
   /*-----------------------------*/
   count = find_prime(prime, n);

   /*-----------------------------*/
   /*   �L�X���j�� n ���Ҧ����   */
   /*-----------------------------*/
   for(i = 0; i <= count; i++){
      printf("%d ",prime[i]);
      if((i+1) % 15 == 0)	/* �C�L�� 15 �ӽ�ƴN���U�@�� */
	 printf("\n\n");
   }
   printf("\n\n�p�󵥩� %d ����Ʀ@�� %d ��",n,count+1);
}

/*-----------------------------------------------------------*/
/*   ��X <= n ���Ҧ���ơA�ĥΥH�U�w�q                      */
/*   ��ƪ��w�q�G�@�ӥ���ơA����Q�p�󥻨����Ҧ���ƩҾ㰣  */
/*   �Q��쪺��Ư��s�b�}�Cprime[]����                       */
/*-----------------------------------------------------------*/
int find_prime(int *prime, int n)
{
   enum boolean isprime;
   enum boolean {false,true};
   int i, j, count = -1;

   for(i = 2; i <= n; i++){
      isprime = true;
      switch(i){
         case 2 :		        /* 2 �O�̤p����� */
            prime[++count] = i;
            break;
         default :
            for(j = 0; prime[j] != 0 && prime[j] <= sqrt(i) &&
                isprime == true; j++){
               if((i % prime[j]) == 0)  /* �D���         */
                  isprime = false;
               else;               
            }
            if(isprime == true)
               prime[++count] = i;
      }
   }
   return count;
}