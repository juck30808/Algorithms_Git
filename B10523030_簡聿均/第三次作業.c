#include <stdio.h>
#include <stdlib.h>

//OXOOOXX�A���_�Ʀr11
//OXOO XX
//OX O XX
//OX   XX
// X   XX   > 11

//OXXXOOOOX�A���_�Ʀr7
//OXXXOOO X
//OXXXO O X
//OXXX  O X
//OXXX    X
// XXX    X  > 7

typedef struct Newnode{     //�w�q�F�@��Newnode�����c  �O�W��node      
	char data;              //Head -> data val next
	int val;
	struct Newnode *next;
}*node;                   

 
node add(node ,char);
int getx(node);
void def_val(node);

int main(){
	char input;
	int num=2, i;
	printf("�п�J��C(�j�g�^��)�G");
	
	node head = NULL;		//head -> NULL
	while(scanf("%c",&input),head = add(head, input),getchar() !='\n'); 
	//�B�ͱЪk�G��A����ɸ��X�h OXOOOXX 
	node p = head;
	
	while (getx(head)){
		for (i = 0; i < num; i++){	
			p = p->next;		//�s����U�@�Ӹ`�I 
			if (p->val == 1){   //�I��U� ���p��L i���^�� 
				i--;
			} 
		}
		if(p->data == 'O'){   //�p�G��O�N�U�� �]val=1 
			p->val=1; 
		}else{
			def_val(head);     //OOXX�̫�p�G��X�� ���_�Ʀr+1 ��reset 
			num++;             //
			p = head;          //���Y�}�l 
		}
	}	
	printf("���_�Ʀr��:%d\n",num);
	//system("pause");  //STOP
	return 0;
}


node add(node head, char data){
	node pnew = (node)malloc(sizeof(node));  //���t�Ŷ����s�`�Ipnew 
	pnew->data = data;
	pnew->val = 0;         //�٦b��W 
	if (head == NULL){     //�p�G�����s�`�I(NULL) 
		head = pnew;        
		pnew->next = head; //�s�`�I��next�s��head 
	}else{
		node p = head;     
		while (p->next != head){
			p = p->next;
		}
		p->next = pnew;//�챵�s���`�I
		pnew->next = head;//�s���Y�`�I
	}
	return head;
}

int getx(node head){
	node p = head;           //head(p) ->NULL
	while (p->next != head){ //�������`��
		if (p->data == 'O' && p->val!=1){  //�N��ӭȬOO �BVAL!=1(�٨S�U��) 
		return 1;
		}
		p = p->next;
	}
return 0;	
}

void def_val(node head){  //�k�s�p�� ���s�պ�num 
	node p = head;
	p->val = 0;
	while(p->next != head){
		if (p->data == 'O' )
		p->val = 0;
		p = p->next;
	}
}


