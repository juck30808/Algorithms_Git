/*****************************************************************/
/*�i�{���W�١j: 3_queue.c                                        */
/*�i�{���\��j: �H��V�쵲��C��@ queue ���c                    */
/*�i��Ƶ��c�j: ��V�쵲��C(singly linked list)�A�`�I���c       */
/*****************************************************************/
/*�i�ܼƦW�٤Υγ~�j                                             */
/* struct node : �w�q node ���@�Ӹ`�I���c                        */
/*       data : �Ψ��x�s�`�I��ƭ�                               */
/*       link : ���@�� node ���СA�����V�U�@�Ӹ`�I               */
/*      front : ���@�� node ���СA�����V queue ���e��(��C���Y)  */
/*       rear : ���@�� node ���СA�����V queue ������(��C����)  */
/*****************************************************************/

#include <stdio.h>
#define N 6

void create_empty_queue(void);
void delete_all_queue(void);
int empty(void);
void insert_into_queue(int key);
int  delete_from_queue(void);

/*------------------------------*/
/*   �w�q node ���@�Ӹ`�I���c   */
/*------------------------------*/
struct node{        	/* �w�q�@�ӳ�V�쵲�`�I���c             */
   int data;		/* data �Ψ��x�s�`�I��ƭ�	        */
   struct node *link;   /* ���@�� node ���СA�����V�U�@�Ӹ`�I   */
};
struct node *front, *rear;

/*---------------------------------------------------*/
/*   ���ͤ@�ӪŦ�C�A���u�� front �� rear ��Ӹ`�I   */
/*---------------------------------------------------*/
void create_empty_queue(void)      /* Constructor */
{
   front = (struct node *) malloc(sizeof(struct node));
   rear = (struct node *) malloc(sizeof(struct node));
   front->link = NULL;
   rear->link = NULL;
}

void free_all_queue(void)        /* Destructor */
{
   struct node *this_node, *temp_node;

   if (front->link != NULL)
      {
        this_node = front->link;
        while(this_node->link != NULL)
          {
            temp_node = this_node;
            this_node = this_node->link;
            free(temp_node);
          }
        free(this_node);
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
   if(front->link == NULL)      /* queue is empty */
      return 1;                 /* true           */  
   else 
      return 0;                 /* false          */
}

/*----------------------------------*/
/*   �N���(key)��J queue ������   */
/*----------------------------------*/
void insert_into_queue(int key)
{
   struct node *new_node, *temp_node;

   new_node = (struct node *) malloc(sizeof(struct node));

   new_node->data = key;
   new_node->link = NULL;

   if (front->link == NULL)     /* queue is empty */
      { 
        front->link = new_node;
        rear->link = new_node;
      }
   else
      {
        temp_node = rear->link;
        temp_node->link = new_node;
        rear->link = new_node;
      } 
}

/*-----------------------------*/
/*   �� queue ���e�ݧR�����   */
/*-----------------------------*/
int delete_from_queue(void)
{
   int key;
   struct node *temp_node;

   temp_node = front->link;
   front->link = temp_node->link;
   key = temp_node->data;
   free(temp_node);  

   return(key);
}

void main(void)
{
   int i;
   int a[N] = {0, 1, 2, 3, 4, 5};

   create_empty_queue( );

   printf("\n�i�N��Ʃ�J queue �����ݡj...\n");
   for(i = 0; i < N; i++)
      {
        printf("  �B�J <%d> ��J %d\n",i,a[i]);
        insert_into_queue(a[i]);
      }

   printf("\n�i�� queue ���e�ݨ��X��ơj...\n");
   i = 0;

   while(! empty())       /*while(front->link != NULL) */
      printf("  �B�J <%d> ���X %d\n",i++,delete_from_queue());

   free_all_queue( );
}