#include <stdio.h>   // stdio.h contains declaration of printf()

// Entry-Point Function => main() => Valid Return Type (int) and 3 Parameters (int P arg, char *argv[l, char *envp[])
int main(int argc, char *argv[], char *envp[])
{
    // Function prototype / declaration / signature
    int MyAddition(int, int);

    // Variable Declarations: Local variables to main()
    int psh_a, psh_b, psh_result;

    // Code
    printf("\n\n");
    printf("Enter Integer Value For 'A' : ");
    scanf("%d", &psh_a);

    printf("\n\n");
    printf("Enter Integer Value For 'B' : ");
    scanf("%d", &psh_b);

    psh_result = MyAddition(psh_a, psh_b); // Function Call
    printf("\n\n");
    printf("Sum Of %d And %d = %d\n\n", psh_a, psh_b, psh_result);
    return 0;
}

// ****** USER DEFINED FUNCTION : METHOD OF DEFINITION 4 ******
// ****** VALID (INT) RETURN TYPE, VALID PARAMETERS (int, int)******
int MyAddition(int psh_a, int psh_b) // Function Definition
{
    // Variable declarations: Local Variables to MyAddition()
    int psh_sum;

    // Code
    psh_sum = psh_a + psh_b;
    return(psh_sum);
}
