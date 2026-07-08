#include<stdio.h>
int main(void)
{
    // Variable Declarations
    int psh_i;

    // Code
    printf("\n\n");

    printf("Printing Even Numbers from 0 to 100: \n\n");

    for (psh_i=0; psh_i <=100; psh_i++)
    {
        // Condition for a number to be even number => division od a number by 2 leaves no remainder (remainder = 0)
        // If remainder is not 0, the number is odd number....

        if (psh_i % 2 != 0)
        {
            continue;
        }
        else
        {
            printf("\t %d \n", psh_i);
        }
    }

    printf("\n\n");
    return(0);
}
