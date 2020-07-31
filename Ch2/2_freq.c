/****************************************************/
/*�i�{���W�١j: 2_freq.c                            */
/*�i�{���\��j: �M��X���ƤΨ�X�{�W�v              */
/*       ��J : ��J15�Ӥ��� 0 �� 5 �����������    */
/*       ��X : ���ƤΨ�X�{�W�v                    */
/*�i��Ƶ��c�j: �}�C���c                            */
/****************************************************/
/*�i�ܼƦW�٤Υγ~�j                                */
/*       x[N] : �x�s��J�����                      */
/*   count[i] : �O����� i �X�{������               */
/*          n : ����                                */
/****************************************************/

#include <stdio.h>
#define N 15      /* ��J 15 �Ӿ��                 */
#define NUMBER 6  /* ��J����ƥ������� 0 �� 5 ���� */

int frequency(int *count);

void main(void)
{
   int i,n;
   int x[N] = {0};
   int count[NUMBER] = {0};

   clrscr();
   printf("�п�J15�Ӿ�� i �A0 <= i <= 5 :\n");

   for(i = 0; i < N; i++){
      scanf("%d",&x[i]);
      count[x[i]] = count[x[i]] + 1;
   };
   n = frequency(count);
   printf("\n���Ƭ� %d �A�@�X�{ %d ��\n",n,count[n]);
}

/*------------------------------------------------------------*/ 
/*   �M�䲳��(��P�ɦ��n�X�ӳ̤j�̮ɡA�H��J�ȸ��p�̬�����)   */
/*------------------------------------------------------------*/ 
int frequency(int *count)
{
   int i;
   int most_freq_no = count[0];
   int n = 0;  /* ���� */
   
   printf("\ncount�}�C�����e�� : ");
   printf("\n----------------------------------");
   for(i = 0; i <= NUMBER-1 ; i++){
      printf("\n ==> count[%d] = %d",i,count[i]);
      printf(" (%d �X�{ %d ��)",i,count[i]);
      if(count[i] > most_freq_no){
         most_freq_no = count[i];
         n = i;
      }
   }
   printf("\n----------------------------------");
   return n;
} 