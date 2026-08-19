#include<stdio.h>
#include <stdlib.h>

int main(void)
{
    // Function Declarations
    void PshMathematicalOperations(int, int, int *, int *,  int *, int *, int *);

    // Variable Declarations
    int psh_a, psh_b;
    int *psh_answer_sum;
    int *psh_answer_difference;
    int *psh_answer_product;
    int *psh_answer_quotient;
    int *psh_answer_remainder;

    // Code
    printf("\n\n");
    printf("Enter Value of 'psh_a': \n");
    scanf("%d", &psh_a);

    printf("Enter Value of 'psh_b': \n");
    scanf("%d", &psh_b);

    psh_answer_sum = (int *)malloc( 1 * sizeof(int));
    if (psh_answer_sum == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY FOR psh_answer_sum !!! EXITING NOW...\n\n");
        exit(0);
    }

    psh_answer_difference = (int *)malloc( 1 * sizeof(int));
    if (psh_answer_difference == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY FOR psh_answer_difference !!! EXITING NOW...\n\n");
        exit(0);
    }

    psh_answer_product = (int *)malloc( 1 * sizeof(int));
    if (psh_answer_product == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY FOR psh_answer_product !!! EXITING NOW...\n\n");
        exit(0);
    }

    psh_answer_quotient = (int *)malloc( 1 * sizeof(int));
    if (psh_answer_quotient == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY FOR psh_answer_quotient !!! EXITING NOW...\n\n");
        exit(0);
    }

    psh_answer_remainder = (int *)malloc( sizeof(int) * 1);
    if (psh_answer_remainder == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY FOR psh_answer_remainder !!! EXITING NOW...\n\n");
        exit(0);
    }

    PshMathematicalOperations(psh_a, psh_b, psh_answer_sum, psh_answer_difference, psh_answer_product, psh_answer_quotient, psh_answer_remainder);

    printf("\n\n");
    printf("****** RESULTS *********** \n");
    printf("Sum = %d\n", *psh_answer_sum);
    printf("Difference = %d\n", *psh_answer_difference);
    printf("Product = %d\n", *psh_answer_product);
    printf("Quotient = %d\n", *psh_answer_quotient);
    printf("Remainder = %d\n", *psh_answer_remainder);

    if (psh_answer_remainder)
    {
        free(psh_answer_remainder);
        psh_answer_remainder = NULL;
        printf("MEMORY ALLOCATED psh_answer_remainder PshEmployee HAS BEEN SUCCESSFULLY FREED !!!\n\n");
    }

    if (psh_answer_quotient)
    {
        free(psh_answer_quotient);
        psh_answer_quotient = NULL;
        printf("MEMORY ALLOCATED psh_answer_quotient PshEmployee HAS BEEN SUCCESSFULLY FREED !!!\n\n");
    }

    if (psh_answer_product)
    {
        free(psh_answer_product);
        psh_answer_product = NULL;
        printf("MEMORY ALLOCATED psh_answer_product PshEmployee HAS BEEN SUCCESSFULLY FREED !!!\n\n");
    }

    if (psh_answer_difference)
    {
        free(psh_answer_difference);
        psh_answer_difference = NULL;
        printf("MEMORY ALLOCATED psh_answer_difference PshEmployee HAS BEEN SUCCESSFULLY FREED !!!\n\n");
    }

    if (psh_answer_sum)
    {
        free(psh_answer_sum);
        psh_answer_sum = NULL;
        printf("MEMORY ALLOCATED psh_answer_sum PshEmployee HAS BEEN SUCCESSFULLY FREED !!!\n\n");
    }

    return(0);
}

void PshMathematicalOperations(int psh_x, int psh_y, int *psh_sum, int *psh_difference, int *psh_product, int *psh_quotient, int *psh_remainder)
{
    // Code
    *psh_sum = psh_x + psh_y; // Value at address 'psh_sum' =  (psh_x + psh_y)
    *psh_difference = psh_x - psh_y; // Value at address 'psh_difference' = (psh_x - psh_y)
    *psh_product = psh_x * psh_y; // Value at address 'psh_product' = (psh_x * psh_y)
    *psh_quotient = psh_x / psh_y; // Value at address 'psh_quotient' = (psh_x / psh_y)
    *psh_remainder = psh_x % psh_y; // Value at address 'psh_remainder' = (psh_x % psh_y)
}
