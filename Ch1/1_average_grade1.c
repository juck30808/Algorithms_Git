/********************************************************/ 
/*�i�{���W�١j: 1_average_grade.c                       */ 
/*�i�{���\��j: �p��T��P�Ǫ���������                  */ 
/********************************************************/ 
/*�i�ܼƦW�٤Υγ~�j                                    */ 
/* average: �ΨӰO����X����������                      */ 
/********************************************************/
  
#include <stdio.h> 
 
main()
{
 int grade1, grade2, grade3;
 int sum, average;

 scanf(��%d��,&grade1);
 scanf(��%d��,&grade2);
 scanf(��%d��,&grade3);
 sum=grade1+grade2+grade3;
 average=sum/3;
 printf(��\nThe average score = %d��, average);

}
