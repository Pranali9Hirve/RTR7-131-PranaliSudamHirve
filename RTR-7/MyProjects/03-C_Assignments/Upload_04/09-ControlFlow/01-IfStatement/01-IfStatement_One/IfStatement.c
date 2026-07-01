#include<stdio.h>
int main(void)
{
    // Variable Declarations
    int psh_a, psh_b, psh_p;

    // Code
    psh_a = 9;
    psh_b = 30;
    psh_p = 30;

    printf("\n\n");

    if(psh_a < psh_b)
    {
        printf("PSH_A is LESS THAN PSH_B !!!\n\n");
    }

    if(psh_b != psh_p)
    {
        printf("PSH_B is NOT EQUAL to PSH_P !!!\n\n");
    }

    printf("Both Comparisons Have Been Done !!!\n\n");

    return(0);
}
