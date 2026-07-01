#include <stdio.h>

int main(void)
{
  // Variable Declaration
  int psh_a, psh_b;
  int psh_p, psh_q;
  char psh_ch_result_01, psh_ch_result_02;
  int psh_i_result_01, psh_i_result_02;

  // Code
  printf("\n\n");

  psh_a = 7;
  psh_b = 5;
  psh_ch_result_01 = (psh_a > psh_b) ? 'A' : 'B';
  psh_i_result_01 = (psh_a > psh_b) ? psh_a : psh_b;
  printf("Ternary Operator  Answer 1 ----- %c and %d. \n\n", psh_ch_result_01, psh_i_result_01);

  psh_p = 30;
  psh_q = 30;
  psh_ch_result_02 = (psh_p != psh_q) ? 'P' : 'Q';
  psh_i_result_02 = (psh_a != psh_b) ? psh_p : psh_q;
  printf("Ternary Operator  Answer 2 ----- %c and %d. \n\n", psh_ch_result_02, psh_i_result_02);

  printf("\n\n");
  return(0);
}
