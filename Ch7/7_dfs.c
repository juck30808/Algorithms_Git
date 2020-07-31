/**********************************************************************/
/*�i�{���W�١j: 7_dfs.c                                               */
/*�i�{���\��j: �L�V�Ϫ�DFS�l��                                       */
/*�i��Ƶ��c�j: �}�C���c                                              */
/**********************************************************************/
/*�i�ܼƦW�٤Υγ~�j                                                  */
/*    visit[N] : ����X�L���I i �ɳ]�wvisit[i]=ALREADY                */
/*    vertices : �L�V�Ϫ����I�Ӽ�                                     */
/*  adj_matrix : �L�V�Ϫ��F���x�}��ܪk                               */
/**********************************************************************/

#include <stdio.h>
#define N    80
#define true 1

int  ALREADY = 1;
int  visit[N];
int  vertices;
char adj_matrix[N][N];

void input_graph(void);
void output_graph(void);
void dfs(int i);

/*----------------------------------*/
/*   ��J�L�V�Ϫ���(���Ii�M���Ij)   */
/*----------------------------------*/
void input_graph(void)
{
   int i, j;

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
           printf("%d  ",adj_matrix[i][j]);
        printf("\n");
      }  
}

/*---------------------*/
/*   �L�V�Ϫ�DFS�l��   */
/*---------------------*/
void dfs(int i)
{
   int j;
   static step = 0;

   visit[i] = ALREADY;
   printf("�B�J %d ==> ���X v%d\n",++step, i);
   for(j = 0; j < vertices; j++)
      if(adj_matrix[i][j] == '1' && visit[j] != ALREADY)
         dfs(j);
}

void main(void)
{ 
   input_graph();
   output_graph();
   clrscr( );
   printf("\n�L�V�Ϫ�DFS�l�ܹL�{...\n\n");
   dfs(0);
}