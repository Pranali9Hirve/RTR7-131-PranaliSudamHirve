#include<stdio.h>

int main(void)
{
  // Variable Declarations
  int psh_num_month;

  // code
  printf("\n\n");

  printf("Enter Number Of Month (1 to 12) : ");
  scanf ("%d", &psh_num_month);

  printf("\n\n");

  // IF - ELSE - IF LADDER BEGINS FROM HERE...
  if (psh_num_month == 1)
  {
    printf("Month Number %d Is JANUARY !!! \n\n", psh_num_month);
  }
  else if (psh_num_month == 2)
  {
    printf("Month Number %d Is FEBRUARY !!! \n\n", psh_num_month);
  }
  else if (psh_num_month == 3)
  {
    printf("Month Number %d Is MARCH !!! \n\n", psh_num_month);
  }
  else if (psh_num_month == 4)
  {
    printf("Month Number %d Is APRIL !!! \n\n", psh_num_month);
  }
  else if (psh_num_month == 5)
  {
    printf("Month Number %d Is MAY !!! \n\n", psh_num_month);
  }
  else if (psh_num_month == 6)
  {
    printf("Month Number %d Is JUNE !!! \n\n", psh_num_month);
  }
  else if (psh_num_month == 7)
  {
    printf("Month Number %d Is JULY !!! \n\n", psh_num_month);
  }
  else if (psh_num_month == 8)
  {
    printf("Month Number %d Is AUGUST !!! \n\n", psh_num_month);
  }
  else if (psh_num_month == 9)
  {
    printf("Month Number %d Is SEPTEMBER !!! \n\n", psh_num_month);
  }
  else if (psh_num_month == 10)
  {
    printf("Month Number %d Is OCTOBER !!! \n\n", psh_num_month);
  }
  else if (psh_num_month == 11)
  {
    printf("Month Number %d Is NOVEMBER !!! \n\n", psh_num_month);
  }
  else if (psh_num_month == 12)
  {
    printf("Month Number %d Is DECEMBER !!! \n\n", psh_num_month);
  }
  else  //just like 'default' is optional in switch-case, so is 'else' in the if-else if-else ladder...
  {
    printf("Invalid Month Number %d Entered !!! Please Try Again... In\n", psh_num_month);
  }

  printf("If- Else If - Else Ladder Complete !!! \n");

  return(0);
}
