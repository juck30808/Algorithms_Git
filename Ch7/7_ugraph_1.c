/**********************************************************************/
/*�i�{���W�١j: 7_ugraph_1.c                                          */
/*�i�{���\��j: �L�V�Ϫ��F���x�}��ܪk                                */
/*�i��Ƶ��c�j: �}�C���c                                              */
/**********************************************************************/
/*�i�ܼƦW�٤Υγ~�j                                                  */
/*    vertices : �L�V�Ϫ����I�Ӽ�                                     */
/*  adj_matrix : �ΥH��ܵL�V�Ϫ��F���x�}                             */
/**********************************************************************/

#include <stdio.h>
#define N    80
#define true 1

int  vertices;
char adj_matrix[N][N];
void input_graph(void);
void output_graph(void);

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
           for(j = 0; j < vertices; j++)
              adj_matrix[i][j] = '0';
     
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
                 adj_matrix[i][j] = '1';
                 adj_matrix[j][i] = '1';
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

   printf("\n�L�V�Ϫ��F���x�}��ܪk�� : \n\n");
   printf("    ");
   for(i = 0; i < vertices; i++)
      printf("v%d  ",i);
   printf("\n");

   for(i = 0; i < vertices; i++)
      {
        printf("v%d  ",i);
        for(j = 0; j < vertices; j++)
	   printf("%2c  ",adj_matrix[i][j]);
        printf("\n");
      }
}

void main(void)
{
   input_graph();
   output_graph();
}