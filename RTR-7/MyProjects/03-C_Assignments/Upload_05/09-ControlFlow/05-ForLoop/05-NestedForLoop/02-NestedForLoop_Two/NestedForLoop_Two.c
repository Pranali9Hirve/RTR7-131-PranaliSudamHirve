#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_i, psh_j, psh_k;

    // Code
    printf("\n\n");

    for (psh_i = 1; psh_i <= 3; psh_i++)
    {
        printf("psh_i = %d\n", psh_i);
        printf("-------------------\n");

        for(psh_j = 1; psh_j <= 3; psh_j++)
        {
            printf("\t psh_j = %d\n", psh_j);
            printf("\t --------------\n");

            for(psh_k = 1; psh_k <= 2; psh_k++)
            {
                printf("\t psh_k = %d\n", psh_k);
            }
            printf("\n");
        }

        printf("\n\n");
    }
    return(0);
}