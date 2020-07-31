/**********************************************************************/
/*�i�{���W�١j: 3_doublelist.c                                        */
/*�i�{���\��j: �`�I��ƥѤp�ܤj�ƧǤ����V�쵲��C����ƼW�R�P�C�L    */
/*�i��Ƶ��c�j: ���V�쵲��C(double linked list)�A�`�I���c            */
/**********************************************************************/
/*�i�ܼƦW�٤Υγ~�j                                                  */
/* struct node : �w�q node ���@�Ӹ`�I���c                             */
/*       data : �Ψ��x�s�`�I��ƭ�                                    */
/*     r_link : ���@�� node ���СA�����V�U�@�Ӹ`�I                    */
/*     l_link : ���@�� node ���СA�����V�e�@�Ӹ`�I                    */
/*      front : ���@�� node ���СA�����V���V�쵲��C���e��(��C���Y)  */
/*       rear : ���@�� node ���СA�����V���V�쵲��C������(��C����)  */
/**********************************************************************/

#include <stdio.h>
#define N 6

void create_double_list(void);
void free_double_list(void);
int  empty(void);
void insert_node(int key);
void delete_node(int key);
void print_front(void);
void print_rear(void);

/*------------------------------*/
/*    �w�q node ���@�Ӹ`�I���O  */
/*------------------------------*/
struct node{        	      /* �w�q�@�����V�쵲�`�I���c */
   int data;
   struct node *l_link;
   struct node *r_link;
};
struct node *front, *rear;


/*---------------------------------------------------*/
/*   ���ͤ@�ӪŦ�C�A���u�� front �� rear ��Ӹ`�I   */
/*---------------------------------------------------*/
void create_double_list(void)            /* Constructor */
{
   front = (struct node *) malloc(sizeof(struct node));
   rear = (struct node *) malloc(sizeof(struct node));
   front->r_link = NULL;
   rear->r_link = NULL;
}

void free_double_list(void)              /* Destructor */
{
   struct node *this_node, *temp_node;

   if (! empty())                        /* �Y�D�Ŧ�C */
      { 
        this_node = front->r_link;
        while(this_node->r_link != front)  /* �Y�D�̫�@�Ӹ`�I */
          {
            temp_node = this_node;
            this_node = this_node->r_link;
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
   if(front->r_link == NULL) /* queue is empty */
      return 1;              /* true           */  
   else
      return 0;              /* false          */
}

/*--------------------------------------------------------*/ 
/*   �N���(key)���J���V�쵲��C���A�ë��p�ܤj���ǱƦC    */
/*--------------------------------------------------------*/
void insert_node(int key)
{
   struct node *new_node, *prev_node, *this_node;
   
   new_node = (struct node *) malloc(sizeof(struct node));

   new_node->data = key;
   new_node->l_link = NULL;
   new_node->r_link = NULL;
  
   if (empty())                     /* �Ŧ�C�A���J�Ĥ@�Ӹ`�I��front���� */
      {
        front->r_link = new_node;
        rear->r_link = new_node;
        new_node->l_link = front;
        new_node->r_link = front;   /* �ڭ̱N�̫�@�Ӹ`�I��r_link���Vfront */
      }
   else
      {
        this_node = front->r_link;
        if (key < this_node->data)  /* ���J���C���e�� */
           {  
             front->r_link = new_node;
             new_node->r_link = this_node;
             new_node->l_link = front;
           }
        else
           {
             while(this_node->r_link != front)    /* ���J���C���� */
               {
                 prev_node = this_node;
                 this_node = this_node->r_link;
                 if (key < this_node->data)
                    {
                      prev_node->r_link = new_node;
                      new_node->l_link = prev_node;               
                      new_node->r_link = this_node;
                      this_node->l_link = new_node; 
                      return;
                    }
                 else;           
               }
             this_node->r_link = new_node;   /* ���J���C������ */
             new_node->l_link = this_node;  
             new_node->r_link = front;       /* �ڭ̱N�̫�@�Ӹ`�I��r_link���Vfront */
             rear->r_link = new_node;
           } 
      }
}

/*-----------------------------------*/
/*   �����V�쵲��C���R�����(key)   */
/*-----------------------------------*/
void delete_node(int key)
{
   struct node *this_node, *prev_node, *temp_node;

   prev_node = front;
   this_node = front->r_link;

   while(this_node->r_link != front)          /* ���O�̫�@�Ӹ`�I�� */
     {
       if (key == this_node->data)
          {
            temp_node = this_node;
            prev_node->r_link = this_node->r_link;
            this_node->r_link->l_link = prev_node;
            free(temp_node);
            return;
          }
       prev_node = this_node;
       this_node = this_node->r_link;
     }
   if (key == this_node->data)                /* �P�_�̫�@�Ӹ`�I */
      {  
        temp_node = this_node;
        prev_node->r_link = front;            /* �ڭ̱N�̫�@�Ӹ`�I��r_link���Vfront */
        rear->r_link = prev_node;
        free(temp_node);
      }
   else
        printf("... �䤣���� %d \n",key);
}

/*-------------------------------------*/
/*   �q front �}�l�C�L���(�Ѥp�ܤj)   */
/*-------------------------------------*/
void print_front(void)
{
   struct node *this_node;
   
   if (! empty())                             /* �Y�D�Ŧ�C */
      {
        this_node = front->r_link;
        printf(" ==> ��C���e�� : ");

        while(this_node->r_link != front)
          {
            printf("%d ->",this_node->data); 
            this_node = this_node->r_link;
          }
        printf("%d \n",this_node->data); 
      }
   else 
        printf(" !!! �Ŧ�C\n");
}

/*------------------------------------*/
/*   �q rear �}�l�C�L���(�Ѥj�ܤp)   */
/*------------------------------------*/
void print_rear(void)
{
   struct node *this_node;
   
   if (! empty())                              /* �Y�D�Ŧ�C */
      {                           
        this_node = rear->r_link;
        printf(" ==> ��C���e�� : ");

        while(this_node->l_link != front)
          {
            printf("%d ->",this_node->data); 
            this_node = this_node->l_link;
          }
        printf("%d \n",this_node->data);
      }
   else 
        printf(" !!! �Ŧ�C\n");
}

void main(void)
{ 
   int i;
   int a[N] = {5, 65, 31, 83, 78, 21};

   create_double_list( );

   clrscr( );
   printf("\n�i�N��ƴ��J���V�쵲��C�A�ëO����ƥѤp�ܤj���Ƨǡj...\n");
   for(i = 0; i < N; i++)
      {
        printf("\n �B�J <%d> ���J %d \n",i,a[i]);
        insert_node(a[i]);
        print_front();
      }

   printf("\n�i�R�� 5�j...\n");
   delete_node(5);
   print_front();
 
   
   printf("\n�i�R�� 83�j...\n");
   delete_node(83);
   print_front(); 
   
   
   printf("\n�i�R�� 31�j...\n");
   delete_node(31);
   print_front(); 

   printf("\n�i�qrear��front�C�L(�Ѥj�ܤp)�j...\n");   
   print_rear();

   free_double_list( );
}