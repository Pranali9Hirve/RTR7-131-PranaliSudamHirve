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
    printf("Size of MyStruct = %zu\n", sizeof(psh_s));

    printf("\n\n");
    printf("Size of MyUnion = %zu\n", sizeof(psh_u));

    return(0);
}
