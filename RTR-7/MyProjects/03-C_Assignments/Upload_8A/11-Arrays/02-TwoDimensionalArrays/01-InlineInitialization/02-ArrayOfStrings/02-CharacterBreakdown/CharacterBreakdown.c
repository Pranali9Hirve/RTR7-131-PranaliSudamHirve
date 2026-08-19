#include <stdio.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Function Prototype
    int MyStrLen(char[]);

    // variable declaraions
    // *** A 'STRING' IS AN ARRAY OF CHARACTERS ... SO char[] IS A char ARRAY AND HENCE, char[] IS A 'STRING' ***
    // *** AN ARRAY OF char ARRAYS IS AN ARRAY OF STRINGS !!! ***
    // *** HENCE, char[] IS ONE char ARRAY AND HENCE, IS ONE STRING ***
    // *** HENCE, CHAR[][] IS AN ARRAY OF char ARRAYS OF char ARRAYS AND HENCE, IS AN ARRAY OF STRINGS ***

    // Here, the string array can allow a maximum number of 10 strings (10 rows) and each of these 10 strings can have only upto 15 characters maximum (15 columns)
    char psh_strArray[10][15] =
    {"Hello!", "Welcome", "To", "Real", "Time", "Rendering", "Batch", "2026-27", "Of", "ASTROMEDICOMP"};

    int psh_iStrengths[10];
    int psh_strArray_size;
    int psh_strArray_num_rows;
    int psh_i, psh_j;

    // code
    printf("\n\n");
    
    psh_strArray_size = sizeof(psh_strArray);
    psh_strArray_num_rows = psh_strArray_size / sizeof(psh_strArray[0]);

    // Storing in lengths of all the strings...
    for(psh_i = 0; psh_i < psh_strArray_num_rows; psh_i++)
    {
        psh_iStrengths[psh_i] = MyStrLen(psh_strArray[psh_i]);
    }

    printf("\n\n");

    printf("The Entire String Array: \n\n");
    for(psh_i = 0; psh_i < psh_strArray_num_rows; psh_i++)
    {
        printf("%s ", psh_strArray[psh_i]);
    }
           
    printf("\n\n");
    printf("Strings In The 2D Array: \n\n");

    for(psh_i = 0; psh_i < psh_strArray_num_rows; psh_i++)
    {
        printf("String Number %d => %s \n\n", (psh_i + 1), psh_strArray[psh_i]);
        for(psh_j = 0; psh_j<psh_iStrengths[psh_i]; psh_j++)
        {
            printf("Character %d = %c \n", (psh_j + 1), psh_strArray[psh_i][psh_j]);
        }
        printf("\n\n");
    }

    return (0);
}

int MyStrLen(char psh_str[])
{
    // Variable Declarations
    int psh_j;
    int psh_string_length = 0;

    // Code
    // Determining exact length of the string by detecting the first occurance of NULL-TERMINATING CHARACTER (\0)
    for (psh_j = 0; psh_j < PSH_MAX_STRING_LENGTH; psh_j++)
    {
        if (psh_str[psh_j] == '\0')
            break;
        else
        psh_string_length++;
    }

    return (psh_string_length);
}
