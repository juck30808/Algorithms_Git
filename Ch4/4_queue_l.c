/*********************************************************/
/*�i�{���W�١j: 4_queue_l.c                              */
/*�i�{���\��j: �H��V�쵲��C��@��C                   */
/*�i��Ƶ��c�j: �쵲��C�B��C                           */
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

void create_queue(void);
void free_queue(void);
int  empty(void);
void insert_into_queue(int queue_data);
int  delete_from_queue(void);

/*------------------------------*/
/*   �w�q node ���@�Ӹ`�I���c   */
/*------------------------------*/
struct node{        	/* �w�q�@�ӳ�V�쵲�`�I���c   */
   int data;		/* data�ΨӦs���Ƹ��	      */
   struct node *link;   /* link�G���СA���V�U�@�Ӹ`�I */
};
struct node *front, *rear;

/*---------------------------------------------------*/
/*   ���ͤ@�ӪŦ�C�A���u�� front �� rear ��Ӹ`�I   */
/*---------------------------------------------------*/
void create_queue(void)
{
   front = (struct node *) malloc(sizeof(struct node));
   rear = (struct node *) malloc(sizeof(struct node));
   front->link = null;
   rear->link = null;
   printf("==> �w�g���ͤ@�ӥH�쵲��C��@���Ŧ�C ! \n");
}

/*----------------------------------------*/
/*   �R����C�A����Ҧ��`�I�Ҧ����O����   */
/*----------------------------------------*/
void free_queue(void)
{
   struct node *x, *y;

   if(front->link != null){
      x = front->link;
      while(x->link != null){
         y = x;
         x = x->link;
         free(y);
      }
      free(x);
   }
   else;

   free(front);
   free(rear);
}

/*-----------------------------*/
/*   �P�_ queue �O�_�ŵL���   */
/*-----------------------------*/
int empty(void)
{
   if(front->link == null)   /* �Ŧ�C */
      return 1;              /* true   */  
   else
      return 0;              /* false  */
}

/*--------------------------------*/
/*   �N��� queue_data ��J��C   */
/*--------------------------------*/
void insert_into_queue(int queue_data)
{
   struct node *new_node, *temp_node;

   new_node = (struct node *) malloc(sizeof(struct node));

   new_node->data = queue_data;
   new_node->link = null;

   if(front->link == null){   /* �Ŧ�C */
      front->link = new_node;
      rear->link = new_node;
   }
   else{
      temp_node = rear->link;
      temp_node->link = new_node;
      rear->link = new_node;
   }
   printf("�N %d ��J��C����\n",queue_data);   
}

/*------------------------*/
/*   �R����C�Y�ݪ����   */
/*------------------------*/
int delete_from_queue(void)
{
   int queue_data;
   struct node *x;

   x = front->link;
   front->link = x->link;
   queue_data = x->data;
   free(x);

   return(queue_data);
}

void main(void)
{
   int i;
   int data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

   clrscr();
   create_queue( ); 
   printf("\n==>�N���1,2,3,4,5,6,7,8,9,10�̧ǩ�J��C...\n");
   for(i = 0; i < n; i++){
      printf("   �B�J(%d):",i+1); 
      insert_into_queue(data[i]);
   }
   i = 1;
   printf("\n==>�R����C�Y�ݪ����...\n");
   while(! empty()){   
      printf("   �B�J(%d):�R�� %d \n",i++,
              delete_from_queue());
   }
   free_queue( );
}