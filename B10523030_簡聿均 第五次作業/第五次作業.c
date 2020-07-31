#include <stdio.h>
#include <stdlib.h>

struct node * get_node(int val);
struct node * insert(struct node* root, int val);
int get_height(struct node* root);
int get_max(int x, int y);
int get_balance(struct node* root);
struct node * left_rotate(struct node* root);
struct node * right_rotate(struct node* root);
void preorder(struct node* root);


struct node{
    int value;
    struct node *left;
    struct node *right;
    int height;
};

 struct node* get_node(int val){
   struct node* new_node = (struct node*)malloc(sizeof(struct node));
   new_node->left = NULL;
   new_node->right = NULL;
   new_node->value = val;
   new_node->height = 1;
   return new_node;
 }

 //���J�`�I
 struct node* insert(struct node* root, int val){
   if(!root){
     struct node* new_node = get_node(val);
     return new_node;
   }
   if(root->value > val)
     root->left = insert(root->left, val);
   else
     root->right = insert(root->right, val);
   //��
   root->height = get_max(get_height(root->left), get_height(root->right)) + 1;
   //�ˬd����
   int balance = get_balance(root);
   //�ˬd���k 
   if(balance > 1){
	   if(root->left->value > val){
		root = right_rotate(root);
		}else{
		 root->left = left_rotate(root->left);
		 root = right_rotate(root);
		}
   }
   //�ˬd���k 
   if(balance < -1){
		if(root->right->value < val){
		 root = left_rotate(root);
		}else{
		 root->right = right_rotate(root->right);
		 root = left_rotate(root);
		}
   }

   return root;
 }

 int get_height(struct node* root){
   if(!root)
	 return 0;
   else
	 return root->height;
 }

 int get_max(int x, int y){
	if(x>y)
	 return x;
	else
	 return y;
 }

 int get_balance(struct node* root){
   if(!root)
	 return 0;
   else
	 return (get_height(root->left) - get_height(root->right));
 }

 //�f�ɰw
 struct node* left_rotate(struct node* root){
   struct node* right = root->right;
   struct node* left = right->left;
   right->left = root;
   root->right = left;
   root->height = get_max(get_height(root->left), get_height(root->right)) + 1;
   right->height = get_max(get_height(right->left), get_height(right->right)) + 1;
   return right;
 }

 //���ɰw
 struct node* right_rotate(struct node* root){
   struct node* left = root->left;
   struct node* right = left->right;
   left->right = root;
   root->left = right;
   root->height = get_max(get_height(root->left), get_height(root->right)) + 1;
   left->height = get_max(get_height(left->left), get_height(left->right)) + 1;
   return left;
 }

 void preorder(struct node* root){
   if(!root){
	   return;
   }
   if(root->left)
    printf("%d\t",root->left->value);
   if(root->right)
    printf("%d\t",root->right->value);
   preorder(root->left);  
   preorder(root->right);
 }

 void main(){
   struct node* root = NULL;
   int n;
   printf("��J�ƭȴ��J��or��J*���}�{��:");
   for(scanf("%d",&n);getchar()!='*';scanf("%d",&n)){             
   //��J*����
	   root = insert(root, n);
	   printf("��J�ƭȴ��J��or��J*���}�{��:");
   }
   printf("AvlTree���G�G\n %d\t",root->value);
   preorder(root);
 }
