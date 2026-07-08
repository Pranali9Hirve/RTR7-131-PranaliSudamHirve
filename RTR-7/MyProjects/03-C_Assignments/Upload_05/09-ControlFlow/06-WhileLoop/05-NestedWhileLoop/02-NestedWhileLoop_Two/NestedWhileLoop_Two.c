#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_i, psh_j, psh_k;

    // Code
    printf("\n\n");

    psh_i = 1;
    while ( psh_i <= 3 )
    {
        printf("psh_i = %d\n", psh_i);
        printf("-------------------\n");
        psh_j = 1;
        while( psh_j <= 2 )
        {
            printf("\t psh_j = %d\n", psh_j);
            printf("\t --------------\n");
            psh_k = 1;
            while( psh_k <= 1 )
            {
                printf("\t psh_k = %d\n", psh_k);
                psh_k++;
            }
            psh_j++;
            printf("\n");
        }
        psh_i++;
        printf("\n\n");
    }
    return(0);
}
