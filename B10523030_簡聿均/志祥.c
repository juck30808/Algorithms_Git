#include <stdio.h>
#include <stdlib.h>

typedef struct Linknode{
	char data;
	int val;
	struct Linknode *pNext;
}node,*PNODE;       //PNODE�@�ӳs����C����������

PNODE addback(PNODE ,char);//����
int getx(PNODE);
void def_val(PNODE);

PNODE addback(PNODE phead, char data){    //�������J
	PNODE pnew = (PNODE)malloc(sizeof(node));
	pnew->data = data;
	pnew->val = 0;
	if (phead == NULL){
		phead = pnew;
		pnew->pNext = phead;//�@�Ӹ`�I����
	}else{
		PNODE p = phead;
		while (p->pNext != phead){
			p = p->pNext;
		}
		p->pNext = pnew;//�챵�s���`�I
		pnew->pNext = phead;//�s���Y�`�I
	}
	return phead;
}

int getx(PNODE phead){
	PNODE p = phead;
	while (p->pNext != phead){ //�������`�����Y�`�I �P�_ 
		if ((p->data == 'o' || p->data == 'O' )&& p->val!=1)
		return 1;
		p = p->pNext;
	}
return 0;	
}

void def_val(PNODE phead){
	PNODE p = phead;
	p->val = 0;
	while(p->pNext != phead){
		if (p->data == 'o' || p->data == 'O' )
		p->val = 0;
		p = p->pNext;
	}
}

int main(){
	PNODE phead = NULL;//�Y�`�I
	char input;
	int tmp = 2,i;
	printf("�п�J��C���e:");
	while(scanf("%c",&input),phead = addback(phead, input),getchar()!='\n');
	PNODE p = phead;
	while (getx(phead)){
		for (i = 0; i < tmp; i++){	
			p = p->pNext;//�`��
			if (p->val == 1)
			i--;
		}
		if(p->data == 'o' || p->data == 'O' ){ 
			p->val=1; 
		}else{
			def_val(phead);
			tmp++;
			p = phead;
		}
	}	
	printf("���_�Ʀr:%d\n",tmp);
	return 0;
}


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

