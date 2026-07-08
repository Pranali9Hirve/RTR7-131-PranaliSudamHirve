#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_i, psh_j;

    // Code
    printf("\n\n");

    for (psh_i = 1; psh_i <= 3; psh_i++)
    {
        printf("psh_i = %d\n", psh_i);
        printf("-------------------\n\n");

        for(psh_j = 1; psh_j <= 2; psh_j++)
        {
            printf("\t psh_j = %d\n", psh_j);
        }

        printf("\n\n");
    }
    return(0);
}