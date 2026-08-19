#include<stdio.h>
#include<conio.h>

// DEFINING STRUCT
struct MyData
{
    int psh_i;
    float psh_f;
    double psh_d;
    char psh_ch;
};

int main(void)
{
    // Variable Declarations
    struct MyData psh_data;
    
    // Code
    printf("\n\n");
    printf("Enter Integer Value For Data Member 'psh_i' of 'struct MyData' \n\n");
    scanf("%d", &psh_data.psh_i);

    printf("Enter Float Value For Data Member 'psh_f' of 'struct MyData' \n\n");
    scanf("%f", &psh_data.psh_f);

    printf("Enter Double Value For Data Member 'psh_d' of 'struct MyData' \n\n");
    scanf("%lf", &psh_data.psh_d);

    printf("Enter Charater Value For Data Member 'psh_c' of 'struct MyData' \n\n");
    psh_data.psh_ch = getch();
    


    printf("\n\n");
    printf("DATA MEMBERS OF 'struct MyData psh_data' ARE: \n\n");
    printf("psh_i = %d\n", psh_data.psh_i);
    printf("psh_f = %f\n", psh_data.psh_f);
    printf("psh_d = %lf\n", psh_data.psh_d);
    printf("psh_c = %c\n", psh_data.psh_ch);

    return(0);
}
