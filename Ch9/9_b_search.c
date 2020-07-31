/*********************************************************/
/*�i�{���W�١j: 9_b_search.c                             */
/*�i�{���\��j: �G���j�M                                 */
/*       ��J : �@�դw�g���u��Ȥ�����v�ƧǪ����       */
/*              �n�j�M����� key                         */
/*       ��X : �j�M���L�{�M���G                         */
/*�i��Ƶ��c�j: �}�C���c                                 */
/*********************************************************/
/*�i�ܼƦW�٤Υγ~�j                                     */
/*        d[] : �x�s�ݷj�M�����                         */
/*    index[] : �Yd[i]=key�A�h�Ni�Ȧs��index[]��         */
/*     Size,n : �}�C d ���j�p(�����Ӽ�)                  */
/*********************************************************/

#include <stdio.h>
#define Size 16
#define true 1

void print_org_data(const int d[], int n) ;
int  b_searching(int d[], int low, int high, int key, int index[]);

/*--------------------------------------------*/
/*   �C�L�ݷj�M�����(�}�C d �@�� n �Ӥ���)   */
/*--------------------------------------------*/
void print_org_data(const int d[], int n) 
{
   int i;

   printf("�}�C���� d[0]  [1]  [2]  [3]  [4]  [5]  [6]  [7]  [8]  [9] [10] [11] [12] [13] [14] [15]\n");
   printf("----------------------------------------------------------------------------------------\n");
   printf("<��  ��> ");
   for(i = 0; i < n; i++){
      printf("%4d ",d[i]);
   }
   printf("\n----------------------------------------------------------------------------------------\n");
}

/*--------------*/
/*   �G���j�M   */
/*--------------*/
int b_searching(int d[], int low, int high, int key, int index[])
{
   int i, count, temp;

   if(key < d[low] || key > d[high])
     return (-1);

   count=-1;
   while(low <= high){
      i = (low + high)/2;
      if(key < d[i]){
         printf("��� %d �P d[%d] ���\n",key,i,d[i]);
         high = i - 1;          /* �U�@�^�X�����e�b���j�M */
      }
      else{
         if(key > d[i]){
            printf("��� %d �P d[%d] ���\n",key,i,d[i]);
            low = i + 1;        /* �U�@�^�X������b���j�M */
         }
         else{
            printf("��� %d �P d[%d] ���\n",key,i,d[i]);
            index[++count] = i; /* ���F�A�N�}�C�����x�s��}�C index */
            temp = i;

            i = temp - 1;            
            while(key == d[i]){	/* �����e��� */
               index[++count] = i--;
            }

	    i = temp + 1;       /* �������� */
	    while(key == d[i] && i < Size){
               index[++count] = i++;
            }
            return (count);
         }
      }
   }
   return (-1);
}

void main(void)
{
   static int d[Size]={1,9,31,35,75,87,88,91,95,157,163,387,391,391,472,789};
   int key;
   int i, index[Size+1], count=-1;

   clrscr( );
   while(true){
      print_org_data(d, Size);
      printf("�п�J�n�j�M����� K (�n�����ɿ�J-1) : ");
      scanf("%d",&key);
      if(key == -1) break;
      else;
      count = b_searching(d, 0, Size-1, key, index);
      if(count >= 0){
         for(i = 0; i <= count; i++)
            printf("---> ���F�I d[%d] = %d\n",index[i],key);
         printf("===> �b�}�C d ���`�@�� %d ����ȲŦX�j�M����I\n\n",count+1);
      }
      else
         printf("===> �b�}�C d ���j�M������� %d�I\n\n",key);
   }
}