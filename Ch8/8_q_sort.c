/*********************************************************/
/*�i�{���W�١j: 8_q_sort.c                               */
/*�i�{���\��j: �ֳt�ƧǪk�Ы��u��Ȥ�����v�Ƨ�         */
/*       ��J : �@�ե��g�ƧǪ�������                   */
/*       ��X : �C�@�^�X�ƧǤ����G                       */
/*�i��Ƶ��c�j: �}�C���c                                 */
/*********************************************************/
/*�i�ܼƦW�٤Υγ~�j                                     */
/*        d[] : �x�s�ݱƧǪ���ȥH�αƧǹL�{���C�@�^�X�� */
/*              ���G                                     */
/*     Size,n : �}�C d ���j�p(�����Ӽ�)                  */
/*********************************************************/

#include <stdio.h>
#define Size 8
#define true 1

int step = 0;

void print_org_data(const int d[], int n);
void print_array_data(const int d[], int n);
void swap(int *x, int *y);
int divide_point(int d[], int low, int high);
void quick_sort_ascending(int d[], int low, int high);

/*------------------------------------------------*/
/*   �C�L�Ƨǫe����ȸ��(�}�C d �@�� n �Ӥ���)   */
/*------------------------------------------------*/
void print_org_data(const int d[], int n) 
{
   int i;

   clrscr( );
   printf("�}�C����   d[0] [1] [2] [3] [4] [5] [6] [7] \n");
   printf("----------------------------------------------\n");
   printf("<�Ƨǫe> ==> ");
   for(i = 0; i < n; i++){
      printf("%2d  ",d[i]);
   }
   printf("\n----------------------------------------------\n");
}

/*---------------------------------------------*/
/*   �L�X�}�C d �����e(�}�C d �@�� n �Ӥ���)   */ 
/*---------------------------------------------*/
void print_array_data(const int d[], int n)
{
   int i;

   printf("�}�C����   d[0] [1] [2] [3] [4] [5] [6] [7] \n");
   printf("----------------------------------------------\n");
   printf("             ");
   for(i = 0; i < n; i++){
      printf("%2d  ",d[i]);
   }
   printf("\n");
}

/*---------------------------*/
/*   �N x,y ���ܼƤ��Ȥ���   */
/*---------------------------*/
void swap(int *x, int *y)
{
   int z = *x;

   *x = *y;
   *y = z;
}

/*------------------*/
/*   ��X�����I j   */
/*------------------*/
int divide_point(int d[], int low, int high)
{
   int i, j, key;  

   key = d[low];
   i = low;
   j = high + 1;
   while(true){
      while(d[++i] < key); 
      while(d[--j] > key);
      if(i < j){
         printf("==> i=%d, j=%d , i < j",i,j);
         printf("==> �N(d[%d]=%d,d[%d]=%d)�洫��m�o��:\n",i,d[i],j,d[j]);
         swap(&d[i], &d[j]);
         print_array_data(d, Size);
      }
      else
         break;
   }
   printf("==> i=%d, j=%d , i >= j",i,j);
   printf("==> �N(d[%d]=%d,d[%d]=%d)�洫��m�o��:\n",low,d[low],j,d[j]);
   swap(&d[low], &d[j]);
   print_array_data(d, Size); 
   return j;
}

/*-------------------------------*/
/*   �ֳt�ƧǪk                  */
/*     1.�}�C d �@�� n �Ӥ���    */
/*     2.���u��Ȥ�����v�Ƨ�    */
/*-------------------------------*/
void quick_sort_ascending(int d[], int low, int high)
{
   int i, j;
   
   if(low < high){
      j = divide_point(d, low, high); /* ��X�����I j */
      printf("==> �H d[%d]=%d �������I\n\n",j,d[j]);

      if((j-1) > low){
         printf("==> �Ƨ� d[%d]-d[%d]\n",low,j-1);
         quick_sort_ascending(d,low,j-1);
      }

      if(high > (j+1)){
         printf("==> �Ƨ� d[%d]-d[%d]\n",j+1,high);
         quick_sort_ascending(d,j+1,high);
      }
   }
}

void main(void)
{
   int d[Size]={83,66,55,21,88,18,88,99};

   print_org_data(d, Size); /* �C�L�Ƨǫe����ȸ�� */

   /* �N�}�C d �̪� d[0] �� d[Size-1] ����ȫ��u��Ȥ�����v�Ƨ� */
   quick_sort_ascending(d,0,Size-1);
}