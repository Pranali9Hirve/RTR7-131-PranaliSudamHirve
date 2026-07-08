#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_i, psh_j;

    // Code
    printf("\n\n");
    printf("Printing Digits 1 to 10 and 10 to 100: \n\n");

    for(psh_i=1, psh_j=10; psh_i<=10, psh_j<=100; psh_i++, psh_j = psh_j + 10)
    {
        printf("\t%d\t %d\n", psh_i, psh_j);
    }

    printf("\n\n");

    return(0);
}