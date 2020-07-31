/*********************************************************/
/*�i�{���W�١j: 2_b_search.c                             */
/*�i�{���\��j: �G���j�M�k(��ȥi����)                   */
/*       ��J : ���j�M�����                             */
/*       ��X : �O�_���A�p�G���h��ܨ���ަ�m       */
/*�i��Ƶ��c�j: �}�C���c                                 */
/*********************************************************/
/*�i�ܼƦW�٤Υγ~�j                                     */
/*        d[] : �x�s�ݷj�M�����(�w�g����Ȼ��W�Ƨ�)     */
/*    index[] : ����������Ȩ���ަ�m�s��b��         */
/*      count : �@���h�ֵ���ƺ����j�M����               */
/*********************************************************/

#include <stdio.h>
#define Size 8
#define true 1

void print_array_data(int *d, int n);
int binary_search(int *d, int low_index, int high_index,
                  int key, int *index);

/*--------------------*/
/*   �C�L�}�C������   */
/*--------------------*/
void print_array_data(int *d, int n)
{
   int i ;

   printf("�}�C���� d[0] [1] [2] [3] [4] [5] [6] [7] \n");
   printf("------------------------------------------\n");
   printf("��  �� ==>");
   for(i = 0; i < n; i++){
      printf("%3d ",d[i]);
   }
   printf("\n\n");
}

/*----------------*/
/*   �G���j�M�k   */
/*----------------*/
int binary_search(int *d, int low_index, int high_index,
                  int key, int *index)
{
   int i, middle, count;

   if(d[low_index] > key || d[high_index] < key ) /* not found */
     return (-1);

   count=-1;
   while(low_index <= high_index){
      middle = (low_index + high_index)/2;
      if(key > d[middle])
         low_index = middle + 1;      /* �U�@�^�X���j�M��b�� */
      else{
         if(key < d[middle])
            high_index = middle - 1;  /* �U�@�^�X���j�M�e�b�� */  
          
         else{ /* key == d[middle] */
            index[++count] = middle;  /* ���F */
                                      /* ���A����e�ᵧ��ȬO�_�ۦP */

            i = middle - 1;
            while(i >= low_index && key == d[i]) /* ����e���X���O�_�P��� */
               index[++count] = i--;

	    i = middle + 1;
	    while(i <= high_index && key == d[i]) /* ����᭱�X���O�_�P��� */
               index[++count] = i++;

            return (count);
         }
      }
   }
   return (-1);
}

void main(void)
{
   int d[Size]={14, 33, 48, 50, 87, 93, 120, 121}; /* �w���W�Ƨ� */
   int key;
   int i, count=-1; /* �@���h�ֵ���ƺ����j�M����   */
   int index[Size]; /* �x�s����������Ȥ����ަ�� */

   clrscr( );
   while(true){
      print_array_data(d, Size);
      printf("�п�J�n�j�M�����(�����ɿ�J-1) : ");
      scanf("%d",&key);
      if(key == -1) break;
      else;

      count = binary_search(d, 0, Size-1, key, index);

      if(count > -1){
	 for(i = 0; i <= count; i++)
            printf("\n�b d[%d] ���F��� %d�I",index[i],key);
         printf(" ==>�@��� %d ���I\n\n",count+1);
      }
      else
         printf("\n==>�䤣����� %d �I\n\n",key);
   }
}
