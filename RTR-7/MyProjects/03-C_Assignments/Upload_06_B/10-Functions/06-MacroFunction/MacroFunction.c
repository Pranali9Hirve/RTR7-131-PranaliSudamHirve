#include <stdio.h>

#define MAX_NUMBER(psh_a, psh_b) ((psh_a > psh_b) ? psh_a : psh_b)

int main(int argc, char *argv[], char *envp[])
{
    // Variable declarations
    int psh_iNum_01;
    int psh_iNum_02;
    int psh_iResult;

    float psh_fNum_01;
    float psh_fNum_02;
    float psh_fResult;

    // Code
    // ****** COMPARING INTEGER VALUES ******

    printf("\n\n");
    printf("Enter An Integer Number : \n\n");
    scanf("%d", &psh_iNum_01);

    printf("\n\n");
    printf("Enter Another Integer Number : ");
    scanf("%d", &psh_iNum_02); 

    psh_iResult = MAX_NUMBER(psh_iNum_01, psh_iNum_02);

    printf("\n\n");
    printf("Result of Macro Function MAX_NUMBER() = %d\n", psh_iResult);
    printf("\n\n");

    // ****** COMPARING FLOATING-POINT VALUES ******

    printf("\n\n");
    printf("Enter A Floating Point Number :");
    scanf("%f", &psh_fNum_01);

    printf("\n\n");
    printf("Enter Another Floating Point Number :");
    scanf("%f", &psh_fNum_02);

    psh_fResult = MAX_NUMBER(psh_fNum_01, psh_fNum_02);

    printf("\n\n");
    printf("Result Of Macro Function MAX_NUMBER() = %f\n", psh_fResult);

    printf("\n\n");

    return 0;
}
