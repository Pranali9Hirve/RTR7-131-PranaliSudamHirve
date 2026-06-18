#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_a;
    int psh_b;
    int psh_c;
    int psh_result;

    // Code
    printf("\n\n");
    printf("Enter First Integer : ");
    scanf("%d", &psh_a);

    printf("\n\n");
    printf("Enter Second Integer : ");
    scanf("%d", &psh_b);

    printf("\n\n");
    printf("Enter Third Integer : ");
    scanf("%d", &psh_c);

    printf("\n\n");
    printf("If Answer = 0, It is \"FALSE\". \n");
    printf("If Answer = 1, It is \"TRUE\". \n\n");

    psh_result = (psh_a <= psh_b) && (psh_b != psh_c);
    printf("LOGICAL AND (&&) : Answer is TRUE (1) If And Only If Both Conditions Are TRUE. The Answer is FALSE (0), If Any One Or Both Conditions Are FALSE. \n\n");
    printf("psh_a = %d Is Less Than Or Equal To psh_b = %d AND psh_b = %d Is NOT Equal To psh_c = %d \t Answer = %d \n\n", psh_a, psh_b, psh_b, psh_c, psh_result);

    psh_result = (psh_b >= psh_a) || (psh_a == psh_c);
    printf("LOGICAL OR (||) : Answer is FALSE (0) If And Only If Both Conditions Are FALSE. The Answer is TRUE (1), If Any One Or Both Conditions Are TRUE. \n\n");
    printf("Either psh_b = %d Is Greater Than Or Equal To psh_a = %d OR psh_a = %d Is Equal To psh_c = %d \t Answer = %d\n\n", psh_b, psh_a, psh_a, psh_c, psh_result);

    psh_result = !psh_a;
    printf("psh_a = %d And Using Logical NOT (!) Operator on psh_a Gives Result = %d \n\n", psh_a, psh_result);

    psh_result = !psh_b;
    printf("psh_b = %d And Using Logical NOT (!) Operator on psh_b Gives Result = %d \n\n", psh_b, psh_result);

    psh_result = !psh_c;
    printf("psh_C = %d And Using Logical NOT (!) Operator on psh_C Gives Result = %d \n\n", psh_c, psh_result);

    psh_result = (!(psh_a <= psh_b) && !(psh_b != psh_c));
    printf("Using Logical NOT (!) On (psh_a <= psh_b) And Also On (psh_b != psh_c) And then AND ing Them Afterwards Gives Result = %d \n", psh_result);

    printf("\n\n");

    psh_result = !((psh_b >= psh_a) || (psh_a == psh_c));
    printf("Using Logical NOT (!) On Entire Logical Expression (psh_b >= psh_a) || (psh_a == psh_c) Gives Result = %d \n", psh_result);

    printf("\n\n");
    
    return(0);
}