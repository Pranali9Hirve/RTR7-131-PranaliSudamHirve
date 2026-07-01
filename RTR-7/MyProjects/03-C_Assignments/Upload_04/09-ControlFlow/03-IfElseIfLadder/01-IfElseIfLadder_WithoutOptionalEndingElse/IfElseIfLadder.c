#include<stdio.h>

int main(void)
{
  // Variable Declarations
  int psh_num;

  // code
  printf("\n\n");

  printf("Enter Value For 'psh_num' : ");
  scanf( "%d", &psh_num);

  // IF - ELSE - IF LADDER BEGINS FROM HERE...
  if (psh_num < 0)
  { 
    printf("Num = %d Is Less Than O (NEGATIVE) !!! \n\n", psh_num) ;
  }
  else if ((psh_num > 0) && (psh_num <= 100))
  {
    printf("Num = %d Is Between 0 And 100 !!!\n\n", psh_num) ;
  }
  else if ((psh_num > 100) && (psh_num <= 200)) // 'if' - 03
  {
    printf("Num = %d Is Between 100 And 200 !!!\n\n", psh_num) ;
  }
  else if ((psh_num > 200) && (psh_num <= 300)) // 'if' - 04
  {
    printf("Num = %d Is Between 200 And 300 !!!\n\n", psh_num) ;
  }
  else if ((psh_num > 300) && (psh_num <= 400)) // 'if' - 05
  {
    printf("Num = %d Is Between 300 And 400 !!!\n\n", psh_num) ;
  }
  else if ((psh_num > 400) && (psh_num <= 500))
  {
    printf("Num = %d Is Between 400 And 500 !!!\n\n", psh_num) ;
  }
  else if (psh_num > 500)
  {
    printf("Num = %d Is Greater Than 500 !!!\n\n", psh_num) ;
  }

  // *** NO TERMINATING 'ELSE' IN THIS LADDER !!! ***
  
  return(0);
}
