#include<stdio.h>
int main(void)
{
    // Variable Declarations
    int psh_i, psh_j;

    // Code
    printf("\n\n");

    for (psh_i = 1; psh_i <= 20; psh_i++)
    {
      for (psh_j = 1; psh_j <= 20; psh_j++)
      {
        if (psh_j > psh_i)
        {
            break;
        }
        else
        {
            printf("* ");
        }
      }
      printf("\n");
    }
    printf("\n\n");
    return(0);
}
