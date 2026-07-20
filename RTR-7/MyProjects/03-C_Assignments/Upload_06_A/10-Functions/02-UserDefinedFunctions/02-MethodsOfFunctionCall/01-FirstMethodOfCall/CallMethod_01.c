#include <stdio.h>   // stdio.h contains declaration of printf() and scanf()

// User Defined Functions: Method of Calling Function 1
// Calling all functions in main() directly

// Entry-Point Function => main() => Valid Return Type (int) and 3 Parameters (int P arg, char *argv[l, char *envp[])
int main(int argc, char *argv[], char *envp[])
{
    // Function prototypes or declarations
    void MyAddition(void);
    int MySubtraction(void);
    void MyMultiplication(int, int);
    int MyDivision(int, int);

    // Variable declarations
    int psh_result_subtraction;
    int psh_a_multiplication, psh_b_multiplication;
    int psh_a_division, psh_b_division, psh_result_division;

    // Code
    // *** ADDITION ***
    MyAddition(); // Function Call

    // *** SUBTRACTION ***
    psh_result_subtraction = MySubtraction(); // Function Call
    printf("\n\n");
    printf("Subtraction Fields Result = %d\n", psh_result_subtraction);

    // *** MULTIPLICATION ***
    printf("\n\n");
    printf("Enter Integer Value For 'A' For Multiplication : ");
    scanf("%d", &psh_a_multiplication);

    printf("\n\n");
    printf("Enter Integer Value For 'B' For Multiplication : ");
    scanf("%d", &psh_b_multiplication);

    MyMultiplication(psh_a_multiplication, psh_b_multiplication); // Function Call

    // *** DIVISION ***
    printf("\n\n");
    printf("Enter Integer Value For 'A' For Division : ");
    scanf("%d", &psh_a_division);

    printf("\n\n");
    printf("Enter Integer Value For 'B' For Division : ");
    scanf("%d", &psh_b_division);

    psh_result_division = MyDivision(psh_a_division, psh_b_division); // Function Call

    printf("\n\n");
    printf("Division Of %d And %d Gives = %d (Quotient)\n",
           psh_a_division, psh_b_division, psh_result_division);

    printf("\n\n");

    return 0;
}

// *** Function Definition Of MyAddition() ***
void MyAddition(void) //Function Definition
{
    // Variable Declarations: Local variables to MyAddition()
    int psh_a, psh_b, psh_sum;

    // Code
    printf("\n\n");
    printf("Enter Integer Value For 'A' For Addition : ");
    scanf("%d", &psh_a);

    printf("\n\n");
    printf("Enter Integer Value For 'B' For Addition : ");
    scanf("%d", &psh_b);

    psh_sum = psh_a + psh_b;

    printf("\n\n");
    printf("Sum Of %d And %d = %d\n\n", psh_a, psh_b, psh_sum);
}

// *** Function Definition Of MySubtraction() ***
int MySubtraction(void) //Function Definition
{
    // Variable Declarations: Local variables to MySubtraction()
    int psh_a, psh_b, psh_subtraction;

    // Code
    printf("\n\n");
    printf("Enter Integer Value For 'A' For Subtraction : ");
    scanf("%d", &psh_a);

    printf("\n\n");
    printf("Enter Integer Value For 'B' For Subtraction : ");
    scanf("%d", &psh_b);

    psh_subtraction = psh_a - psh_b;

    return psh_subtraction;
}

// *** Function Definition Of MyMultiplication() ***
void MyMultiplication(int psh_a, int psh_b) // Function Definition
{
    // Variable Declarations: Local variables to MyMultiplication()
    int psh_multiplication;

    // Code
    psh_multiplication = psh_a * psh_b;

    printf("\n\n");
    printf("Multiplication Of %d And %d = %d\n\n",
           psh_a, psh_b, psh_multiplication);
}

// *** Function Definition Of MyDivision() ***
int MyDivision(int psh_a, int psh_b)
{
    // Variable Declarations: Local variables to MyDivision()
    int psh_division_quotient;

    // Code
    if (psh_a > psh_b)
        psh_division_quotient = psh_a / psh_b;
    else
        psh_division_quotient = psh_b / psh_a;

    return psh_division_quotient;
}
