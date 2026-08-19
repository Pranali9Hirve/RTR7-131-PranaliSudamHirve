#include<stdio.h>

struct MyStruct
{
    int psh_i;
    float psh_f;
    double psh_d;
    char psh_c;
};

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
    struct MyStruct psh_s;
    union MyUnion psh_u;
    
    // Code
    printf("\n\n");
    printf("Members of struct are: \n\n");

    psh_s.psh_i = 131;
    psh_s.psh_f = 131.33f;
    psh_s.psh_d = 131.3456;
    psh_s.psh_c = 'A';

    printf(" psh_s.psh_i = %d\n", psh_s.psh_i);
    printf(" psh_s.psh_f = %f\n", psh_s.psh_f);
    printf(" psh_s.psh_d = %lf\n", psh_s.psh_d);
    printf(" psh_s.psh_c = %c\n", psh_s.psh_c);

    printf("Addresses of MEMBERS OF 'struct' ARE: \n\n");
    printf("psh_s.psh_i = %p\n", &psh_s.psh_i);
    printf("psh_s.psh_f = %p\n", &psh_s.psh_f);
    printf("psh_s.psh_d = %p\n", &psh_s.psh_d);
    printf("psh_s.psh_c = %p\n", &psh_s.psh_c);

    printf("MyStruct psh_s = %p\n\n", &psh_s);

    printf("\n\n");

    printf("Members of Union u2 Are: \n\n");

    psh_u.psh_i = 22;
    printf("psh_i = %d\n", psh_u.psh_i);

    psh_u.psh_f = 131.33f;
    printf("psh_f = %f\n", psh_u.psh_f);

    psh_u.psh_d = 131.3456;
    printf("psh_d = %lf\n", psh_u.psh_d);

    psh_u.psh_c = 'P';
    printf("psh_c = %c\n", psh_u.psh_c);

    printf("Addresses of MEMBERS OF 'union MyUnion psh_u2 ' ARE: \n\n");
    printf("psh_i = %p\n", &psh_u.psh_i);
    printf("psh_f = %p\n", &psh_u.psh_f);
    printf("psh_d = %p\n", &psh_u.psh_d);
    printf("psh_c = %p\n", &psh_u.psh_c);

    printf("MyUnion psh_u = %p \n\n", &psh_u);
    return(0);
}
