#include<stdio.h>

int main(void)
{
    // Variable Declaration
    int psh_iArray[10];
    int psh_i;

    //Code
    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        psh_iArray[psh_i] = (psh_i + 1) *3;
    }

    printf("\n\n");
    printf("Elements Of The Integer Array : \n\n");

    for (psh_i= 0; psh_i< 10; psh_i++)
        printf("psh_iArray[%d] = %d\n", psh_i, psh_iArray[psh_i]);

    printf("\n\n");
    printf("Elements Of The Integer Array : \n\n");

    for (psh_i= 0; psh_i< 10; psh_i++)
        printf("psh_iArray[%d] = %d \t \t Address = %p\n", psh_i, psh_iArray[psh_i], &psh_iArray[psh_i]);

    printf("\n\n");

    return (0);
}