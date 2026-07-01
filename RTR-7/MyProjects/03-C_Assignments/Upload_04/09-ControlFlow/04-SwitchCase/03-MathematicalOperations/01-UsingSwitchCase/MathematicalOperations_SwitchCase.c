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

  switch (psh_option)
  {
    // FALL THROUGH CONDITION FOR 'A' and 'a'
    case 'A':
    case 'a':
        psh_result = psh_a + psh_b;
        printf("Addition Of A = %d And B = %d Gives Result %d !!! \n\n", psh_a, psh_b, psh_result); 
        break;

    // FALL THROUGH CONDITION FOR 'S' and 's'
    case 'S':
    case 's':
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
        break;

    // FALL THROUGH CONDITION FOR 'M' and 'm'
    case 'M':
    case 'm':
        psh_result = psh_a * psh_b;
        printf("Multiplication Of A = %d And B = %d Gives Result %d !!! \n\n", psh_a, psh_b, psh_result); 
        break;

    // FALL THROUGH CONSITION FOR 'D' and 'd'
    case 'D':
    case 'd':
        printf("Enter Option In Character : \n\n");
        printf("'Q' or 'q' or '/' For Quotient Upon Division : \n");
        printf("'R' or 'r' or '%%' For Remainder Upon Division : \n");

        printf("Enter Option : ");
        psh_option_division = getch();

        switch (psh_option_division)
        {
          // FALL THROUGH CONDITION FOR 'Q' and 'q' and "/'
          case 'Q':
          case 'q':
          case '/':
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
              break; // 'break' of case 'Q' or case 'q' or case "/'

          // FALL THROUGH CONSITION FOR 'R' and 'r' and "%
          case 'R':
          case 'r':
          case '%':
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
              break; // 'break' of case 'R' or case 'r' or case '%'

          default: // 'default' case for switch(psh_option_division)
              printf("Invalid Character %c Entered For Division !!! Please Try Again... In\n", psh_option_division);
              break; // 'break' of 'default' of switch(psh_option_division)
        } // ending curly brace of switch(psh_option_division)
      break; // 'break' of case 'D' or case 'd'

      default: // 'default' case for switch (psh_option)
            printf("Invalid Character %c Entered !!! Please Try Again... \n\n", psh_option);
            break;
  } // ending curly brace of switch (psh_option)

  printf("Switch Case Block Complete !!! \n");
  
  return (0);
}
