#include <stdio.h>
#include <string.h> // for toupper()

int main(void)
{
    // variable declarations
    char psh_ch, psh_ch_i;
    unsigned int psh_ascii_ch = 0;

    // code
    printf("\n\n");
    printf("Enter The First Character Of First Name : ");
    psh_ch = getch();

    psh_ch = toupper(psh_ch);

    for (psh_ch_i = 'A'; psh_ch_i <= 'Z'; psh_ch_i++)
    {
        if (psh_ch == psh_ch_i)
        {
            psh_ascii_ch = (unsigned int) psh_ch;
            // program flow jumps directly to label 'psh_result_output' 
            goto psh_result_output;
        }
    }

    printf("\n\n");
    printf("Goto statement not executed, so printing \"Hello, world !!!!\n"); // will be omitted if 'goto' statement is executed

    // Label itself does not alter flow of program. Following code is executed regardless of whether goto statement executed or not
    psh_result_output: 
        printf("\n\n");

        if (psh_ascii_ch == 0)
        {
            printf("You must have a strange name! Could not find the character '%c' in the entire English Alphabet!\n", psh_ch);
        }
        else
        {
            printf("Character '%c' found. It has ASCII value %u.\n", psh_ch, psh_ascii_ch);
        }

        printf("\n\n");
        return(0);
}
