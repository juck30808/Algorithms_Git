/********************************************************/ 
/*�i�{���W�١j: 1_find_maximum.c                        */ 
/*�i�{���\��j: ��X�T�ӼƭȤ����̤j��                  */ 
/********************************************************/ 
/*�i�ܼƦW�٤Υγ~�j                                    */ 
/* MAX: �ΨӰO����X���̤j��                            */ 
/********************************************************/
  
#include <stdio.h> 
 
main()
{
 int A, B, C;
 int MAX;

 scanf(��%d��,&A);
 scanf(��%d��,&B);
 scanf(��%d��,&C);

 if (A>B)
    {
      if (A>C)
           
         MAX=A;
      else
         MAX=C;
    }
 else
    {
      if (B>C)
         MAX=B;
      else
         MAX=C;
    }
 printf(��\nThe maximal number is = %d��, MAX);

}
