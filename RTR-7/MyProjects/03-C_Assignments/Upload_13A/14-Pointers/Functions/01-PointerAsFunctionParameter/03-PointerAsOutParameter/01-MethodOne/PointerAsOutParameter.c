#include<stdio.h>

int main(void)
{
    // Function Declarations
    void MathematicalOperations(int, int, int *, int *,  int *, int *, int *);

    // Variable Declarations
    int psh_a, psh_b;
    int psh_answer_sum;
    int psh_answer_difference;
    int psh_answer_product;
    int psh_answer_quotient;
    int psh_answer_remainder;

    // Code
    printf("\n\n");
    printf("Enter Value of 'psh_a': \n");
    scanf("%d", &psh_a);

    printf("Enter Value of 'psh_b': \n");
    scanf("%d", &psh_b);

    // PASSING ADDRESSES TO FUNCTION... FUNCTION WILL FILL THEM UP WITH VALUES... 
    // HENCE, THEY GO INTO THE FUNCTION AS ADDRESS PARAMETERS AND COME OUT OF THE FUNCTION FILLED WITH THE VALID VALUES
    // THUS, (&psh_answer_sum, &psh_answer_difference, &psh_answer_product, &psh_answer_quotient, &psh_answer_remainder)
    // ARE CALLED "OUT PARAMETERS" OR "PARAMETERIZED RETURN VALUES" ... RETURN VALUES OF FUNCTIONS COMING VIA PARAMETERS
    // HENCE, ALTHOUGH EACH FUNCTION HAS ONLY ONE RETURN VALUE, USING THE CONCEPT OF "PARAMETERIZED RETURN VALUES", 
    // OUR FUNCTION "MathematicalOperations()" HAS GIVEN US 5 RETURN VALUES !!!

    MathematicalOperations(psh_a, psh_b, &psh_answer_sum, &psh_answer_difference, &psh_answer_product, &psh_answer_quotient, &psh_answer_remainder);

    printf("\n\n");
    printf("****** RESULTS *********** \n");
    printf("Sum = %d\n", psh_answer_sum);
    printf("Difference = %d\n", psh_answer_difference);
    printf("Product = %d\n", psh_answer_product);
    printf("Quotient = %d\n", psh_answer_quotient);
    printf("Remainder = %d\n", psh_answer_remainder);
    return(0);
}

void MathematicalOperations(int psh_x, int psh_y, int *psh_sum, int *psh_difference, int *psh_product, int *psh_quotient, int *psh_remainder)
{
    // Code
    *psh_sum = psh_x + psh_y; // Value at address 'psh_sum' =  (psh_x + psh_y)
    *psh_difference = psh_x - psh_y; // Value at address 'psh_difference' = (psh_x - psh_y)
    *psh_product = psh_x * psh_y; // Value at address 'psh_product' = (psh_x * psh_y)
    *psh_quotient = psh_x / psh_y; // Value at address 'psh_quotient' = (psh_x / psh_y)
    *psh_remainder = psh_x % psh_y; // Value at address 'psh_remainder' = (psh_x % psh_y)
}
