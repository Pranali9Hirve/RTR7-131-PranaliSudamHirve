#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_i, psh_j;

    // Code
    printf("\n\n");

    psh_i = 1;
    while ( psh_i <= 3)
    {
        printf("psh_i = %d\n", psh_i);
        printf("-------------------\n\n");

        psh_j = 1;
        while ( psh_j <= 2)
        {
            printf("\t psh_j = %d\n", psh_j);
            psh_j++;
        }

        psh_i++;

        printf("\n\n");
    }
    return(0);
}