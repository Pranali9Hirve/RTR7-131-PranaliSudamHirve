#include<stdio.h>

int main(void)
{
    // Variable declaration
    int psh_a;
    int psh_b;
    int psh_result;

    // Code
    printf("\n\n");
    printf("Enter A number : ");
    scanf("%d", &psh_a);

    printf("\n\n");
    printf("Enter Another number : ");
    scanf("%d", &psh_b);

    printf("\n\n");

    /**
        The following are the 5 Arithmetic Operators +, -, *, / and %
        Also, the resultants of the Arithmetic Operators in all the below
        five cases have been assigned to the variable 'psh_result' using the 
        Arithmetic Operator (=)
    */
    psh_result = psh_a + psh_b;
    printf("Addintion of psh_a = %d And psh_b = %d gives %d. \n", psh_a, psh_b, psh_result);

    psh_result = psh_a - psh_b;
    printf("Subtraction of psh_a = %d And psh_b = %d gives %d. \n", psh_a, psh_b, psh_result);

    psh_result = psh_a * psh_b;
    printf("Multiplication of psh_a = %d And psh_b = %d gives %d. \n", psh_a, psh_b, psh_result);

    psh_result = psh_a / psh_b;
    printf("Division of psh_a = %d And psh_b = %d gives %d. \n", psh_a, psh_b, psh_result);

    psh_result = psh_a % psh_b;
    printf("Division of psh_a = %d And psh_b = %d gives %d. \n", psh_a, psh_b, psh_result);

    printf("\n\n");

    return(0);
}
