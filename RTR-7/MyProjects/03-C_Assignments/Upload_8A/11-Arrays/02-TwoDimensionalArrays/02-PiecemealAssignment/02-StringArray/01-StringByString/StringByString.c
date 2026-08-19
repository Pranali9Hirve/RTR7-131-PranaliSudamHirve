// StringByString.c

#include <stdio.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Function prototype
    void MyStrcpy(char[], char[]);

    // Variable declarations

    // *** A 'STRING' IS AN ARRAY OF CHARACTERS ... so char[] IS A char ARRAY AND
    // *** HENCE, char[] IS A 'STRING' ***
    // *** AN ARRAY OF char ARRAYS IS AN ARRAY OF STRINGS !!! ***
    // *** HENCE, char[] IS ONE char ARRAY AND HENCE, IS ONE STRING ***
    // *** HENCE, char[][] IS AN ARRAY OF char ARRAYS AND HENCE, IS AN ARRAY OF
    // *** STRINGS ***

    // Here, the string array can allow a maximum number of 5 strings (5 rows) and
    // each of these 5 strings can have only upto 10 characters maximum (10 columns)

    char psh_strArray[5][10]; // 5 ROWS (0, 1, 2, 3, 4) -> 5 STRINGS
                           // (EACH STRING CAN HAVE A MAXIMUM OF 10 CHARACTERS)

    int psh_char_size;
    int psh_strArray_size;
    int psh_strArray_num_elements, psh_strArray_num_rows, psh_strArray_num_columns;
    int psh_i;

    // Code

    printf("\n\n");

    psh_char_size = sizeof(char);
    psh_strArray_size = sizeof(psh_strArray);

    printf("Size Of Two Dimensional (2D) Character Array (String Array) Is = %d\n\n",
           psh_strArray_size);

    psh_strArray_num_rows = psh_strArray_size / sizeof(psh_strArray[0]);

    printf("Number of Rows (Strings) In Two Dimensional (2D) Character Array "
           "(String Array) Is = %d\n\n",
           psh_strArray_num_rows);

    psh_strArray_num_columns = sizeof(psh_strArray[0]) / psh_char_size;

    printf("Number of Columns In Two Dimensional (2D) Character Array "
           "(String Array) Is = %d\n\n",
           psh_strArray_num_columns);

    psh_strArray_num_elements = psh_strArray_num_rows * psh_strArray_num_columns;

    printf("Maximum Number of Elements (Characters) In Two Dimensional (2D) "
           "Character Array (String Array) Is = %d\n\n",
           psh_strArray_num_elements);

    // *** PIECE-MEAL ASSIGNMENT ***

    MyStrcpy(psh_strArray[0], "My");
    MyStrcpy(psh_strArray[1], "Name");
    MyStrcpy(psh_strArray[2], "Is");
    MyStrcpy(psh_strArray[3], "Pranali");
    MyStrcpy(psh_strArray[4], "Hirve");

    printf("\n\n");
    printf("The Strings In the 2D Character Array Are : \n\n");

    for (psh_i = 0; psh_i < psh_strArray_num_rows; psh_i++)
    {
        printf("%s \n", psh_strArray[psh_i]);
    }
    printf("\n\n");

    return (0);
}

void MyStrcpy(char str_destination[], char str_source[])
{
    // Function prototype
    int MyStrlen(char[]);

    // Variable declarations
    int psh_iStringLength = 0;
    int psh_j;

    psh_iStringLength = MyStrlen(str_source);

    for (psh_j = 0; psh_j < psh_iStringLength; psh_j++)
        str_destination[psh_j] = str_source[psh_j];

    str_destination[psh_j] = '\0';
}

int MyStrlen(char str[])
{
    // Variable declarations
    int psh_j;
    int psh_string_length = 0;

    // Code

    // *** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST
    // *** OCCURRENCE OF NULL-TERMINATING CHARACTER ('\0') ***

    for (psh_j = 0; psh_j < PSH_MAX_STRING_LENGTH; psh_j++)
    {
        if (str[psh_j] == '\0')
            break;
        else
            psh_string_length++;
    }

    return (psh_string_length);
}
