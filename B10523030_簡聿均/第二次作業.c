#include <stdio.h>
//#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j=1,x;
	printf("�п�J�n���h�j�G");
	scanf("%d",&x);
	printf("��Ƭ��G"); 
	for(i=2;i<=x;i++){ 
		for(j=2;j<=i;j++){				//printf("��%d�� ��%d��\n",i,j);
			if(i==j){
				printf("%d,\n",i);
			}else if(i%j==0){			//	printf("�D���\n");
				break;
			}
		}
	}
	return 0;
}
