#include<stdio.h>
int main(void)
{
    // Variable Declarations
    int psh_i, psh_j;

    // Code
    printf("\n\n");

    printf("Outer loop Prints Odd Numbers between 1 and 10: \n\n");
    printf("Inner loop Prints Even Numbers between 1 and 10 For Every Odd Number Printed by Outer Loop. \n\n");
    // Condition for a number to be even number => division od a number by 2 leaves no remainder (remainder = 0)
    // Condition for a number to be Odd number => division od a number by 2 leaves remainder (remainder = 1 (usually))
    for (psh_i=1; psh_i <=10; psh_i++)
    {
        if (psh_i % 2 != 0) // If Number is Odd
        {
            printf("\t %d \n", psh_i);
            printf("-------------------\n");

            for(psh_j=1; psh_j <= 10; psh_j++)
            {
                if (psh_j % 2 == 0) // If Number is Even
                {
                    printf("\t j = %d\n", psh_j);
                }
                else // If Number (psh_j) is Odd..
                {
                    continue;
                }
            }
            printf("\n\n");
        }
        else // If Number (psh_i) Is Even
        {
            continue;
        }
    }

    printf("\n\n");
    return(0);
}
