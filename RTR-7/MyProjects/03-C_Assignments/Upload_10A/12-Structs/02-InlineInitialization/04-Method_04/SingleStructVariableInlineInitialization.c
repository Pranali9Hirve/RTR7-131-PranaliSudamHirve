#include<stdio.h>

// DEFINING STRUCT
struct MyData
{
    int psh_i;
    float psh_f;
    double psh_d;
    char psh_c;
};

int main(void)
{
    // Variable Declarations
    struct MyData psh_data_one = {131, 2.5f, 5.2555, 'A'};
    struct MyData psh_data_two = {'A', 6.2f,  12.6543, 68};
    struct MyData psh_data_three = {131, 'P'};
    struct MyData psh_data_four = {79};
    
    // Code
    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData psh_data_one' ARE: \n\n");
    printf("psh_i = %d\n", psh_data_one.psh_i);
    printf("psh_f = %f\n", psh_data_one.psh_f);
    printf("psh_d = %lf\n", psh_data_one.psh_d);
    printf("psh_c = %c\n", psh_data_one.psh_c);

    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData psh_data_two' ARE: \n\n");
    printf("psh_i = %d\n", psh_data_two.psh_i);
    printf("psh_f = %f\n", psh_data_two.psh_f);
    printf("psh_d = %lf\n", psh_data_two.psh_d);
    printf("psh_c = %c\n", psh_data_two.psh_c);

    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData psh_data_three' ARE: \n\n");
    printf("psh_i = %d\n", psh_data_three.psh_i);
    printf("psh_f = %f\n", psh_data_three.psh_f);
    printf("psh_d = %lf\n", psh_data_three.psh_d);
    printf("psh_c = %c\n", psh_data_three.psh_c);

    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData psh_data_four' ARE: \n\n");
    printf("psh_i = %d\n", psh_data_four.psh_i);
    printf("psh_f = %f\n", psh_data_four.psh_f);
    printf("psh_d = %lf\n", psh_data_four.psh_d);
    printf("psh_c = %c\n", psh_data_four.psh_c);

    return(0);
}
