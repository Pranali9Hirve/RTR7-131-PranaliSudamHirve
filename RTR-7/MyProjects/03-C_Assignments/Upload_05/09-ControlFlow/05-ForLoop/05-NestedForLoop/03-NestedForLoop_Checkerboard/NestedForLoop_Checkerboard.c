#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_i, psh_j, psh_c;

    // Code
    printf("\n\n");
    for(psh_i = 0; psh_i < 12; psh_i++)
    {
        for(psh_j = 0; psh_j < 12; psh_j++)
        {
            psh_c = ((psh_i & 0X2) == 0) ^ ((psh_j & 0X2) == 0);
            if (psh_c == 0)
            {
                printf(" ");
            }

            if (psh_c == 1)
            {
                printf("* ");
            }
        }
        printf("\n\n");
    }
    return(0);
}