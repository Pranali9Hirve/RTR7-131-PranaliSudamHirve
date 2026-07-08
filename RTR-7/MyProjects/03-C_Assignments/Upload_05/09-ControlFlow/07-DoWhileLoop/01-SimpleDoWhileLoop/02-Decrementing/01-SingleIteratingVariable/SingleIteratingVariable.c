#include<stdio.h>

int main(void)
{
    // Variable Declaration
    int psh_i;

    // Code
    printf("\n\n");
    printf("Printing Digits 10 to 1 : \n\n");
    psh_i = 10;
    do
    {
        printf("\t%d\n", psh_i);
        psh_i--;
    }while( psh_i >= 1);

    printf("\n\n");

    return(0);
}
