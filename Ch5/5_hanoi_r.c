/*******************************************************/
/*�i�{���W�١j: 5_hanoi_r.c                            */
/*�i�{���\��j: ���j���(��)�G�e������                 */
/*       ��J : ��L���Ӽ�                             */
/*       ��X : �Nn�Ӷ�L�qa�W�h����c�W���L�{          */
/*�i��Ƶ��c�j: ���j                                   */
/*******************************************************/
/*�i�ܼƦW�٤Υγ~�j                                   */
/*    disk_no : ��L���Ӽ�                             */
/*******************************************************/

#include <stdio.h>

/*-------------------------------------*/
/*   ���j���(��)�G�e������ �e������   */
/*-------------------------------------*/
/* ��1�ӰѼ�      disk_no�G��L���Ӽ�  */
/* ��2�ӰѼ�       source�G�ӷ��W      */
/* ��3�ӰѼ� intermediate�G�C���W      */
/* ��4�ӰѼ�  destination�G�ت��a�W    */
/*-------------------------------------*/
void hanoi(int disk_no,char source,char intermediate,char destination)
{
   static int step=0;

   if(disk_no > 1)
      hanoi(disk_no-1,source,destination,intermediate);
      printf("==>�B�J(%d):�N %d ����L�q %c �W�h�� %c �W�C\n",++step,
             disk_no,source,destination);

   if(disk_no > 1)
      hanoi(disk_no-1,intermediate,source,destination);
}

void main(void)
{
   int disk_no;

   clrscr( );
   printf("\n���X�Ӷ�L ? ");
   scanf("%d",&disk_no);
   printf("\n�h�����B�J�p�U : \n");
   hanoi(disk_no,'a','b','c');
}