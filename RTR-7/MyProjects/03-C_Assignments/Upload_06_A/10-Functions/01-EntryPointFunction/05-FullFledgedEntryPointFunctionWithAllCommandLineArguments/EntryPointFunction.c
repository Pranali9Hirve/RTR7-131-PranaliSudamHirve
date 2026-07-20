#include <stdio.h> //'stdio.h' contains declaration of 'printf()'

// Entry-Point Function => main() => Valid Return Type(int) and 3 Parameters(int argc, char *argv[], char *envp[])
int main(int argc, char *argv[], char *envp[])
{
    // Variable Declarartions
    int psh_i;

    // Code
    printf("\n\n");
    printf("Hello World !!!\n"); // Library Function
    printf("Number of Command Line Arguments = %d\n\n", argc);

    printf("Command Line Arguments passed to this Program are:  \n\n");
    for (psh_i = 0; psh_i < argc; psh_i++)
    {
        printf("Command Line Argument Number %d = %s\n", (psh_i + 1), argv[psh_i]);
    }
    printf("\n\n");

    printf("First 20 Environmental Variables Passed To This Program are : \n\n");
    for (psh_i = 0; psh_i < 20; psh_i++)
    {
        printf("Environmental Variable Number %d = %s \n", (psh_i + 1), envp[psh_i]);
    }
    printf("\n\n");
    return(0);
}
