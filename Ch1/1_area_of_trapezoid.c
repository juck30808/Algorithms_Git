  /********************************************************/ 
  /*�i�{���W�١j: 1_area_of_trapezoid.c                   */ 
  /*�i�{���\��j: �p���έ��n                            */ 
  /********************************************************/ 
  /*�i�ܼƦW�٤Υγ~�j                                    */ 
  /* area: �ΨӰO����X����έ��n                         */ 
  /********************************************************/
   
#include <stdio.h> 
main()
{
 int base1, base2, height;
 int basenum, area;

 scanf(��%d��,&base1);
 scanf(��%d��,&base2);
 scanf(��%d��,&height);

 basenum = base1 + base2;
 area = basenum * height / 2;
 printf(��\nThe area is %d��,area);

}  
