#include <stdio.h>

int main(void)
{
  // Variable Declarations
  int psh_i, psh_j;
  char psh_ch_01, psh_ch_02;

  int psh_a, psh_result_int;
  float psh_f, psh_result_float;

  int psh_i_explicit;
  float psh_f_explicit;

  // Code
  printf("\n\n");

  //INTERCONVERSION AND IMPLICIT TYPE-CASTING BETWEEN 'char' AND 'int' TYPES....
  psh_i = 70;
  psh_ch_01 = psh_i;
  printf("psh_i = %d\n", psh_i);
  printf("Charater 1 (after psh_ch_01 = psh_i) = %c\n\n", psh_ch_01);

  psh_ch_02 = 'Q';
  psh_j = psh_ch_02;
  printf("Charater 2  = %c\n", psh_ch_02);
  printf("psh_j (after psh_j = psh_ch_02) = %d\n\n", psh_j);

  //IMPLICIT CONVERSION OF 'int' TO 'float'...
  psh_a = 5;
  psh_f = 7.8f;
  psh_result_float = psh_a + psh_f;
  printf("Integer a = %d And Floating-Point Number %f Added Gives Floating-Point Sum = %f\n\n", psh_a, psh_f, psh_result_float);

  psh_result_int = psh_a + psh_f;
  printf("Integer a = %d And Floating-Point Number %f Added Gives Integer Sum = %d\n\n", psh_a, psh_f, psh_result_int);

  //EXPLICIT TYPE-CASTING USING CAST OPERATOR...
  psh_f_explicit = 30.121995f;
  psh_i_explicit = (int)psh_f_explicit;
  printf("Floating Point Number Which Will Be Type Casted Explicitly = %f\n", psh_f_explicit);
  printf("Resultant Integer After Explicit Type Casting Of %f = %d\n\n", psh_f_explicit, psh_i_explicit);

  return(0);
}
