#include<stdio.h>
#include<string.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Function Prototypes
    void MyStrrev(char[], char[]);

    // Variable declarations
    char psh_chArray_Original[PSH_MAX_STRING_LENGTH], psh_chArray_reversed[PSH_MAX_STRING_LENGTH]; // A character array is a String

    // Code
    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter A String:\n\n");
    gets_s(psh_chArray_Original, PSH_MAX_STRING_LENGTH);

    // *** STRING REVERSE ***
    MyStrrev(psh_chArray_reversed, psh_chArray_Original);

    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("The Original String Entered By You (i.e. psh_chArray_Original[]) Is:\n\n");
    printf("%s\n", psh_chArray_Original);

    printf("\n\n");
    printf("The Reversed String (i.e. psh_chArray_Reverse[]) Is:\n\n");
    printf("%s\n", strrev(psh_chArray_Original));

    return 0;
}

void MyStrrev(char psh_str_destination[], char psh_str_source[])
{
    // Function Prototypes
    int MyStrlen(char[]);

    // Variable Declarations
    int psh_iStringLength = 0;
    int psh_i, psh_j, psh_len;

    psh_iStringLength = MyStrlen(psh_str_source);

    // Last valid index
    psh_len = psh_iStringLength - 1;

    // Copy characters in reverse order
    for (psh_i = 0, psh_j = psh_len; psh_i < psh_iStringLength; psh_i++, psh_j--)
    {
        psh_str_destination[psh_i] = psh_str_source[psh_j];
    }

    // Add null terminator
    psh_str_destination[psh_i] = '\0';
}

int MyStrlen(char psh_str[])
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
