#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_a;
    int psh_b;
    int psh_result;

    // Code
    printf("\n\n");
    printf("Enter One Integer : ");
    scanf("%d", &psh_a);

    printf("\n\n");
    printf("Enter Another Integer : ");
    scanf("%d", &psh_b);
    
    printf("\n\n");
    printf("If Answer = 0, It is \"FALSE\". \n");
    printf("If Answer = 1, It is \"TRUE\". \n\n");

    psh_result = (psh_a < psh_b);
    printf("(psh_a < psh_b) psh_a = %d Is Less Than psh_b = %d \t Answer = %d \n", psh_a, psh_b, psh_result);

    psh_result = (psh_a > psh_b);
    printf("(psh_a > psh_b) psh_a = %d Is Greater Than psh_b = %d \t Answer = %d \n", psh_a, psh_b, psh_result);

    psh_result = (psh_a <= psh_b);
    printf("(psh_a <= psh_b) psh_a = %d Is Less Than Or Equal To psh_b = %d \t Answer = %d \n", psh_a, psh_b, psh_result);

    psh_result = (psh_a >= psh_b);
    printf("(psh_a >= psh_b) psh_a = %d Is Greater Than Or Equal To psh_b = %d \t Answer = %d \n", psh_a, psh_b, psh_result);

    psh_result = (psh_a == psh_b);
    printf("(psh_a == psh_b) psh_a = %d Is Equal To psh_b = %d \t Answer = %d \n", psh_a, psh_b, psh_result);

    psh_result = (psh_a != psh_b);
    printf("(psh_a != psh_b) psh_a = %d Is NOT Equal To psh_b = %d \t Answer = %d \n", psh_a, psh_b, psh_result);

    printf("\n\n");

    return(0);
}
