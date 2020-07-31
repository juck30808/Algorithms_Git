/*********************************************************/
/*�i�{���W�١j: 4_hanoi_s.c                              */
/*�i�{���\��j: �e����(�ϥΰ��|�ޥ�)                     */
/*�i��Ƶ��c�j: �}�C���c�B���|                           */
/*       ��J : ��L���Ӽ�                               */
/*       ��X : ��L���h���L�{                           */
/*********************************************************/
/*�i�ܼƦW�٤Υγ~�j                                     */
/*    stack[n] : ���@�Ӱ��|���c                          */
/*         top : ���@�Ӱ}�C���ޡA�����V���|stack������   */
/*********************************************************/

#include <stdio.h>

#define n 100
#define true 1
#define false 0

int  stack[n][4];
int  top = -1;

int  empty(void);
int  full(void);
void push(int disk_no,
          char source, char intermediate, char destination);
void pop(int *disk_no,
         char *source, char *intermediate, char *destination);
void print_stack_data();
void swap(char *x, char *y);
void hanoi(int disk_no,
           char source, char intermediate, char destination);

/*----------------------*/
/*   �P�_�O�_���Ű��|   */
/*----------------------*/
int empty(void)
{
    return (top < 0) ? true : false;   
}

/*----------------------*/
/*   �P�_���|�O�_����   */
/*----------------------*/
int full(void)
{
   return (top >= n - 1) ? true : false;
}

/*--------------------*/
/*   �N��Ʃ�J���|   */
/*--------------------*/
void push(int disk_no,
          char source, char intermediate, char destination)
{
   top = top + 1 ;
   stack[top][0] = disk_no;
   stack[top][1] = source;
   stack[top][2] = intermediate;
   stack[top][3] = destination;
   printf("�N��� %d %c %c %c ��J���|\n",disk_no,
         source,intermediate, destination); 
   print_stack_data();
}

/*------------------*/
/*   �C�L���|���   */
/*------------------*/
void print_stack_data()
{
   int i;

   printf("���|���e��:\n");
   if(top >= 0){
      for(i = top; i >= 0 ; i--)
         printf("stack(%d)=%d %c %c %c \n",i,stack[i][0],
                 stack[i][1],stack[i][2],stack[i][3]);    
   }
   else
      printf("�Ű��|\n");
}

/*------------------------*/
/*   �R�����|���ݪ����   */
/*------------------------*/
void pop(int *disk_no,
         char *source, char *intermediate, char *destination)
{
   *disk_no= stack[top][0];
   *source= stack[top][1];
   *intermediate= stack[top][2];
   *destination = stack[top][3];
   top = top - 1;
   printf("�۰��|���X���:%d %c %c %c\n",*disk_no,
         *source,*intermediate,*destination);
   print_stack_data();   
}

/*------------------------*/
/*   �N x �P y ���ȥ洫   */
/*------------------------*/
void swap(char *x, char *y)
{
   char temp;
   
   temp = *x;
   *x = *y;
   *y = temp;
}

/*--------------*/
/*   �e������   */
/*--------------*/
void hanoi(int disk_no,
           char source, char intermediate, char destination)
{
   int step=0;

   printf("�h�����L�{�p�U�G\n");
   while(1){
      while(disk_no > 1){
         push(disk_no,source,intermediate,destination);
         disk_no -= 1;
         swap(&intermediate,&destination);
      }
      printf("==>�B�J(%d):�N %d ����L�q %c �W�h�� %c �W�C\n",++step,
             disk_no,source,destination);
      if(empty()) break;
      else{
         pop(&disk_no,&source,&intermediate,&destination);

         printf("**>�B�J(%d):�N %d ����L�q %c �W�h�� %c �W�C\n",++step,
                disk_no,source,destination);
         disk_no -= 1;
         swap(&source,&intermediate);
      }
   }
}

void main(void)
{
   int disk_no;

   clrscr( );
   printf("==> �w�g�ŧi�@�Ӯe�q�� %d �����| ! \n",n);
   printf("���X�Ӷ�L ? ");
   scanf("%d",&disk_no);
   hanoi(disk_no,'a','b','c'); 
}