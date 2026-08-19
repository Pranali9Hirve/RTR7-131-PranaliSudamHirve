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

    int psh_char_size;
    int psh_strArray_size;
    int psh_strArray_num_elements, psh_strArray_num_rows, psh_strArray_num_columns;
    int psh_strActual_num_chars = 0;
    int psh_i;

    // code
    printf("\n\n");

    psh_char_size = sizeof(char);
    
    psh_strArray_size = sizeof(psh_strArray);

    printf("Size Of Two Dimensional (2D) Character Array (string array) Is = %d\n\n",
           psh_strArray_size);

    psh_strArray_num_rows = psh_strArray_size / sizeof(psh_strArray[0]);
    printf("Number of Rows In Two Dimensional (2D) Character Array (string array) Is = %d\n\n",
           psh_strArray_num_rows);

    psh_strArray_num_columns = sizeof(psh_strArray[0]) / psh_char_size;
    printf("Number of Columns In Two Dimensional (2D) Character Array (string array) Is = %d\n\n",
           psh_strArray_num_columns);

    psh_strArray_num_elements = psh_strArray_num_rows * psh_strArray_num_columns;
    printf("Maximum Number of Elements In Two Dimensional (2D) Character Array (string array) Is = %d\n\n",
           psh_strArray_num_elements);

    printf("\n\n");

    for(psh_i = 0; psh_i < psh_strArray_num_rows; psh_i++)
    {
        psh_strActual_num_chars = psh_strActual_num_chars + MyStrLen(psh_strArray[psh_i]);
    }

    printf("Actual Number of Elements In Two Dimensional (2D) Character Array (string array) Is = %d\n\n",
           psh_strActual_num_chars);
           
    printf("\n\n");
    printf("Strings In The 2D Array: \n\n");

    printf("%s ", psh_strArray[0]);
    printf("%s ", psh_strArray[1]);
    printf("%s ", psh_strArray[2]);
    printf("%s ", psh_strArray[3]);
    printf("%s ", psh_strArray[4]);
    printf("%s ", psh_strArray[5]);
    printf("%s ", psh_strArray[6]);
    printf("%s ", psh_strArray[7]);
    printf("%s ", psh_strArray[8]);
    printf("%s \n\n", psh_strArray[9]);

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
