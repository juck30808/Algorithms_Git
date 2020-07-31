/*******************************************************************/
/*�i�{���W�١j: 3_singlelist.c                                     */
/*�i�{���\��j: �`�I��ƥѤp�ܤj�ƧǤ���V�쵲��C����ƼW�R�P�C�L */
/*�i��Ƶ��c�j: ��V�쵲��C(singly linked list)�A�`�I���c         */
/*******************************************************************/
/*�i�ܼƦW�٤Υγ~�j                                               */
/* struct node : �w�q node ���@�Ӹ`�I���c                          */
/*       data : �Ψ��x�s�`�I��ƭ�                                 */
/*       link : ���@�� node ���СA�����V�U�@�Ӹ`�I                 */
/*      front : ���@�� node ���СA�����V��V�쵲��C���e��         */
/*       rear : ���@�� node ���СA�����V��V�쵲��C������         */
/*******************************************************************/

#include <stdio.h>
#define N 6

void create_single_list(void);
void free_single_list(void);
int  empty(void);
void insert_node(int key);
void delete_node(int key);
void print(void);
void reverse(void);


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
void create_single_list(void)      /* Constructor */
{
   front = (struct node *) malloc(sizeof(struct node));
   rear = (struct node *) malloc(sizeof(struct node));
   front->link = NULL;  
   rear->link = NULL;
}

void free_single_list(void)        /* Destructor */
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

/*----------------------*/
/*   �P�_�O�_���Ŧ�C   */
/*----------------------*/
int empty(void)
{
   if(front->link == NULL)                      /* �Ŧ�C */
      return 1;                                 /* true   */
   else
      return 0;                                 /* false  */
}

/*--------------------------------------------------------*/
/*    �N���(key)���J��V�쵲��C���A�ë��p�ܤj���ǱƦC   */
/*--------------------------------------------------------*/
void insert_node(int key)
{
   struct node *new_node, *prev_node, *this_node;
   
   new_node = (struct node *) malloc(sizeof(struct node));

   new_node->data = key;
   new_node->link = NULL;

   if (empty())                            /* �Ŧ�C�A���J�Ĥ@�Ӹ`�I��front���� */
      {
        front->link = new_node;
        rear->link = new_node;
      }
   else
      {
        this_node = front->link;
        if (key < this_node->data)                           /* ���J���C���e�� */
           {  
             front->link = new_node;
             new_node->link = this_node;
           }
        else
           {
             while(this_node->link != NULL)                    /* ���J���C���� */
               {  
                 prev_node = this_node;
                 this_node = this_node->link;
                 if (key < this_node->data)
                    {
                      prev_node->link = new_node;               
                      new_node->link = this_node;
                      return;
                    }
                 else;           
              }
            this_node->link = new_node;                        /* ���J���C���� */
            rear->link = new_node;
          } 
      }
}

/*-----------------------------------*/
/*    �۳�V�쵲��C���R�����(key)  */
/*-----------------------------------*/
void delete_node(int key)
{
   struct node *this_node, *prev_node, *temp_node;

   prev_node = front;
   this_node = front->link;

   while(this_node->link != NULL)                        /* ���O�̫�@�Ӹ`�I�� */
     {
       if (key == this_node->data)
          {
            temp_node = this_node;
            prev_node->link = this_node->link;
	    free(temp_node);
            return;
          }
       prev_node = this_node;
       this_node = this_node->link;
    }
 
   if (key == this_node->data)                               /* �P�_�̫�@�Ӹ`�I */
      {
        temp_node = this_node;
        prev_node->link = NULL;              /* �ڭ̱N�̫�@�Ӹ`�I��link���VNULL */
        rear->link = prev_node;
        free(temp_node);
      }
   else
      printf("... �䤣���� %d \n",key);
}

/*-------------------------------------*/
/*   �q front �}�l�C�L���(�Ѥp�ܤj)   */
/*-------------------------------------*/
void print(void)
{
   struct node *this_node;
    
   if (! empty())                                                 /* �Y�D�Ŧ�C */
      {
        this_node = front->link;
        printf(" ==> ��C���e�� : ");

        while(this_node->link != NULL)
          {
            printf("%d ->",this_node->data); 
            this_node = this_node->link;
          }
        printf("%d \n",this_node->data);
      }
   else 
      printf(" !!! �Ŧ�C\n");
}

/*------------------------*/
/*    �N��V�쵲��C����  */
/*------------------------*/
void reverse(void)
{
   struct node *prev_node, *this_node, *next_node;
   
   next_node = front->link;
   this_node = NULL;
   while(next_node->link != NULL)
     {
       prev_node = this_node;
       this_node = next_node;
       next_node = next_node->link; 
       this_node->link = prev_node;
     }
   next_node->link = this_node;
   front->link = next_node;
}


void main(void)
{
   int i;
   int a[N] = {5, 65, 31, 83, 78, 21};

   create_single_list( );

   clrscr( );
   printf("\n�i�N��ƴ��J��V�쵲��C�A�ëO����ƥѤp�ܤj���Ƨǡj...\n");
   for(i = 0; i < N; i++)
      {
        printf("\n  �B�J <%d> ���J %d\n",i,a[i]);
        insert_node(a[i]);
        print();
      }

   printf("\n�i�R�� 5�j...\n");
   delete_node(5);
   print();

   printf("\n�i�R�� 83�j...\n");
   delete_node(83);
   print();


   printf("\n�i�R�� 31�j...\n");
   delete_node(31);
   print(); 

   printf("\n�i�N��C����j...\n");   
   reverse();
   print();
   
   printf("\n�i�N��C����j...\n"); 
   reverse();
   print(); 

   free_single_list( );
}