#include <stdio.h>   // stdio.h contains declaration of printf()

// Entry-Point Function => main() => Valid Return Type (int) and 3 Parameters (int P arg, char *argv[l, char *envp[])
int main(int argc, char *argv[], char *envp[])
{
    // Function prototype / declaration / signature
    void MyAddition(void);

    // Function call
    MyAddition();
    return 0;
}

// ****** USER DEFINED FUNCTION : METHOD OF DEFINITION 1 ******
// ****** NO RETURN VALUE, NO PARAMETERS ******
void MyAddition(void) // Function Definition
{
    // Variable declarations: Local Variables to MyAddition()
    int psh_a, psh_b, psh_sum;

    // Code
    printf("\n\n");
    printf("Enter Integer Value For 'A' : ");
    scanf("%d", &psh_a);

    printf("\n\n");
    printf("Enter Integer Value For 'B' : ");
    scanf("%d", &psh_b);

    psh_sum = psh_a + psh_b;

    printf("\n\n");
    printf("Sum Of %d And %d = %d\n\n", psh_a, psh_b, psh_sum);
}
