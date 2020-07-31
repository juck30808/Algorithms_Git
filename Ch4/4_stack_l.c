/*********************************************************/
/*�i�{���W�١j: 4_stack_l.c                              */
/*�i�{���\��j: �H�쵲��C��@���|                       */
/*�i��Ƶ��c�j: �쵲��C�B���|                           */
/*       ��J : ��Ƹ�� 1, 2, 3, 4, 5, 6, 7, 8, 9, 10   */
/*       ��X : 10, 9, 8, 7, 6, 5, 4, 3, 2, 1            */
/*********************************************************/
/*�i�ܼƦW�٤Υγ~�j                                     */
/* struct node : �w�q node ���@�Ӹ`�I���c                */
/*        data : �Ψ��x�s�`�I����ƭ�                    */
/*        link : ���`�I���СA�����V�U�@�Ӹ`�I            */
/*       front : ���`�I���СA�����V���|���Y��            */
/*        rear : ���`�I���СA�����V���|������            */
/*********************************************************/

#include <stdio.h>

#define n 10
#define null 0

void create_stack(void);
void free_stack(void);
int  empty(void);
void push(int stack_data);
int  pop(void);

struct node{ 		/* �w�q�@�ӳ�V�쵲�`�I���c   */
   int data;		/* data�G�ΨӦs���Ƹ��     */
   struct node *link;	/* link�G���СA���V�U�@�Ӹ`�I */
};
struct node *top;

void main(void)
{
   int i;
   int data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

   clrscr();
   create_stack();
   printf("\n==>�N���1,2,3,4,5,6,7,8,9,10�̧ǩ�J���|...\n");
   for(i = 0; i < n; i++){
      printf("   �B�J(%d):",i+1); 
      push(data[i]);
   }
   printf("\n==>�۰��|���ݨ��X���...\n");
   i = 1;
   while(! empty()){
      printf("   �B�J(%d):�۰��|���ݨ��X %d \n",i++, pop());
   }
   free_stack();
}

/*-------------------------------------*/
/*   ���ͤ@�ӪŰ��|�A���u�� top �`�I   */
/*-------------------------------------*/
void create_stack(void)
{
   top = (struct node *) malloc(sizeof(struct node));
   top->link = null;
   printf("==> �w�g���ͤ@�ӥH�쵲��C��@���Ű��| ! \n");
}

/*----------------------------------------*/
/*   �R�����|�A����Ҧ��`�I�Ҧ����O����   */
/*----------------------------------------*/
void free_stack(void)
{
   struct node *x, *y;

   if(top->link != null){
      x = top->link;
      while(x->link != null){
         y = x;
         x = x->link;
         free(y);
      }
      free(x);
   }
   else;
   free(top);
}

/*-----------------------------*/
/*   �P�_ stack �O�_�ŵL���   */
/*-----------------------------*/
int empty(void)
{
   if(top->link == null)   /* �Ű��| */
      return 1;            /* true   */  
   else
      return 0;            /* false  */
}

/*--------------------------------*/
/*   �N��� stack_data ��J���|   */
/*--------------------------------*/
void push(int stack_data)
{
   struct node *new_node;

   new_node = (struct node *) malloc(sizeof(struct node));

   new_node->data = stack_data;
   new_node->link = top->link;
   top->link = new_node;

   printf("�N %d ��J���|\n",stack_data); 
}

/*------------------------*/
/*   �R�����|���ݪ����   */
/*------------------------*/
int pop(void)
{
   int stack_data;
   struct node *x;

   x = top->link;
   top->link = x->link;
   stack_data = x->data;
   free(x);

   return(stack_data);
}

