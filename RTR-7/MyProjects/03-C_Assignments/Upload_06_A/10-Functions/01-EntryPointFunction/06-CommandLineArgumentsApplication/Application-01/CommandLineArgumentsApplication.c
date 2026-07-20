#include <stdio.h> //'stdio.h' contains declaration of 'printf()'
#include <ctype.h> //'ctype.h' contains declaration of 'atoi()'
#include <stdlib.h> //'stdlib.h'  contains declaration of 'exit()'

int main(int argc, char *argv[], char *envp[])
{
    // Variable Declarations
    int psh_i;
    int psh_num;
    int psh_sum = 0;

    // Code
    if(argc == 1)
    {
        printf("\n\n");
        printf("No Numbers Given For Addition !!! Exitting Now...\n\n");
        printf("Usage : CommandLineArgumentsApplication <First Number> <Second Number>... \n\n");
        exit(0);
    }

    // *** This PROGRAMS ADDS ALL COMMAND LINE ARGUMENTS GIVEN IN INTEGER FORM ONLY AND OUTPUTS THE SUM ***
    // *** DUE TO USE OF atio(), ALL COMMAND LINE ARGUMENTS OF TYPES OTHER THAN 'int' ARE IGNORED ***
    printf("\n\n");
    printf("Sum of all integer  COMMAND LINE ARGUMENTS is : \n\n");
    // Loop starts from i = 1 because, i = 0 will result in 'argv[i]' = 'argv[0]' which is the name of the program itself i.e :
    // CommandLineArgumentsApplication.exe
    for (psh_i = 1; psh_i < argc; psh_i++)
    {
        psh_num = atoi(argv[psh_i]);
        psh_sum += psh_num;
    }

    printf("Sum = %d \n\n", psh_sum);
    return(0);
}
