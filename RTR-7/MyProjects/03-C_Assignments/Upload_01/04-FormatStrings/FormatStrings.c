#include<stdio.h>

int main(void)
{
    // Code
    printf("\n\n");
    printf("**************************************************************");
    printf("\n\n");

    printf("Hello, World !!! \n\n");

    int psh_a = 131;
    printf("Integer Decimal value of 'psh_a' = %d\n", psh_a);
    printf("Integer Octal value of 'psh_a' = %o\n", psh_a);
    printf("Integer Hexadecimal value of 'psh_a' (Hexadecimal Letters In Lower Case) = %x\n", psh_a);
    printf("Integer Hexadecimal value of 'psh_a' (Hexadecimal Letters In Upper Case) = %X\n\n", psh_a);

    char psh_ch = 'P';
    printf("Character ch = %c\n", psh_ch);
    char psh_str[] = "Astromedicomp's Real Time Rendering Bath";
    printf("String str = %s\n\n", psh_str);

    long psh_num = 30121995L;
    printf("Long Integer 'psh_num' = %ld\n\n", psh_num);

    unsigned int psh_b = 131;
    printf("Unsigned Integer 'psh_b' = %u\n\n", psh_b);

    float psh_f_num = 3012.1995f;
    printf("Floating Point Number With Just %%f 'psh_f_num' = %f\n", psh_f_num);
    printf("Floating Point Number With %%4.2f 'psh_f_num' = %4.2f\n", psh_f_num);
    printf("Floating Point Number With %%6.5f 'psh_f_num' = %6.5f\n", psh_f_num);
    printf("Floating Point Number With %%4.1f 'psh_f_num' = %4.1f\n\n", psh_f_num);

    double psh_d_pi = 3.14159265358979323846;
    printf("Double Precision Floating Point Number Without Exponential = %g\n", psh_d_pi);
    printf("Double Precision Floating Point Number With Exponential(Lower Case) = %e\n", psh_d_pi);
    printf("Double Precision Floating Point Number With Exponential(Upper Case) = %E\n", psh_d_pi);
    printf("Double Hexadecimal Value Of 'psh_d_pi' (Hexadecimal Letters In Lower Case) = %a\n", psh_d_pi);
    printf("Double Hexadecimal Value Of 'psh_d_pi' (Hexadecimal Letters In Upper Case) = %A\n\n\n", psh_d_pi);

    printf("**************************************************************");
    printf("\n\n");

    return(0);
}
