// CharacterByCharacter.c

#include <stdio.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
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

    // ****** ROW 1 / STRING 1 ******
    psh_strArray[0][0] = 'M';
    psh_strArray[0][1] = 'y';
    psh_strArray[0][2] = '\0'; // NULL-TERMINATING CHARACTER

    // ****** ROW 2 / STRING 2 ******
    psh_strArray[1][0] = 'N';
    psh_strArray[1][1] = 'a';
    psh_strArray[1][2] = 'm';
    psh_strArray[1][3] = 'e';
    psh_strArray[1][4] = '\0'; // NULL-TERMINATING CHARACTER

    // ****** ROW 3 / STRING 3 ******
    psh_strArray[2][0] = 'I';
    psh_strArray[2][1] = 's';
    psh_strArray[2][2] = '\0'; // NULL-TERMINATING CHARACTER

    // ****** ROW 4 / STRING 4 ******
    psh_strArray[3][0] = 'P';
    psh_strArray[3][1] = 'r';
    psh_strArray[3][2] = 'a';
    psh_strArray[3][3] = 'n';
    psh_strArray[3][4] = 'a';
    psh_strArray[3][5] = 'l';
    psh_strArray[3][6] = 'i';
    psh_strArray[3][7] = '\0'; // NULL-TERMINATING CHARACTER

    // ****** ROW 5 / STRING 5 ******
    psh_strArray[4][0] = 'H';
    psh_strArray[4][1] = 'i';
    psh_strArray[4][2] = 'r';
    psh_strArray[4][3] = 'v';
    psh_strArray[4][4] = 'e';
    psh_strArray[4][5] = '\0'; // NULL-TERMINATING CHARACTER

    printf("\n\n");
    printf("The Strings In the 2D Character Array Are : \n\n");

    for (psh_i = 0; psh_i < psh_strArray_num_rows; psh_i++)
        printf("%s ", psh_strArray[psh_i]);

    printf("\n\n");

    return (0);
}

int MyStrlen(char psh_str[])
{
    // Variable declarations
    int psh_j;
    int psh_string_length = 0;

    // *** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST
    // *** OCCURRENCE OF NULL-TERMINATING CHARACTER ('\0') ***

    for (psh_j = 0; psh_j < PSH_MAX_STRING_LENGTH; psh_j++)
    {
        if (psh_str[psh_j] == '\0')
            break;
        else
            psh_string_length++;
    }

    return (psh_string_length);
}
