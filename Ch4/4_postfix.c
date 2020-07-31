/*********************************************************/
/*�i�{���W�١j: 4_postfix.c                              */
/*�i�{���\��j: �N���m�B�⦡�ഫ����m�B�⦡             */
/*�i��Ƶ��c�j: �}�C���c�B���|                           */
/*       ��J : ���m�B�⦡                               */
/*       ��X : ��m�B�⦡                               */
/*********************************************************/
/*�i�ܼƦW�٤Υγ~�j                                     */
/*    stack[] : ���@�Ӱ}�C�A���Ψ��x�s���|���           */
/*        top : ���@�Ӱ}�C���ޡA�����V���|����           */
/* operator[] : ���@�Ӱ}�C�A���ΨӦs��B��l             */
/* priority[] : ���@�Ӱ}�C�A���ΨӦs��B��l���u������   */
/*********************************************************/

#include <stdio.h>

#define n 50
#define no_of_operator 6
#define true 1
#define false 0
 
int stack[n];
int top = -1;

/*----------------------------------------------*/
/*   operator[0]='('�A���u���Ǭ�priority[0]=0   */
/*   operator[0]='+'�A���u���Ǭ�priority[1]=1   */
/*   operator[0]='-'�A���u���Ǭ�priority[2]=2   */
/*   operator[0]='*'�A���u���Ǭ�priority[3]=3   */
/*   operator[0]='/'�A���u���Ǭ�priority[4]=4   */
/*   operator[0]='^'�A���u���Ǭ�priority[5]=5   */
/*----------------------------------------------*/
char operator[no_of_operator] = {'(','+','-','*','/','^'};
int  priority[no_of_operator] = {0,1,1,2,2,3}; 

int  empty(void);
int  full(void);
void push(char key);
char top_stack_data();
char pop(void);
int  precedence(char op);
void infix_to_postfix(char infix[], char postfix[]);

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

/*-------------------------*/
/*   �N��� key ��J���|   */
/*-------------------------*/
void push(char stack_data)
{
   stack[++top] = stack_data;        
}

/*----------------------------------------*/
/*    �d�ݰ��|���ݪ���Ƭ���?(�ëD�R��)   */
/*----------------------------------------*/
char top_stack_data()
{
   return stack[top];    
}

/*------------------------*/
/*   �R�����|���ݪ����   */
/*------------------------*/
char pop(void)
{
   return stack[top--];    
}

/*----------------------------*/
/*    �Ǧ^�B��l op ���u����  */
/*----------------------------*/
int precedence(char op)
{
   int i;
   
   for(i=0; i < no_of_operator ; i++)
      if(operator[i] == op)
         return priority[i];
   return -1;
}

/*------------------------------------*/
/*   �N���m��infix�ন��m��postfix   */
/*------------------------------------*/
void infix_to_postfix(char infix[], char postfix[])
{
   int i=0, j=-1;
   char x, y;

   while((x=infix[i++]) != '\0'){
      x = tolower(x);
      switch(x){
         case '(' : push(x);
                    break;
         case ')' : while(! empty() && (x=pop()) != '(')
                       postfix[++j]=x;
                    break;
         case '+' :
         case '-' :
         case '*' :
         case '/' : 
         case '^' : y=top_stack_data();
                    while(precedence(y) >= precedence(x)){
                       postfix[++j]=pop();
                       y=top_stack_data();
                    }
                    push(x);
                    break;
          default : /* x ���B�⤸ */
                    postfix[++j]=x;
      }
   }
   while(! empty())
      postfix[++j]=pop();
   postfix[++j]='\0';
}

void main(void)
{
   char infix[50], postfix[50];

   clrscr( );
   printf("==> �w�g�ŧi�@�Ӯe�q�� %d �����| ! \n",n);

   while(true){
      printf("\n�п�J���m�B�⦡(0:����) : ");
      gets(infix);

      if(infix[0]=='0')
         break;
      else{
         infix_to_postfix(infix,postfix);
         printf("\n==>���m�B�⦡ : %s ",infix);
         printf("\n==>��m�B�⦡ : %s \n",postfix);
      }    
   }
}