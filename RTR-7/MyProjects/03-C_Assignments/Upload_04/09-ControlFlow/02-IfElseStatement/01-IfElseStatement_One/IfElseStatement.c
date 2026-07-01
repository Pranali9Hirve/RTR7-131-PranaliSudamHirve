#include<stdio.h>
int main(void)
{
    // Variable Declarations
    int psh_a, psh_b, psh_p;

    // Code
    psh_a = 9;
    psh_b = 30;
    psh_p = 30;

    // *** FIRST if-else PAIR ***
    printf("\n\n");

    if(psh_a < psh_b)
    {
        printf("Entering First if-block... \n\n");
        printf("PSH_A is LESS THAN PSH_B !!!\n\n");
    }
    else
    {
        printf("Entering First else-block... \n\n");
        printf("PSH_A is NOT LESS THAN PSH_B !!!\n\n");
    }
    printf("First if-else Pair Done !!!\n\n");

    // *** SECOND if-else PAIR ***
    printf("\n\n");

    if(psh_b != psh_p)
    {
        printf("Entering Second if-block... \n\n");
        printf("PSH_B is NOT EQUAL to PSH_P !!!\n\n");
    }
    else
    {
        printf("Entering Second else-block... \n\n");
        printf("PSH_B is EQUAL TO PSH_P !!!\n\n");
    }

    printf("Second if-else Pair Done !!!\n\n");

    return(0);
}