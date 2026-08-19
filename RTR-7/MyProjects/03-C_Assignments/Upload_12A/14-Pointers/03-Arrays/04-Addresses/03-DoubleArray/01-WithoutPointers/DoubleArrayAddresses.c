// DoubleArrayAddresses.c

#include <stdio.h>

int main(void)
{
    // Variable declarations
    double psh_dArray[10];
    int psh_i;

    // Code
    for (psh_i = 0; psh_i < 10; psh_i++)
        psh_dArray[psh_i] = (float)(psh_i + 1) * 1.333333f;

    printf("\n\n");
    printf("Elements Of The 'double' Array : \n\n");

    for (psh_i = 0; psh_i < 10; psh_i++)
        printf("psh_dArray[%d] = %lf\n", psh_i, psh_dArray[psh_i]);

    printf("\n\n");
    printf("Elements Of The 'double' Array : \n\n");

    for (psh_i = 0; psh_i < 10; psh_i++)
        printf("psh_dArray[%d] = %lf \t \t Address = %p\n", psh_i, psh_dArray[psh_i], &psh_dArray[psh_i]);

    printf("\n\n");

    return (0);
}
