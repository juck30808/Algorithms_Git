/**********************************************************************/
/*�i�{���W�١j: 7_allpath.cpp                                         */
/*�i�{���\��j: ���⳻�I���̵u�Z��(���V��)                            */
/*�i��Ƶ��c�j: �}�C���c                                              */
/**********************************************************************/
/*�i�ܼƦW�٤Υγ~�j                                                  */
/*    vertices : ���V�Ϫ����I�Ӽ�                                     */
/*  cost[i][j] : �x�s���I i �쳻�I j ���Z��(�Φ���)                   */
/*     a[i][j] : �x�sA-1�BA1�BA2�B...�BAvertices-1                    */
/**********************************************************************/

#include <stdio.h>
#define   V    80
#define   E    80
#define   true 1
int  start;
int  MAX = 10000;
int  vertices;
int  cost[V][V];
int  a[V][V];

void input_graph(void);
void all_path(void);
int  min_dist(int a, int b);
void output_cost(int k);

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
           cost[i][i] = 0;

        printf("�п�J���V�Ϫ���");
        printf("(0<=�䪺�s��<=%d)... \n",vertices-1);
        while(true)
          {
            printf("��O�s�����I(-1:����) : ");
	    scanf("%d",&i);
            if (i == -1)
                break;
            else
              {
                printf("               �쳻�I : ");
	        scanf("%d",&j);
                printf("                 �Z�� : ");
	        scanf("%d",&distance);
                cost[i][j] = distance;
              }
          }
     }
}

/*--------------------------*/
/*   �D���⳻�I���̵u�Z��   */
/*--------------------------*/
void all_path(void)
{            
   int i, j, k;
            
   for(i = 0; i < vertices; i++)
      {
        for(j = 0; j < vertices; j++)
           a[i][j] = cost[i][j];
      }

   output_cost(-1);
   
   for(k = 0; k < vertices; k++)
      {
        for(i = 0; i < vertices; i++)
           for(j = 0; j < vertices; j++)
              a[i][j] = min_dist(a[i][j],a[i][k]+a[k][j]);
        output_cost(k);
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

/*---------------------*/
/*    ��X cost �x�}   */
/*---------------------*/
void output_cost(int k)
{
   int i, j;
   printf("\n���V�Ϫ��F���x�} A %d :\n\n",k);
   printf("    ");
   for(i = 0; i < vertices; i++)
      printf("   v%d  ",i);
   printf("\n----------------------------------------------\n"); 

   for(i = 0; i < vertices; i++)
      {
        printf("v%d |",i);
        for(j = 0; j < vertices; j++)
           {
             if (a[i][j] != MAX)
                printf("%5d  ",a[i][j]);
             else
                printf("    x  ") ;
           }
        printf("\n");
      }  
}

void main(void)
{ 
   input_graph();
   all_path();
}