/*********************************************************/
/*�i�{���W�١j: 8_shell_sort.c                           */
/*�i�{���\��j: �¦ձƧǪk�Ы��u��Ȥ�����v�Ƨ�         */
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
void swap(int *x, int *y);
void shell_sort_ascending(int d[], int n, int s);

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

/*---------------------------*/
/*   �N x,y ���ܼƤ��Ȥ���   */
/*---------------------------*/
void swap(int *x, int *y)
{
   int z = *x;

   *x = *y;
   *y = z;
}

/*----------------------------------------------------------*/ 
/*   �¦ձƧǪk                                             */ 
/*     1.�}�C d �@�� n �Ӥ���                               */ 
/*     2.���u��Ȥ�����v�Ƨ�                               */ 
/*     3.�N�}�C d ����Ȥ��� s ��(�P�ժ���ȳ��۶Z s �Ӧ첾)*/ 
/*----------------------------------------------------------*/ 
void shell_sort_ascending(int d[], int n, int s)
{
   int i, j, a, step;
   int temp;

   step = 0;
   s = 3;
   do{
      for(a = 0; a < s; a++){
         for(i = a + s; i <= (n-1)/s*s + a && i <= n-1; i = i + s){
            temp = d[i];
            for(j = i - s; j >= 0; j = j - s){
               if(d[j] > temp)
                  d[j+s] = d[j];
               else
                   break;
            }
            d[j+s] = temp;
         }
      }
      printf(" ��%d�^�X ==> ",++step);
      print_array_data(d, n);
      s = s - 1;
   }while(s >= 1);
}


void main(void)
{
   int d[Size]={83,66,55,21,88,18,88,99};

   print_org_data(d, Size); /* �C�L�Ƨǫe����ȸ�� */

   /* �N�}�C d �̪� Size ����ȫ��u��Ȥ�����v�Ƨ� */
   shell_sort_ascending(d,Size,3);
}