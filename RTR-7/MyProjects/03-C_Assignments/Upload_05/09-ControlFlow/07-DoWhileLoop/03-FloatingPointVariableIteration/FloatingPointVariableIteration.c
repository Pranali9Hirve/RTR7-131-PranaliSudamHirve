#include<stdio.h>

int main(void)
{
    // Variable Declarations
    float psh_f;
    float psh_f_num = 1.0f; // Simply change this value ONLY to get different outputs...

    // Code
    printf("\n\n");
    printf("Printing numbers %f to %f : \n\n", psh_f_num, (psh_f_num * 10.0f));

    psh_f = psh_f_num;
    do
    {
        printf("\t %f \n", psh_f);
        psh_f = psh_f + psh_f_num;
    }while ( psh_f <= (psh_f_num * 10.0f));

    printf("\n\n");
    return(0);
}
