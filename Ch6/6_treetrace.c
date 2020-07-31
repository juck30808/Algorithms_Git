/*****************************************************************/
/*�i�{���W�١j: 6_treetrace.c                                    */
/*�i�{���\��j: �𪺰l��(�t�e�ǰl�ܡB���ǰl�ܡB��ǰl��)         */
/*�i��Ƶ��c�j: singly linked list, tree, stack                  */
/*****************************************************************/
/*�i�ܼƦW�٤Υγ~�j                                             */
/*     stack[] : �ΨӱN���m�����m�������|                      */
/*         top : stack[]���|�����ݫ���                           */
/*stack_node[] : �ΨӱN�غc�G���𤧰��|                          */
/*    top_node : stack_node[]���|�����ݫ���                      */
/* struct node : �w�qtree���`�I���c�A�]�Adata���left,right�쵲��*/
/*****************************************************************/

#include <stdio.h>

#define N 50
#define OP 5
#define STZCK_SIZE 100
#define true 1
#define false 0

int top = -1;
int top_node = -1;
char data[STZCK_SIZE];
static char op[OP] = {'(','+','-','*','/',};
static int  op_priority[5]={0,1,1,2,2};
struct node{
   char data;
   struct node *left;
   struct node *right;
};
struct node *stack_node[STZCK_SIZE];

int stack_empty(void);
int stack_full(void);
void stack_push(char key);
char stack_top_data(void);
char stack_pop(void);
void to_postfix(char infix[], char postfix[]);

int priority(char c);
struct node *bin_tree(char postfix[]);
void push_node(struct node *c);
struct node *pop_node(void);
void preorder(struct node *root);


/*----------------------*/
/*   �P�_�O�_���Ű��|   */
/*----------------------*/
int stack_empty(void)
{
    return (top < 0) ? true : false;
}

/*----------------------*/
/*   �P�_���|�O�_����   */
/*----------------------*/
int stack_full(void)
{
   return (top >= N - 1) ? true : false;
}

/*-------------------------*/
/*   �N��� key ��J���|   */
/*-------------------------*/
void stack_push(char key)
{
   data[++top] = key;
}

/*------------------------*/
/*   �Ǧ^���|���ݪ����   */   
/*------------------------*/
char stack_top_data(void)
{
   return data[top];
}

/*------------------------------------*/
/*   �Ǧ^���|���ݪ���ơA���ëD���X   */
/*------------------------------------*/
char stack_pop(void)
{
   return data[top--];
}

/*------------------------------------*/
/*   �N���m��infix�ন��m��postfix   */
/*------------------------------------*/
void to_postfix(char infix[], char postfix[])
{
   int i=0, j=-1;
   char x, y;

   while((x=infix[i++]) != '\0'){
      x = tolower(x);
      switch(x){
         case '(' : stack_push(x);
                    break;
         case ')' : while(! stack_empty() && (x=stack_pop()) != '(')
                       postfix[++j]=x;
                    break;
         case '+' :
         case '-' :
         case '*' :
         case '/' : y=stack_top_data();
                    while(priority(y) >= priority(x)){
                       postfix[++j]=stack_pop();
                       y=stack_top_data();
                    }
                    stack_push(x);
                    break;
          default : /* x ���B�⤸ */
                    postfix[++j]=x;
      }
   }
   while(! stack_empty())
      postfix[++j]=stack_pop();
   postfix[++j]='\0';
}

/*---------------------------*/
/*   �Ǧ^�B��l c ���u����   */
/*---------------------------*/
int priority(char c)
{
   int i;
   
   for(i=0; i < OP; i++)
      if(op[i] == c)
         return op_priority[i];
   return -1;
}

/*---------------------------------------------------*/
/*   �Npostfix�ন�G����覡���x�s�A�öǦ^��ڸ`�I   */
/*---------------------------------------------------*/
struct node *bin_tree(char postfix[])
{
   int i = 0;
   char x;
   struct node *new_node;

   while((x = postfix[i++]) != '\0'){
      new_node = (struct node *) malloc(sizeof(struct node));
      new_node->data = x;
      if(x >= 'a' && x <= 'z'){   /* x is operand */
         new_node->left = NULL;
         new_node->right = NULL;
      }
      else{                       /* x is operator */
         new_node->right = pop_node();
         new_node->left = pop_node();
      }
      push_node(new_node);
   }
   return pop_node();
}

/*--------------------*/
/*   �N�`�I��J���|   */
/*--------------------*/
void push_node(struct node *c)
{
   if(top_node < STZCK_SIZE)
      stack_node[++top_node] = c;
   else
      printf("���| stack_node �w�� !!\n");
}

/*------------------------*/
/*   �۰��|���ݨ��X�`�I   */
/*------------------------*/
struct node *pop_node(void)
{
   if(top_node >= 0)
      return stack_node[top_node--];
   else
      printf("���| stack_node �w�� !!\n");
}

/*------------------*/
/*   �i��e�ǰl��   */
/*------------------*/
void preorder(struct node *root)
{
   if(root != NULL){
      printf("%c",root->data);
      preorder(root->left);
      preorder(root->right);
   }
}

/*------------------*/
/*   �i�椤�ǰl��   */
/*------------------*/
void inorder(struct node *root)
{
   if(root != NULL){
      inorder(root->left);
      printf("%c",root->data);
      inorder(root->right);
   }
}


/*------------------*/
/*   �i���ǰl��   */
/*------------------*/
void postorder(struct node *root)
{
   if(root != NULL){
      postorder(root->left);
      postorder(root->right);
      printf("%c",root->data);
   }
}

void main(void)
{
   int i, j, l;
   char x, y, infix[N], postfix[N];
   struct node *head;

   clrscr( );
   printf("�п�J���m�� : ");
   gets(infix);

   /*------------------------*/
   /*   �N���m���ন��m��   */
   /*------------------------*/
   to_postfix(infix,postfix);
   printf("\n���m�� : %s ����m���� : %s \n",infix ,postfix);

   /* cout << "\n���m�� : " << infix << " ����m���� : " << postfix << endl;*/
 
   /*----------------*/
   /*   �غc�G����   */ 
   /*----------------*/
   head = bin_tree(postfix);

   /*--------------*/
   /*   �e�ǰl��   */
   /*--------------*/
   printf("\n�e�ǰl�ܵ��G�� ==> ");
   preorder(head);
   printf("\n");

   /*--------------*/
   /*   ���ǰl��   */
   /*--------------*/
   printf("\n���ǰl�ܵ��G�� ==> ");
   inorder(head);
   printf("\n");

   /*--------------*/
   /*   ��ǰl��   */
   /*--------------*/
   printf("\n��ǰl�ܵ��G�� ==> ");
   postorder(head);
   printf("\n");
}