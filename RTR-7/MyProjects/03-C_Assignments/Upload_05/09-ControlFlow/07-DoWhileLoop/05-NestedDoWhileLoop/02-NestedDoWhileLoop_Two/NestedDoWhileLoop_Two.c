#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_i, psh_j, psh_k;

    // Code
    printf("\n\n");

    psh_i = 1;
    do
    {
        printf("psh_i = %d\n", psh_i);
        printf("-------------------\n");
        psh_j = 1;
        do
        {
            printf("\t psh_j = %d\n", psh_j);
            printf("\t --------------\n");
            psh_k = 1;
            do
            {
                printf("\t psh_k = %d\n", psh_k);
                psh_k++;
            }while( psh_k <= 1 );
            psh_j++;
            printf("\n");
        }while( psh_j <= 2 );
        psh_i++;
        printf("\n\n");
    }while ( psh_i <= 3 );
    return(0);
}
