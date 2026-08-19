#include <stdio.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Function prototype
    int MyStrlen(char[]);

    // Variable declarations
    char psh_chArray[PSH_MAX_STRING_LENGTH];   // A character array is a string
    int psh_iStringLength = 0;

    // Code
    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter A String: \n\n");
    gets_s(psh_chArray, PSH_MAX_STRING_LENGTH);

    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("String Entered By You Is:\n\n");
    printf("%s", psh_chArray);

    // *** STRING LENGTH ***
    printf("\n");
    psh_iStringLength = MyStrlen(psh_chArray);

    printf("Length Of String Is = %d Characters !!!\n", psh_iStringLength);

    return 0;
}

int MyStrlen(char psh_str[])
{
    // Variable declarations
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

    return psh_string_length;
}
