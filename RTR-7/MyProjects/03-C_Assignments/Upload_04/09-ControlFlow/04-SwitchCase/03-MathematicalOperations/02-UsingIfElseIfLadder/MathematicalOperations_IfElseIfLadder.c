#include <stdio.h> //for printf()
#include <conio.h> //for getch()

int main(void)
{
  // Variable Declarations
  int psh_a, psh_b;
  int psh_result;

  char psh_option, psh_option_division;

  //code
  printf(" \n\n");
  printf("Enter Value For 'A' : ");
  scanf ("%d", &psh_a) ;

  printf("Enter Value For 'B' : ");
  scanf ("%d", &psh_b);

  printf("Enter Option In Character : \n\n");
  printf("'A' or 'a' For Addition : \n");
  printf("'S' or 's' For Subtraction : \n");
  printf("'M' or 'm' For Multiplication : \n");
  printf("'D' or 'd' For Division : \n\n");

  printf("Enter Option : ");
  psh_option = getch();

  printf("\n\n");

  if (psh_option == 'A' || psh_option == 'a')
  {
    psh_result = psh_a + psh_b;
    printf("Addition Of A = %d And B = %d Gives Result %d !!! \n\n", psh_a, psh_b, psh_result); 
  }
  else if (psh_option == 'S' || psh_option == 's')
  {
    if (psh_a >= psh_b)
    {
      psh_result = psh_a - psh_b;
      printf("Substraction Of B = %d From A = %d Gives Result %d !!! \n\n", psh_b, psh_a, psh_result); 
    }
    else
    {
      psh_result = psh_b - psh_a;
      printf("Substraction Of A = %d From B = %d Gives Result %d !!! \n\n", psh_a, psh_b, psh_result); 
    }
  }
  else if (psh_option == 'M' || psh_option == 'm')
  {
    psh_result = psh_a * psh_b;
    printf("Multiplication Of A = %d And B = %d Gives Result %d !!! \n\n", psh_a, psh_b, psh_result); 
  }
  else if (psh_option == 'D' || psh_option == 'd')
  {
    printf("Enter Option In Character : \n\n");
    printf("'Q' or 'q' or '/' For Quotient Upon Division : \n");
    printf("'R' or 'r' or '%%' For Remainder Upon Division : \n");

    printf("Enter Option : ");
    psh_option_division = getch();

    if (psh_option_division == 'Q' || psh_option_division == 'a' || psh_option_division == '/')
    {
      if (psh_a >= psh_b)
      {
        psh_result = psh_a / psh_b;
        printf("Division Of A = %d By B = %d Gives Quotient = %d !!! \n \n", psh_a, psh_b, psh_result);
      }
      else
      {
        psh_result = psh_b / psh_a;
        printf("Division Of B = %d By A = %d Gives Quotient = %d !!!\n", psh_b, psh_a, psh_result);
      } 
    }
    else if (psh_option_division == 'R' || psh_option_division == 'r' || psh_option_division == '%')
    {
      if (psh_a >= psh_b)
      {
        psh_result = psh_a % psh_b;
        printf("Division Of A = %d By B = %d Gives Remainder = %d !!! \n \n", psh_a, psh_b, psh_result);
      }
      else
      {
        psh_result = psh_b % psh_a;
        printf("Division Of B = %d By A = %d Gives Remainder = %d !!!\n", psh_b, psh_a, psh_result);
      } 
    }
    else 
    {
      printf("Invalid Character %c Entered For Division !!! Please Try Again... In\n", psh_option_division);
    }
  }
  else 
  {
    printf("Invalid Character %c Entered !!! Please Try Again... \n\n", psh_option);
  }

  printf("If - Else If - Else Ladder Complete !!! \n");
  
  return (0);
}
