#include <stdio.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Function Prototypes
    void MyStrcpy(char[], char[]);

    // Variable declarations
    char psh_chArray_Original[PSH_MAX_STRING_LENGTH];
    char psh_chArray_Copy[PSH_MAX_STRING_LENGTH];

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter A String:\n\n");
    gets_s(psh_chArray_Original, PSH_MAX_STRING_LENGTH);

    // *** STRING COPY ***
    MyStrcpy(psh_chArray_Copy, psh_chArray_Original);

    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("The Original String Entered By You (i.e. psh_chArray_Original[]) Is:\n\n");
    printf("%s\n", psh_chArray_Original);

    printf("\n\n");
    printf("The Copied String (i.e. psh_chArray_Copy[]) Is:\n\n");
    printf("%s\n", psh_chArray_Copy);

    return 0;
}

void MyStrcpy(char psh_str_destination[], char psh_str_source[])
{
    // Function Prototypes
    int MyStrlen(char[]);

    // Variable Declarations
    int psh_iStringLength = 0;
    int psh_j;

    // Code
    psh_iStringLength = MyStrlen(psh_str_source);

    for (psh_j = 0; psh_j < psh_iStringLength; psh_j++)
    {
        psh_str_destination[psh_j] = psh_str_source[psh_j];
    }

    // Copy the null character
    psh_str_destination[psh_j] = '\0';
}

int MyStrlen(char psh_str[])
{
    int psh_j;
    int psh_string_length = 0;

    for (psh_j = 0; psh_j < PSH_MAX_STRING_LENGTH; psh_j++)
    {
        if (psh_str[psh_j] == '\0')
            break;
        else
        psh_string_length++;
    }

    return (psh_string_length);
}
