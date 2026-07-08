#include<stdio.h>

int main(void)
{
    // Variable Declaration
    int psh_i, psh_j;

    // Code
    printf("\n\n");
    printf("Printing Digits 10 to 1 and 100 to 10 : \n\n");
    psh_i = 10;
    psh_j = 100;

    while( psh_i >= 1, psh_j >= 10)
    {
        printf("\t%d \t %d\n", psh_i, psh_j);
        psh_i--;
        psh_j = psh_j - 10;
    }

    printf("\n\n");

    return(0);
}
