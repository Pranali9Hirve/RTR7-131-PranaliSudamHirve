#include<stdio.h>

// DEFINING STRUCT
struct MyData
{
    int psh_i;
    float psh_f;
    double psh_d;
    char psh_c;
} data = {131, 4.5f, 11.2345, 'A'};

int main(void)
{
    // Code
    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData' ARE: \n\n");
    printf("psh_i = %d\n", data.psh_i);
    printf("psh_f = %f\n", data.psh_f);
    printf("psh_d = %lf\n", data.psh_d);
    printf("psh_c = %c\n", data.psh_c);

    return(0);
}
