#include<stdio.h>

union MyUnion
{
    int psh_i;
    float psh_f;
    double psh_d;
    char psh_c;
};

int main(void)
{
    // Variable Declarations
    union MyUnion psh_u1, psh_u2;
    
    // Code

    // ****** MyUnion u1 *******

    printf("\n\n");
    printf("Members of Union u1 Are: \n\n");

    psh_u1.psh_i = 131;
    psh_u1.psh_f = 131.33f;
    psh_u1.psh_d = 131.3456;
    psh_u1.psh_c = 'A';

    printf("\n\n");
    printf("DATA MEMBERS OF 'union MyUnion psh_u1 ' ARE: \n\n");
    printf("psh_i = %d\n", psh_u1.psh_i);
    printf("psh_f = %f\n", psh_u1.psh_f);
    printf("psh_d = %lf\n", psh_u1.psh_d);
    printf("psh_c = %c\n", psh_u1.psh_c);

    printf("Addresses of MEMBERS OF 'union MyUnion psh_u1 ' ARE: \n\n");
    printf("psh_i = %p\n", &psh_u1.psh_i);
    printf("psh_f = %p\n", &psh_u1.psh_f);
    printf("psh_d = %p\n", &psh_u1.psh_d);
    printf("psh_c = %p\n", &psh_u1.psh_c);

    printf("MyUnion psh_u1 = %p \n\n", &psh_u1);

    // ****** MyUnion u2 *******

    printf("\n\n");
    printf("Members of Union u2 Are: \n\n");

    psh_u2.psh_i = 22;
    printf("psh_i = %d\n", psh_u2.psh_i);

    psh_u2.psh_f = 131.33f;
    printf("psh_f = %f\n", psh_u2.psh_f);

    psh_u2.psh_d = 131.3456;
    printf("psh_d = %lf\n", psh_u2.psh_d);

    psh_u2.psh_c = 'P';
    printf("psh_c = %c\n", psh_u2.psh_c);

    printf("Addresses of MEMBERS OF 'union MyUnion psh_u2 ' ARE: \n\n");
    printf("psh_i = %p\n", &psh_u2.psh_i);
    printf("psh_f = %p\n", &psh_u2.psh_f);
    printf("psh_d = %p\n", &psh_u2.psh_d);
    printf("psh_c = %p\n", &psh_u2.psh_c);

    printf("MyUnion psh_u2 = %p \n\n", &psh_u2);
    return(0);
}
