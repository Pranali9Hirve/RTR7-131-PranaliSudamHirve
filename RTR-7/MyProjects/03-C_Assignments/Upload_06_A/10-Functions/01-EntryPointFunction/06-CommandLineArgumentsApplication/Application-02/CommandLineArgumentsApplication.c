#include <stdio.h> //'stdio.h' contains declaration of 'printf()'
#include <stdlib.h> //'stdlib.h'  contains declaration of 'exit()'

int main(int argc, char *argv[], char *envp[])
{
    // Variable Declarations
    int psh_i;

    // Code
    if(argc != 4) // Program name + first name + middle name + surname = 4 Command Line Arguments are required
    {
        printf("\n\n");
        printf("Invalid Usage !!! Exitting Now...\n\n");
        printf("Usage : CommandLineArgumentsApplication <First Name> <Middle Name> <Surname>... \n\n");
        exit(0);
    }

    // *** THIS PROGRAMS PRINTS YOUR FULL NAME AS ENTERED IN THE COMMAND LINE ARGUMENTS ***
    printf("\n\n");
    printf("Your full name is : ");

    // Loop starts from i = 1 because, i = 0 will result in 'argv[i]' = 'argv[0]' which is the name of the program itself i.e :
    // CommandLineArgumentsApplication.exe
    for (psh_i = 1; psh_i < argc; psh_i++)
    {
        printf("%s \t", argv[psh_i]);
    }

    printf("\n\n");
    return(0);
}
