/*********************************************************/
/*�i�{���W�١j: 9_s_search.c                             */
/*�i�{���\��j: �`�Ƿj�M                                 */
/*       ��J : �@�ե��g�ƧǪ����                       */
/*              �n�j�M����� key                         */
/*       ��X : �j�M�����G                               */
/*�i��Ƶ��c�j: �}�C���c                                 */
/*********************************************************/
/*�i�ܼƦW�٤Υγ~�j                                     */
/*        d[] : �x�s�ݷj�M�����                         */
/*     Size,n : �}�C d ���j�p(�����Ӽ�)                  */
/*********************************************************/

#include <stdio.h>
#define Size 16
#define true 1

void print_org_data(const int d[], int n) ;
void s_searching(int d[], int low, int high, int key);

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
/*   �`�Ƿj�M   */
/*--------------*/
void s_searching(int d[], int low, int high, int key)
{
   int i, count;

   count = 0;
   for(i = low; i <= high; i++){
      if(d[i] == key){
         count++;
         printf("---> ���F�I d[%d] = %d\n",i,d[i]);
      }
   }
   if(count > 0)
      printf("===> �b�}�C d ���`�@�� %d ����ȲŦX�j�M����I\n\n",count);
   else
      printf("===> �b�}�C d ���j�M������� %d �I\n\n",key);
}

void main(void)
{
   static int d[Size]={1,75,387,88,35,9,789,157,87,91,95,391,472,31,163,391};
   int key;

   clrscr( );
   while(true){
      print_org_data(d,Size);
      printf("�п�J�n�j�M����� K (�n�����ɿ�J-1) : ");
      scanf("%d",&key);
      if(key == -1) break;
      s_searching(d,0,Size-1,key);
   }
}