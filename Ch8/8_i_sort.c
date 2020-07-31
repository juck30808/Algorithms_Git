/*********************************************************/
/*�i�{���W�١j: 8_i_sort.c                               */
/*�i�{���\��j: ���J�ƧǪk�Ы��u��Ȥ�����v�Ƨ�         */
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

void print_org_data(const int d[], int n);
void print_array_data(const int d[], int n);
void insertion_sort_ascending(int d[], int n);

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

   for(i = 0; i < n; i++){
      printf("%2d  ",d[i]);
   }
   printf("\n");
}

/*-------------------------------*/
/*   ���J�ƧǪk                  */
/*     1.�}�C d �@�� n �Ӥ���    */
/*     2.���u��Ȥ�����v�Ƨ�    */
/*-------------------------------*/
void insertion_sort_ascending(int d[], int n)
{
   int i, j;
   int temp;

   for(i = 1; i <= n-1; i++){
      temp = d[i];
      for(j = i-1; j >= 0; j--){
         if(d[j] > temp) 
            d[j+1] = d[j];
         else
            break;
      }
      d[j+1] = temp;
      printf(" ��%d�^�X ==> ",i);
      print_array_data(d, n);
   }
}

void main(void)
{
   int d[Size]={83,66,55,21,88,18,88,99};

   print_org_data(d, Size); /* �C�L�Ƨǫe����ȸ�� */

   /* �N�}�C d �̪� Size ����ȫ��u��Ȥ�����v�Ƨ� */
   insertion_sort_ascending(d,Size);
}