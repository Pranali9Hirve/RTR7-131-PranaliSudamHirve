#include<stdio.h>

enum
{
    PSH_NEGATIVE = -1,
    PSH_ZERO,
    PSH_POSITIVE
};

int main(void)
{
    // Function declaration
    int Difference(int, int , int *);

    // Variable Declaration
    int psh_a, psh_b, psh_answer, psh_ret;

    // Code
    printf("\n\n");
    printf("Enter Value of 'psh_a': \n");
    scanf("%d", &psh_a);

    printf("Enter Value of 'psh_b': \n");
    scanf("%d", &psh_b);

    psh_ret = Difference(psh_a, psh_b, &psh_answer);

    printf("\n\n");
    printf("Difference of %d And %d = %d\n\n", psh_a, psh_b, psh_answer);

    if (psh_ret == PSH_POSITIVE)
    {
        printf("Difference of %d And %d is positive !!! \n", psh_a, psh_b);
    }
    else if (psh_ret == PSH_NEGATIVE)
    {
        printf("Difference of %d And %d is negative !!! \n", psh_a, psh_b);
    }
    else
    {
        printf("Difference of %d And %d is Zero !!! \n", psh_a, psh_b);
    }
}

int Difference(int psh_x, int psh_y, int *psh_diff)
{
    // Code
    *psh_diff = psh_x - psh_y;
    if (*psh_diff > 0)
    {
        return(PSH_POSITIVE);
    }
    else if (*psh_diff < 0)
    {
        return(PSH_NEGATIVE);
    }
    else
    {
        return(PSH_ZERO);
    }
}
