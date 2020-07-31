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
