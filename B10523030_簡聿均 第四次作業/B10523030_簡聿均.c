#include <stdio.h>
#include <stdlib.h>

//OXXXOXO�A���_�Ʀr11
//OXXX XO
//OXXX X
// XXX X   > 11

typedef struct linklist{
    int val;                         //data
    char str;                        //o�Mx�r�� 
    struct linklist *nextp,*prevp;
}node;

node *get_node(node *headp,char data);
int anyO(node *headp);
void resetOX(node *headp);
void printlist(node *headp);

int anyO(node *headp)            //�d�ݬO�_�٦��H�b��W 
{
    node *p = headp;
    while(p->nextp != NULL)
    {
        if((p->str == 'o' || p->str == 'O' )&& p->val != 1)
            return 1;
        p = p->nextp;
    }
    if((p->str == 'o' || p->str == 'O' )&& p->val != 1)
            return 1;
    return 0;
}

node *get_node(node *headp,char data )
{
    node *newp = (node *)malloc(sizeof(node));
    newp->str = data;
    newp->val = 0;
    newp->nextp = NULL;
    newp->prevp = NULL;
    if(headp == NULL){
        headp = newp;
        headp->nextp = NULL;
        headp->prevp = NULL;
    }else{
        node * p = headp;
        while (p->nextp != NULL){
            p = p->nextp;
        }
        newp->prevp = p;
        p->nextp = newp;
    }
    return headp;
}



void resetOX(node *headp)
{
    node *p = headp;
    while(p->nextp !=NULL)
    {
        if(p->str =='O' || p->str == 'o' )   
        {
            p->val = 0;
        }
        p = p->nextp;
    }
    p->val = 0;
}

node *get_rearnode(node *headp){
    node *p = headp;
    while(p->nextp !=NULL){
        p = p->nextp;
    }
    return p;
}

int main(void){
    node *headp = NULL;
    char input[100];
    int MagicNum = 1,i;
    int whichside = 1;
    printf("�п�J��C���e:");
    scanf("%[^\n]",input);
    char *str = input;
    while(*str != 32 ? headp = get_node(headp, *str) : NULL ,str++,*str!='\0');    //����Ψӵ����j��
    node *rearp = get_rearnode(headp);
    node *p = headp;
    while (anyO(headp))
    {
        for (i = 0; i < MagicNum; i++)
        {
            if(whichside){
                p = p->nextp;
                if(p == NULL)
                p = headp;
                if (p->val == 1)
                i--;
            }else{
                p = p->prevp;
                if(p == NULL)
                p = rearp;
                if (p->val == 1)
                i--;
            }
        }
        if(p->str == 'o' || p->str == 'O'  )
        {
            p->val=1;
            if(whichside){
                whichside = 0;
            }else{
                whichside =1;
            }
        }else                            //���m�W�� ���_�Ʀr+1
        {
            resetOX(headp);
            MagicNum++;
            p = headp;
        }
    }
    printf("���_�Ʀr:%d\n",MagicNum);
    system("pause");
    return 0;
}
