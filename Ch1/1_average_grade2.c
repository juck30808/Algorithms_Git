/********************************************************/ 
/*�i�{���W�١j: 1_aveage_grade2.c                       */ 
/*�i�{���\��j: �p����Z��������                        */ 
/********************************************************/ 
/*�i�ܼƦW�٤Υγ~�j                                    */ 
/* average: �ΨӰO����X����������                      */ 
/********************************************************/

  
#include <stdio.h> 

main()
{
 int i, grade;
 int average, sum=0;

 for( i=1 ; i<=60 ; i++)
    {
      printf(��\nPlease input %dth grade��,i);
      scanf(��%d��,&grade);
      sum+=grade;
    }
 average = sum/60;
 printf(��\nThe average score = %d��, average);

}
