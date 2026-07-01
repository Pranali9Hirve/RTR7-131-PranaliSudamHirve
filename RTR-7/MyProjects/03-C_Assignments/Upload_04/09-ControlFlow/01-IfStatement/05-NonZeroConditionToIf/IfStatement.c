#include<stdio.h>
int main(void)
{
    // Variable Declarations
    int psh_a;

    // Code
    printf("\n\n");

    psh_a = 5;
    if (psh_a)   //Non-Zero Positive Value
    {
        printf("if-block 1 : 'A' Exists And Has Value = %d !!! \n\n", psh_a);
    }

    psh_a = -5;
    if (psh_a)   //Non-Zero Negative Value
    {
        printf("if-block 2 : 'A' Exists And Has Value = %d !!! \n\n", psh_a);
    }

    psh_a = 0;
    if (psh_a)   //Zero Value
    {
        printf("if-block 3 : 'A' Exists And Has Value = %d !!! \n\n", psh_a);
    }

    printf("All Three If-Statements Are Done");

    return(0);
}
