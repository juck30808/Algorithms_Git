#include <stdio.h> 
#include <stdlib.h>        //�n�]�t 

typedef struct node{
	struct node *llink;
	int data;
	struct node *rlink;
}tree_node;

typedef tree_node *tree_pointer;

//���J�`�I
tree_pointer insert(tree_pointer root,int key){
	tree_pointer ptr,current,pre;
	
	ptr= (tree_pointer)malloc(sizeof(tree_node));
	ptr->data =key;
	ptr->llink =NULL;
	ptr->rlink =NULL;
	
	if(root ==NULL){
		return ptr;
	}else{
		current=root;
		while(current != NULL){
			pre = current;
			if(key < current->data){			//�P�_�����٩��k 
				current = current->llink;
			}else{
				current = current->rlink;
			}
		}
		if(ptr->data < pre->data){
			pre->llink = ptr;
		}else{
			pre->rlink = ptr;
		}return root;
	}
}

//�L�X���Ǩ��X���G
inorder(tree_pointer root){  //��� 
	if(root){
		inorder(root->llink);
		printf("%d ",root->data);
		inorder(root->rlink);
	} 
} 

main(){
	tree_pointer root=NULL;
	root = insert(root,30);
	root = insert(root,25);
	root = insert(root,24);
	root = insert(root,58);
	root = insert(root,45);
	root = insert(root,26);
	root = insert(root,12);
	root = insert(root,14);
	inorder(root);
}

/*�ھ�key���w����ȷj�M�`�I 
tree_pointer search(tree_pointer root,int key){
	tree_pointer current;
	current = root;
	while(current){
		if(key < current->data){			//�P�_�����٩��k 
			current = current->llink;
		}else if(key > current->data){
			current = current->rlink;
		}else
			return current;
	}return NULL;
} */


//---------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct node{                 //type + def
	int data;
	struct node *next;
}list_node;

typedef list_node *list_pointer;  //���V�`�I������ 

list_pointer head,current,previous; 	//�s�W�T�ӫ��� 


initialize(){
	head = (list_pointer)malloc(sizeof(list_node));
	head->next = NULL;
}

//���J  1.�s�Wptr�Ŷ��w�� 2.�e�@�Ӭ��Y 3.current = head->next; 4.ptr�U�@�Ӭ�next 
/*	previous=head -> current	previous->	ptr -> current
   			 	 						value  next 
*/
insert(int value){			
	list_pointer ptr; //�s�W�@�ӫ��� 
	ptr = (list_pointer)malloc(sizeof(list_pointer));
	ptr->data = value;
	previous = head;	//���ܭ��I
	current = head->next;
	while((current != NULL)&&(current->data < ptr->data)){   //�j��p��i�H���ܱƦC���� 
		previous = current;			//previoud	->	current  (�@���U�h����current->value) 
		current = current->next;	//(current)
	}ptr->next = current;			//
	previous->next = ptr;
} 

//�L�X�Ҧ� 

traverse(){
	if(head->next == NULL){
		printf("��C�O�Ū�");	
	}else{
		current = head->next;
		while(current != NULL){
			printf("%d   ",current->data);
			current = current->next;
		}
	}
}

int count(){
	int length=0;
	current =head->next;
	while(current != NULL){
		length ++;
		current = current->next;
	}printf("Y %d ",length);
	return length;
}
int main(int argc, char *argv[]) {
	initialize();
	insert(30);
	insert(40);
	insert(60);
	insert(80);
	count();
	traverse();
}
*/

//#include <stdio.h> 
#include <stdlib.h> 

int main() { 
	int a,b,c=1,d=0; 		//a�{�b�� b�G�i�� c�C�@���N*10 d�`�M 
	printf("�п�J�Q�i�쪺�Ʀr�G");
	scanf("%d",&a); 		//7										4									2
	while(a!=0){			//7 != 0 		// 3 != 0		//1 !=0				//4 != 0		//2 != 0		//2 != 0
		b=a%2; 				//b = 7%2  = 1	// b = 3%2 = 1	//b = 1%2 =1		//b = 4%2 = 0	//b = 2%2 = 0	//b = 2%2 = 0
		a=a/2; 				//a = 7/2  = 3	// a = 3/2 = 1	//a = 1/2 =0		//a = 4/2 = 2	//a = 2/2 = 0
		d=d+b*c; 			//d = 0+1*1= 1	// d = 1+10 =11	//d = 11+100=101	//d = 0+0 = 0	//d = 0*0;
		c=c*10; 			//c = 1*10 = 10	// c = 10*10=100//c = 100*10		//c = 1*10=10	//c = 10*10=100
	} 
	printf("�G�i��=%d",d); 
	system("PAUSE"); 
	return 0; 
}


/*int main() { 
	int a,b,c=1,d=0; 		//a�{�b�� b�G�i�� c�C�@���N*10 d�`�M 
	printf("�п�J�Q�i�쪺�Ʀr�G");
	scanf("%d",&a); 		//7										4									2
	while(a!=0){			//7 != 0 		// 3 != 0		//1 !=0				//4 != 0		//2 != 0		//2 != 0
		b=a%2; 				//b = 7%2  = 1	// b = 3%2 = 1	//b = 1%2 =1		//b = 4%2 = 0	//b = 2%2 = 0	//b = 2%2 = 0
		a=a/2; 				//a = 7/2  = 3	// a = 3/2 = 1	//a = 1/2 =0		//a = 4/2 = 2	//a = 2/2 = 0
		d=d+b*c; 			//d = 0+1*1= 1	// d = 1+10 =11	//d = 11+100=101	//d = 0+0 = 0	//d = 0*0;
		c=c*10; 			//c = 1*10 = 10	// c = 10*10=100//c = 100*10		//c = 1*10=10	//c = 10*10=100
	} 
	printf("�G�i��=%d",d); 
	system("PAUSE"); 
	return 0; 
}*/
