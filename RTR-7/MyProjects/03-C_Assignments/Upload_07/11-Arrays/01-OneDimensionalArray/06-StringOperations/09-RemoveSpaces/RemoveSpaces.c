#include<stdio.h>
#include<string.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Function Prototypes
    int MyStrLen(char[]);
    void MyStrCpy(char[], char[]);

    // Variable declarations
    char psh_chArray[PSH_MAX_STRING_LENGTH], psh_spaces_removed[PSH_MAX_STRING_LENGTH]; // A character array is a String
    int psh_iStringLength;
    int psh_i, psh_j;

    // Code
    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter A String:\n\n");
    gets_s(psh_chArray, PSH_MAX_STRING_LENGTH);

    psh_iStringLength = MyStrLen(psh_chArray);
    psh_j = 0;
    for (psh_i = 0; psh_i<psh_iStringLength; psh_i++)
    {
        if (psh_chArray[psh_i] == ' ')
        {
            continue;
        }
        else
        {
            psh_spaces_removed[psh_j] = psh_chArray[psh_i];
            psh_j++;
        }
    }
    psh_spaces_removed[psh_j] = '\0';

    // String Output
    printf("\n\n");
    printf("String Entered By You (i.e. psh_chArray) Is:\n\n");
    printf("%s\n", psh_chArray);

    printf("String After removal of space (i.e. psh_spaces_removed[]) Is:\n\n");
    printf("%s\n", psh_spaces_removed);

    return(0);
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
