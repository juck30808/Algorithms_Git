#include <stdio.h>
//#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	double total=0,x;
	printf("�п�Jx (�u��0~1)) �G");
	scanf("%lf",&x);
	
	for(i=1;i<=99;i++){    //i=1   //i< �_�Ƭ��[(����) ���Ƭ���(�t��) 
		if(i % 2 != 0){
			total =  total + pow(x,i)/i;   //�_�ƶ��ۥ[ 
		}else{
			total = total - pow(x,i)/i;    //���ƶ�����  
		}				 //�Ʀr�|�L���W�� �ҥH�_�Ƭ����� ���Ƭ��t�� 
	}
	printf("%f",total);
	return 0;
}

/*
x���w�u�����0~1����
�Y�a0.6���׬�0.47  �p�Gx�]�w��2�A
���ƶ������7���׬�-5.60�A
���ƶ������9 ���׬�-19.31�A
���ƶ������11���׬�-64.83�A�Ʀr�o���|�V�ӶV�j�A���|����
*/
