/*********************************************************/
/*�i�{���W�١j: 4_stack_a.c                              */
/*�i�{���\��j: �H�}�C��@���|                           */
/*       ��J : ��Ƹ�� 1, 2, 3, 4, 5, 6, 7, 8, 9, 10   */
/*       ��X : 5,4,3,2,1                                */
/*�i��Ƶ��c�j: �}�C���c                                 */
/*********************************************************/
/*�i�ܼƦW�٤Υγ~�j                                     */
/*   stack[5] : ���@�Ӱ}�C�A���Ψ��x�s���|���           */
/*        top : ���@�Ӱ}�C���ޡA�����V���|stack������    */
/*********************************************************/

#include <stdio.h>

#define n 5
#define true 1
#define false 0

int stack[n]; /* �ŧi stack[n] ���@�Ӱ��| */
int top = -1;

int  empty(void);
int  full(void);
void push(int stack_data);
int  pop();

/*-----------------------*/
/*    �P�_�O�_���Ű��|   */
/*-----------------------*/
int empty(void)
{
   if(top < 0){
      printf("\n==>���|�w�šI\n");
      return true;
   }
   else
      return false;

   /* return (top < 0) ? true : false; */  
}

/*----------------------*/
/*   �P�_���|�O�_����   */
/*----------------------*/
int full(void)
{
   if(top >= n - 1){
      printf("\n==>���|�w���I\n");
      return true; 
   }
   else 
      return false;

   /* return (top >= n - 1) ? true : false; */
}

/*--------------------------------*/
/*   �N��� stack_data ��J���|   */
/*--------------------------------*/
void push(int stack_data)
{
   stack[++top] = stack_data;
   printf("�N %d ��J���|\n",stack_data);        
}

/*------------------------*/
/*   �R�����|���ݪ����   */
/*------------------------*/
int pop()
{
   return stack[top--];    
}

void main(void)
{
   int i=0;
   int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

   clrscr( );
   printf("==> �w�g�ŧi�@�Ӯe�q�� %d �����| ! \n",n);
   printf("\n==>�N���1,2,3,4,5,6,7,8,9,10�̧ǩ�J���|...\n");
   while(! full( )){
      printf("   �B�J(%d):",i+1);  
      push(data[i]);   
      i++;
   }
   i=1;
   printf("\n==>�۰��|���ݨ��X���...\n");
   while(! empty())
      printf("   �B�J(%d):�۰��|���ݨ��X %d \n",i++, pop());
}