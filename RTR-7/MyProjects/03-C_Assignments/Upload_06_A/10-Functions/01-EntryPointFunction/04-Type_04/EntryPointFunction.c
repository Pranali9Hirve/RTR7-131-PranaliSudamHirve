#include <stdio.h> //'stdio.h' contains declaration of 'printf()'

// Entry-Point Function => main() => Valid Return Type(int) and 2 Parameter(int argc, char *argv[])
int main(int argc, char *argv[])
{
    // Variable Declarations
    int i;
    
    // Code
    printf("\n\n");
    printf("Hello World !!!\n"); // Library Function
    printf("Number of Command Line Arguments = %d\n\n", argc);

    printf("Command Line Arguments passed to this Program are:  \n\n");
    for (i = 0; i < argc; i++)
    {
        printf("Command Line Argument Number %d = %s\n", (i + 1), argv[i]);
    }
    printf("\n\n");
    return(0);
}
