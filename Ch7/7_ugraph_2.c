/**********************************************************************/
/*�i�{���W�١j: 7_ugraph_2.c                                          */
/*�i�{���\��j: �L�V�Ϫ��F����C��ܪk                                */
/*�i��Ƶ��c�j: ��V�쵲��C(singly linked list)�A�`�I���c            */
/**********************************************************************/
/*�i�ܼƦW�٤Υγ~�j                                                  */
/*    vertices : �L�V�Ϫ����I�Ӽ�                                     */
/*   v_list[N] : �ΥH��ܵL�V�Ϫ��F����C                             */
/**********************************************************************/

#include <stdio.h>
#define N    80
#define true 1

int vertices;
struct node{        	/* �w�q�@�ӳ�V�쵲�`�I���c           */
   int data;		/* data �Ψ��x�s�`�I��ƭ�	      */
   struct node *link;	/* ���@�� node ���СA�����V�U�@�Ӹ`�I */
};
struct node v_list[N];

void input_graph(void);
void adj_list(int i, int j);
void output_adj_list(void);

/*----------------------------------*/
/*   ��J�L�V�Ϫ���(���Ii�M���Ij)   */
/*----------------------------------*/
void input_graph(void)
{
   int i, j;

   clrscr( );
   printf("\n�п�J�L�V�Ϫ����I�� : ");
   scanf("%d",&vertices);

   if (vertices > 0)
      {
        for(i = 0; i < vertices; i++)
           {
             v_list[i].data = 0;
             v_list[i].link = NULL;
           } 
        printf("�п�J�L�V�Ϫ���");
        printf("(0<=�䪺�s��<=%d)...\n",vertices-1);
        while(true)
          {
            printf("��O�s�����I(-1:����) : ");
            scanf("%d",&i);
            if (i == -1)
               break;
            else
              {
                printf("               �M���I : ");
                scanf("%d",&j);
                adj_list(i,j);
              }
         }
    }
}

/*------------------*/
/*   �غc�F����C   */
/*------------------*/
void adj_list(int i, int j)
{
   struct node *new_node, *x;
   
   new_node = (struct node *) malloc(sizeof(struct node));
   new_node->data = j;
   new_node->link = NULL;
   x = &v_list[i];
   while(x->link != NULL)
      x = x-> link;
   x->link = new_node;

   new_node = (struct node *) malloc(sizeof(struct node));
   new_node->data = i;
   new_node->link = NULL;
   x = &v_list[j];
   while(x->link != NULL)
      x = x-> link;
   x->link = new_node;
}

/*------------------*/
/*   ��X�F����C   */
/*------------------*/
void output_adj_list(void)
{
   int i, j;
   struct node *new_node, *x;

   printf("\n�L�V�Ϫ��F����C��ܪk�� : \n\n");
   for(i = 0; i < vertices; i++)
      {
        printf("v%d",i);
        x = &v_list[i];
        while(x->link != NULL)
          {
            x = x-> link;
            printf(" ==> v%d",x->data);
          }
        printf("\n");
     }
}

void main(void)
{ 
   input_graph( );
   output_adj_list( );
}