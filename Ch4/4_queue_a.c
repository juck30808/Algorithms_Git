/*********************************************************/
/*�i�{���W�١j: 4_queue_a.c                              */
/*�i�{���\��j: �H�}�C��@��C                           */
/*�i��Ƶ��c�j: �}�C���c                                 */
/*       ��J : ��Ƹ�� 1, 2, 3, 4, 5, 6, 7, 8, 9, 10   */
/*       ��X : 10, 9, 8, 7, 6, 5, 4, 3, 2, 1            */
/*********************************************************/
/*�i�ܼƦW�٤Υγ~�j                                     */
/*      data[] : �w�q data[] ���@�Ӧ�C���c              */
/*       front : ���@�Ӱ}�C���ޡA�����V��C�Y��          */
/*        rear : ���@�Ӱ}�C���ޡA�����V��C����          */
/*********************************************************/

#include <stdio.h>

#define n 5
#define true 1
#define false 0

int queue[n];
int front = 0;
int rear = -1;

/*----------------------*/
/*   �P�_�O�_���Ŧ�C   */
/*----------------------*/
int empty(void)
{
   if(front > rear){
      printf("\n==>��C�w�šI\n");
      return true;
   }
   else
      return false;

   /* return (front > rear) ? true : false; */
}

/*----------------------*/
/*   �P�_��C�O�_����   */
/*----------------------*/
int full(void)
{
   if(rear >= n - 1){
      printf("\n==>��C�w���I\n");
      return true;
   }
   else
      return false;

   /* return (rear >= n - 1) ? true : false; */
}

/*------------------------------------*/
/*   �N��� queue_data ��J��C����   */
/*------------------------------------*/ 
void insert_into_queue(int queue_data)
{
   queue[++rear] = queue_data;
   printf("�N %d ��J��C����\n",queue_data);   
}

/*------------------------*/
/*   �R����C�Y�ݪ����   */
/*------------------------*/
int delete_from_queue()
{
   return queue[front++];    
}

void main(void)
{ 
   int i=0;
   int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

   clrscr( );
   printf("==> �w�g�ŧi�@�Ӯe�q�� %d ����C ! ...\n",n);
   printf("\n==>�N���1,2,3,4,5,6,7,8,9,10�̧ǩ�J��C...\n");
   while(! full( )){
      printf("   �B�J(%d):",i+1); 
      insert_into_queue(data[i]);
      i++;
   }
   i=1;
   printf("\n==>�R����C�Y�ݪ����...\n");
   while(! empty())
      printf("   �B�J(%d):�R�� %d \n",i++ ,
              delete_from_queue());
}