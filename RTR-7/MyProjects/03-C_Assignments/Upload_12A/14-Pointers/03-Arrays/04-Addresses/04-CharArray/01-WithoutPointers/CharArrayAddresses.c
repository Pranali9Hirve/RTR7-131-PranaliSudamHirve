// CharArrayAddresses.c

#include <stdio.h>

int main(void)
{
    // Variable declarations
    char psh_cArray[10];
    int psh_i;

    // Code
    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        psh_cArray[psh_i] = (char)(psh_i + 65);
    }
    printf("\n\n");
    printf("Elements Of The Character Array : \n\n");

    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        printf("psh_cArray[%d] = %c\n", psh_i, psh_cArray[psh_i]);
    }
    printf("\n\n");
    printf("Elements Of The Character Array : \n\n");

    for (psh_i = 0; psh_i < 10; psh_i++)
        printf("psh_cArray[%d] = %c \t \t Address = %p\n", psh_i, psh_cArray[psh_i], &psh_cArray[psh_i]);

    printf("\n\n");

    return (0);
}
