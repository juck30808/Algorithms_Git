/****************************************************************/
/*�i�{���W�١j: 5_perm_r.c                                      */
/*�i�{���\��j: ���j���(��)�G�C�L�X3���M4����ƪ��Ҧ��ƦC�覡  */
/*       ��J :                                                 */
/*       ��X : 3���M4����ƪ��Ҧ��ƦC�覡                      */
/*�i��Ƶ��c�j: ���j                                            */
/****************************************************************/
/*�i�ܼƦW�٤Υγ~�j                                            */
/* permutation(char data[],int no_of_data,int from,int n)       */
/*        data[] : �s��ݱƦC�����                             */
/*    no_of_data : �X�����                                     */
/*       from, n : �qdata[from]��data[n]����ƭn�ƦC            */
/* backup_data[] : �N data[] �ƥ��� backup_data[]               */
/****************************************************************/

#include <stdio.h>

#define N 5

void permutation(char data[],int no_of_data,int from,int n);
void swap(char *x, char *y);

/*-----------------------------------------------------------*/
/*   �ƦCdata[]�̪�no_of_data�����(�qdata[from]��data[n])   */
/*-----------------------------------------------------------*/
void permutation(char data[],int no_of_data,int from,int n)
{
   int  i, j, k;
   char temp[N];

   if(from == n){
      printf("\n");
      for(i = 0; i < no_of_data; i++){
         printf("%c  ",data[i]);
      }
   }
   else{
      for(k = 0; k < no_of_data; k++)  
         temp[k] = data[k];

      for(j = from; j <= n; j++){
	 swap(&data[from],&data[j]);
         permutation(data, no_of_data, from+1, n);

         for(k = 0; k < no_of_data; k++)
            data[k] = temp[k];
      }
   }
}

/*------------------------*/
/*   �N x �P y ���ȥ洫   */
/*------------------------*/
void swap(char *x, char *y)
{
   int temp;

   temp = *x;
   *x = *y;
   *y = temp;
}

void main(void)
{
      char data[N]={'a','b','c','d','e'};

      clrscr( );
      printf("\na�Bb�Bc 3����ƪ��ƦC�覡���H�U�X��:"); 
      permutation(data,3,0,2);

      printf("\n\na�Bb�Bc�Bd 4����ƪ��ƦC�覡���H�U�X��:"); 
      permutation(data,4,0,3);
}