/**********************************************************************/
/*�i�{���W�١j: 7_minspantree.c                                       */
/*�i�{���\��j: �L�V�Ϫ��̤p�X�i��(�ϥ�Kruskal's��k)                 */
/*�i��Ƶ��c�j: �}�C���c                                              */
/**********************************************************************/
/*�i�ܼƦW�٤Υγ~�j                                                  */
/*     Tset[V] : �ΥH���T���X�A���s��զ��̤p�X�i�𪺳��I���X        */
/*    vertices : �L�V�Ϫ����I�Ӽ�                                     */
/* adj_matrix[V][V] : ��ܵL�V�Ϫ��F���x�}�A�䤸��������(�ζZ��)      */
/*  span_tree[V][V] : ��̤ܳp�X�i�𪺾F���x�}��ܡA�䤸��������(�Z��)*/
/* struct edge : �䪺���c                                             */
/**********************************************************************/

#include <stdio.h>
#define V    80
#define E    80
#define true 1

int MAX = 10000;
int INIT = -1;
int CYCLE = 1;
int GIVEUP = 0;
int FOUND = 1;
int NOT_FOUND = 0;
int SELECTED = 1;
int e, s, t, tot_cost;
int Tset[V];
int vertices;
int adj_matrix[V][V];
int span_tree[V][V];

struct edge{  /* �w�q"��"�����c */
   int vx;
   int vy;
   int cost;
   int order;
   int selected;
}edge[E];      

void input_graph(void);
void input_edge(int i, int j, int cost);
void spanning_tree(void);
int  is_cycle(int ee);
void output_graph(void);
void output_span_tree(void);

/*--------------------------------------------------*/
/*   ��J�L�V�Ϫ���(���Ii�M���Ij)�Φ���(�Z��)���   */
/*--------------------------------------------------*/
void input_graph(void)
{
   int i, j, cost;

   e = -1;
   s = -1;
   t = -1;
   tot_cost = 0;

   clrscr( );
   printf("\n�п�J�L�V�Ϫ����I�� : ");
   scanf("%d",&vertices);
   if (vertices > 0)
      {
        for(i = 0; i < vertices; i++)
           for(j = 0; j < vertices; j++)
              {
                adj_matrix[i][j] = MAX;
                span_tree[i][j] = MAX;
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
                printf("         ����(�ζZ��) : ");
                scanf("%d",&cost);
                adj_matrix[i][j] = cost;
                adj_matrix[j][i] = cost;
                input_edge(i, j, cost);
              }
          }
     }
}

/*------------------------------*/
/*   �x�s��Φ���(�ζZ��)���   */
/*------------------------------*/
void input_edge(int i, int j, int cost)
{
   e += 1;
   edge[e].vx = i;
   edge[e].vy = j;
   edge[e].cost = cost;
   edge[e].order = 0;
   edge[e].selected = INIT; 
}

/*-------------------------------------*/
/*   �H Kruskal's ��k�سy�̤p�X�i��   */
/*-------------------------------------*/
void spanning_tree(void)
{
   int i, j, ee, min, order, cycle, select_edge;
   
   order = 0;
   select_edge = 0;
   printf("\n�H Kruskal's ��k�سy�̤p�X�i�𤧹L�{...\n\n");
   while(select_edge < vertices -1)
     {
       ee = -1;
       min = MAX;
       for(j = 0; j <= e; j++)
          {
            if (edge[j].selected == INIT)
               if (min > edge[j].cost)
                  {
                    min = edge[j].cost;
                    ee = j;
                  }
          }
       order += 1;
       cycle = is_cycle(ee);
       if (! cycle)
          {
            select_edge += 1;
            edge[ee].order = order;
            edge[ee].selected = SELECTED;
            tot_cost = tot_cost + edge[ee].cost;
            printf("�B�J %d ==> ��� ��",order);
            printf("(v%d,v%d) ",edge[ee].vx, edge[ee].vy);
            printf("�Z��=%d",edge[ee].cost);
            printf(" �`�Z��=%d\n",tot_cost);
            span_tree[edge[ee].vx][edge[ee].vy] = edge[ee].cost;
            span_tree[edge[ee].vy][edge[ee].vx] = edge[ee].cost;
          }
       else
          {
            edge[ee].order = order;
            edge[ee].selected = GIVEUP;
	    printf("�B�J %d ==> ��� ��",order);
            printf("(v%d,v%d) ",edge[ee].vx,edge[ee].vy);
            printf("�Z��=%d",edge[ee].cost);
            printf(" �`�Z��=%d\n",tot_cost);
          }
    }
}

/*----------------------------------------*/
/*   �P�_�� edge[ee] ���[�J�O�_���Ͱj��   */
/*----------------------------------------*/
int is_cycle(int ee)
{
   int i, vx, vy;
   
   vx = NOT_FOUND;
   vy = NOT_FOUND;
   for(i = 0; i <= t; i++)
      {
        if (edge[ee].vx == Tset[i])
           {
              vx = FOUND;
              break;
           }
     }
   for(i = 0; i <= t; i++)
      {
        if (edge[ee].vy == Tset[i])
           {
             vy = FOUND;
             break;
           }
      }

   if(vx == FOUND && vy == FOUND)
      return(CYCLE);
   else
     {
       if(vx == NOT_FOUND) Tset[++t] = edge[ee].vx;
       if(vy == NOT_FOUND) Tset[++t] = edge[ee].vy;
       return(! CYCLE);
    }
}

/*------------------*/
/*   ��X�F���x�}   */
/*------------------*/
void output_graph(void)
{
   int i, j;

   printf("\n�L�V�Ϫ��F���x�}��ܪk�� : \n\n");
   printf("    ");
   for(i = 0; i < vertices; i++)
      printf("   v%d  ",i);
   printf("\n");
   for(i = 0; i < vertices; i++)
      {
        printf("v%d  ",i);
        for(j = 0; j < vertices; j++)
           {
             if (adj_matrix[i][j] != MAX)
                printf("%5d  ",adj_matrix[i][j]);
             else
                printf("    x  ");
           }
        printf("\n");
     }  
}

/*--------------------*/
/*   ��X�̤p�X�i��   */
/*--------------------*/
void output_span_tree(void)
{
   int i, j;

   printf("\n�L�V�Ϫ��̤p�X�i�� : \n\n");
   printf("    ");
   for(i = 0; i < vertices; i++)
      printf("   v%d  ",i);
   printf("\n");
 
   for(i = 0; i < vertices; i++)
      {
        printf("v%d  ",i);
        for(j = 0; j < vertices; j++)
           {
             if (span_tree[i][j] != MAX)
                printf("%5d  ",span_tree[i][j]);
             else
                printf("    x  ") ;
           }  
        printf("\n");
      }
}

void main(void)
{ 
   input_graph();
   output_graph();
   spanning_tree();
   output_span_tree();
}