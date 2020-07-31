/**********************************************************************/
/*�i�{���W�١j: 7_topological.cpp                                     */
/*�i�{���\��j: �ݾ�Ƨ�(���V��)                                      */
/*�i��Ƶ��c�j: �}�C���c                                              */
/**********************************************************************/
/*�i�ܼƦW�٤Υγ~�j                                                  */
/*    vertices : ���V�Ϫ����I�Ӽ�                                     */
/*  adj_matrix : �ΥH��ܦ��V�Ϫ��F���x�}                             */
/**********************************************************************/

#include <stdio.h>
#define  V    80
#define  true 1

int  SELECTED = 1;
int  UNSELECTED = 0;
int  vertices;
int  adj_matrix[V][V];
int  mark[V];

void input_graph(void);
void topological_sort(void);
void output_graph(void);

/*--------------------------------------------------*/
/*   ��J���V�Ϫ���(���Ii�M���Ij)�ζZ��(����)���   */
/*--------------------------------------------------*/
void input_graph(void)
{
   int i, j;

   clrscr( );
   printf("\n�п�J���V�Ϫ����I�� : ");
   scanf("%d",&vertices);

   if(vertices > 0){
      for(i = 0; i < vertices; i++)
         for(j = 0; j < vertices; j++)
            {
              adj_matrix[i][j] = 0;
            }
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
              printf("               �쳻�I : ");
              scanf("%d",&j);
              adj_matrix[i][j] = 1;
            }
       }
   }
}

/*--------------*/
/*   �ݾ�Ƨ�   */
/*--------------*/
void topological_sort(void)
{
   int i, j, n, one;

   printf("\n�ݾ�ƧǬ� : ");
   for(i = 0; i < vertices; i++)
      mark[i] = UNSELECTED;

   n = 0;
   label:
   while(n < vertices)
     {
       for(i = 0; i < vertices; i++)
          {
            one = 0;
            if (mark[i] == UNSELECTED)
               {
                 for(j = 0; j < vertices; j++)
                    if (mark[i] == UNSELECTED && mark[j] == UNSELECTED)
                       if ( adj_matrix[j][i] == 1)
                          one += 1;
                 if (one ==0)
                    {
                      mark[i] = SELECTED;
                      n += 1;
                      printf("==> v%d  ",i);
                      goto label;
                    }
               }  
          }
     }
}

/*------------------*/
/*   ��X�F���x�}   */
/*------------------*/
void output_graph(void)
{
   int i, j;

   printf("\n���V�Ϫ��F���x�}��ܪk�� : \n\n");
   printf("    ");
   for(i = 0; i < vertices; i++)
      printf("   v%d  ",i);
   printf("\n---------------------------------------\n"); 

   for(i = 0; i < vertices; i++)
      {
        printf("v%d |",i);
        for(j = 0; j < vertices; j++)
           printf("%5d  ",adj_matrix[i][j]);
        printf("\n");
      }  
}

void main(void)
{ 
   input_graph();
   output_graph();
   topological_sort();
}