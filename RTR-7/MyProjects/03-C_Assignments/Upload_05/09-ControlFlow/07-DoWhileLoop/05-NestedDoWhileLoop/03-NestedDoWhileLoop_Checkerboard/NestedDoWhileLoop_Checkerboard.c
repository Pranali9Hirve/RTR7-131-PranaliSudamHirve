#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_i, psh_j, psh_c;

    // Code
    printf("\n\n");
    psh_i = 0;
    do
    {
        psh_j = 0;
        do
        {
            psh_c = ((psh_i & 0X8) == 0) ^ ((psh_j & 0X8) == 0);
            if (psh_c == 0)
            {
                printf(" ");
            }

            if (psh_c == 1)
            {
                printf("# ");
            }
            psh_j++;
        }while ( psh_j < 64 );
        psh_i++;
        printf("\n\n");
    }while ( psh_i < 64);
    return(0);
}
