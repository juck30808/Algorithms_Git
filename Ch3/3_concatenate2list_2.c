/******************************************************************/
/**�i�{���W�١j: 3_concatenate2list_2.c                           */
/**�i�{���\��j: �H�N��ӳ�V�쵲��C�X�֦��@�Ӧ�C               */
/**�i��Ƶ��c�j: ��V�쵲��C(singly linked list)�A�`�I���c       */
/******************************************************************/
/**�i�ܼƦW�٤Υγ~�j                                             */
/** struct node : �w�q node ���@�Ӹ`�I���c                        */
/**       data : �Ψ��x�s�`�I��ƭ�                               */
/**       link : ���@�� node ���СA�����V�U�@�Ӹ`�I               */
/**      front : ���@�� node ���СA�����V��V�쵲��C���e��       */
/**       rear : ���@�� node ���СA�����V��V�쵲��C������       */
/******************************************************************/

#include <stdio.h>
#define N 6

void create_list_x(void);
void create_list_y(void);
void create_list_z(void);
void cancatenate(struct node *front_x, struct node *rear_x,
		 struct node *front_y, struct node *rear_y,
		 struct node *front_z, struct node *rear_z);
void print(struct node *front_);
void length(struct node *front_);
 
/* ------------------------------*/
/*    �w�q node ���@�Ӹ`�I���O   */
/* ------------------------------*/
struct node{        	        /* �w�q�@�ӳ�V�쵲�`�I���c           */
   int data;		        /* data �Ψ��x�s�`�I��ƭ�	      */
   struct node *link;	        /* ���@�� node ���СA�����V�U�@�Ӹ`�I */
};
struct node *front_1, *rear_1;
struct node *front_2, *rear_2;
struct node *front_3, *rear_3;

/* ---------------------------------------------------*/
/*    ���ͦ�Clist_1�A���u�� front �� rear ��Ӹ`�I   */
/* ---------------------------------------------------*/
void create_list_1(void)               /* Constructor */
{
   front_1 = (struct node *) malloc(sizeof(struct node));
   rear_1 = (struct node *) malloc(sizeof(struct node));
   front_1->link = NULL;
   rear_1->link = NULL;
}

/* ---------------------------------------------------*/
/*    ���ͦ�Clist_2�A���u�� front �� rear ��Ӹ`�I   */
/* ---------------------------------------------------*/
void create_list_2(void)               /* Constructor */
{
   front_2 = (struct node *) malloc(sizeof(struct node));
   rear_2 = (struct node *) malloc(sizeof(struct node));
   front_2->link = NULL;
   rear_2->link = NULL;
}

/* ---------------------------------------------------*/
/*    ���ͦ�Clist_3�A���u�� front �� rear ��Ӹ`�I   */
/* ---------------------------------------------------*/
void create_list_3(void)               /* Constructor */
{
   front_3 = (struct node *) malloc(sizeof(struct node));
   rear_3 = (struct node *) malloc(sizeof(struct node));
   front_3->link = NULL;
   rear_3->link = NULL;
}

/* ---------------------------------------*/
/*    �N���(key)���J��V�쵲��C������   */
/* ---------------------------------------*/
void insert(int key, struct node *front_, struct node *rear_)
{
   struct node *new_node, *temp_node;

   new_node = (struct node *) malloc(sizeof(struct node));

   new_node->data = key;
   new_node->link = NULL;

   if (front_->link == NULL)              /* queue is empty */
      {
        front_->link = new_node;
        rear_->link = new_node;
      } 
   else
      {
        temp_node = rear_->link;
        temp_node->link = new_node;
        rear_->link = new_node;
      }
}


/*-------------------------------------------------------------------*/
/*    �Nfront_y��C�X�֨�front_x��C����A�åHfront_z���s��C���e��  */
/* ------------------------------------------------------------------*/
void cancatenate(struct node *front_x, struct node *rear_x,
		 struct node *front_y, struct node *rear_y,
		 struct node *front_z, struct node *rear_z)
{
   struct node *this_node;

   if (front_x->link == NULL)                      /* front_x ���Ŧ�C */
      { 
        front_z->link = front_y->link;
        rear_z->link = rear_y->link;
      }
   else
      {
        if (front_y->link == NULL)                 /* front_y ���Ŧ�C */
           {
             front_z->link = front_x->link;
             rear_z->link = rear_x->link;
           }
      else                              /* front_x, front_y ���D�Ŧ�C */
           {
             front_z->link = front_x->link;
             this_node = rear_x->link;
             this_node->link = front_y->link;
             rear_z->link = rear_y->link;
           }
      } 
}


/* ---------------------------*/
/*    �q front �}�l�C�L���   */
/* ---------------------------*/
void print(struct node *front_)
{
   struct node *this_node;

   if (front_->link != NULL)
      {
        this_node = front_->link;
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

/* -------------------- */
/*    �p���C������    */
/* -------------------- */
void length(struct node *front_)
{
   int count = 0;
   struct node *this_node;

   if (front_->link != NULL)
      {
        this_node = front_->link;
        while(this_node->link != NULL)
             {
               count ++;
               this_node = this_node->link;
             }
        count ++;
        printf(" ==> ��C���׬� : %d\n",count);
      }
   else
        printf(" !!! �Ŧ�C�A��C���׬� : 0 \n");
}

void main(void)
{
   int i;
   int a[N] = {0, 1, 2, 3, 4, 5};
   int b[N] = {10, 11, 12, 13, 14, 15};

   create_list_1( );
   create_list_2( );
   create_list_3( );

   clrscr( );
   for(i = 0; i < N; i++)
      {
        insert(a[i], front_1, rear_1);
      }
   printf("\n�i��V�쵲��C 1�j...\n");
   print(front_1);
   length(front_1);

   for(i = 0; i < N; i++)
      {
        insert(b[i], front_2, rear_2);
      }
   printf("\n�i��V�쵲��C 2�j...\n");
   print(front_2);
   length(front_2);

   printf("\n�i��V�쵲��C 3�j...\n");
   print(front_3);
   length(front_3);

   cancatenate(front_1, rear_1, front_2, rear_2, front_3, rear_3);
   printf("\n�i �X�᪺֫��V�쵲��C�j...\n");
   print(front_3);
   length(front_3);
}
