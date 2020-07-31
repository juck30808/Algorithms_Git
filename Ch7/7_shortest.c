/**********************************************************************/
/*�i�{���W�١j: 7_shortest.c                                          */
/*�i�{���\��j: �q�@���I���l�C�@���I���̵u�Z��(���V��)              */
/*�i��Ƶ��c�j: �}�C���c                                              */
/**********************************************************************/
/*�i�ܼƦW�٤Υγ~�j                                                  */
/*    vertices : ���V�Ϫ����I�Ӽ�                                     */
/*  cost[i][j] : �x�s���I i �쳻�I j ���Z��(�Φ���)                   */
/*     dist[i] : �x�s�X�o���I start(��v) �쳻�I i ���Z��(�Φ���)      */
/**********************************************************************/

#include <stdio.h>
#define V    80
#define E    80
#define true 1

int  start;
int  MAX = 10000;
int  SELECTED = 1;
int  UNSELECTED = 0; 
 
int  vertices;
int  node;
int  cost[V][V];
int  mark[V];
long int dist[V];    

void input_graph(void);
void shortest_path(int v);
int  min_dist(int a, int b);
void output_cost(void);
void output_dist(int v);

/*--------------------------------------------------*/
/*   ��J���V�Ϫ���(���Ii�M���Ij)�ζZ��(����)���   */
/*--------------------------------------------------*/
void input_graph(void)
{
   int i, j, distance;

   clrscr( );
   printf("\n�п�J���V�Ϫ����I�� : ");
   scanf("%d",&vertices);

   if (vertices > 0)
      {
        for(i = 0; i < vertices; i++)
           for(j = 0; j < vertices; j++)
              {
                cost[i][j] = MAX;
              }
           for(i = 0; i < vertices; i++)
              mark[i] = UNSELECTED;

           printf("�п�J���V�Ϫ���");
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
                   printf("                 �Z�� : ");
                   scanf("%d",&distance);
                   cost[i][j] = distance;
                 }
             }
     }
}

/*---------------------------------------*/
/*   �D���I v ���l�C�@���I���̵u�Z��   */
/*---------------------------------------*/
void shortest_path(int v)
{
   int i, j, u, w, t;
   long int min;

   for(i = 0; i < vertices; i++)
      dist[i] = cost[v][i];

   node = 2;
   mark[v] = SELECTED;
   dist[v] = 0;

   while(node < vertices)
     {
       min = MAX;
       u = -1;
       for(i = 0; i < vertices; i++)
          {
            if (mark[i] == UNSELECTED && dist[i] < min)
               {
                 min = dist[i];
                 u = i;
               }
          }
       if (u != -1)
          {
            mark[u] = SELECTED;
            node += 1;
            for(w = 0; w < vertices; w++)
               {
                 if (mark[w] == UNSELECTED)
                   dist[w] = min_dist(dist[w], dist[u]+cost[u][w]);
               } 
          }
       else
          break; 
    } 
}

/*-------------------------*/
/*   ��X a , b �����p��   */
/*-------------------------*/
int min_dist(int a, int b)
{
   if(a > b)
      return (b);
   else
      return (a);
}

/*--------------------*/
/*   ��X cost �x�}   */
/*--------------------*/
void output_cost(void)
{
   int i, j;

   printf("\n���V�Ϫ��F���x�}��ܪk�� : \n\n");
   printf("    ");
   for(i = 0; i < vertices; i++)
      printf("   v%d  ",i);
   printf("\n----------------------------------------------------------------\n"); 

   for(i = 0; i < vertices; i++)
      {
        printf("v%d |",i);
        for(j = 0; j < vertices; j++)
           {
             if (cost[i][j] != MAX)
                printf("%5d  ",cost[i][j]);
             else
                printf("    x  ");
           }
        printf("\n");
     }  
}

/*--------------------*/
/*   ��X dist �x�}   */
/*--------------------*/
void output_dist(int v)
{
   int i;

   printf("\n�q���I %d ���l�C�@���I���̵u�Z���� : \n\n",v);
   printf("�Z���}�C dist :  ");

   for(i = 0; i < vertices; i++)
      printf("  [%d] ",i);
   printf("\n----------------------------------------------------------------\n");

   printf("                ");
   for(i = 0; i < vertices; i++)
      {
        if (dist[i] != MAX)
           printf("%6d",dist[i]);
        else
           printf("     x");
      }
   printf("\n");
}

void main(void)
{ 
   input_graph();
   printf("�q���@�ӳ��I�X�o : ");
   scanf("%d",&start);
   shortest_path(start);
   output_cost();
   output_dist(start);
}