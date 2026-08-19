// FloatArrayAddresses.c

#include <stdio.h>

int main(void)
{
    // Variable declarations
    float psh_fArray[10];
    int psh_i;

    // Code
    for (psh_i = 0; psh_i < 10; psh_i++)
        psh_fArray[psh_i] = (float)(psh_i + 1) * 1.5f;

    printf("\n\n");
    printf("Elements Of The 'float' Array : \n\n");

    for (psh_i = 0; psh_i < 10; psh_i++)
        printf("fArray[%d] = %f\n", psh_i, psh_fArray[psh_i]);

    printf("\n\n");
    printf("Elements Of The 'float' Array : \n\n");

    for (psh_i = 0; psh_i < 10; psh_i++)
        printf("psh_fArray[%d] = %f \t \t Address = %p\n", psh_i, psh_fArray[psh_i], &psh_fArray[psh_i]);

    printf("\n\n");

    return (0);
}
