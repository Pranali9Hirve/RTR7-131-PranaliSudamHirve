#include <stdio.h>
#include <ctype.h>      // for toupper()

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Function Prototype
    int MyStrLen(char[]);

    // Variable declarations
    char psh_chArray[PSH_MAX_STRING_LENGTH];
    char psh_chArray_CapitalizedFirstLetterOfEveryWord[PSH_MAX_STRING_LENGTH]; // A character Array is a string

    int psh_iStringLength;
    int psh_i, psh_j;

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter A String : \n\n");
    gets_s(psh_chArray, PSH_MAX_STRING_LENGTH);

    psh_iStringLength = MyStrLen(psh_chArray);

    psh_j = 0;

    for (psh_i = 0; psh_i < psh_iStringLength; psh_i++)
    {
        if (psh_i == 0)
        {
            psh_chArray_CapitalizedFirstLetterOfEveryWord[psh_j] = toupper(psh_chArray[psh_i]);
        }
        else if (psh_chArray[psh_i] == ' ')
        {
            psh_chArray_CapitalizedFirstLetterOfEveryWord[psh_j] = psh_chArray[psh_i];
            psh_chArray_CapitalizedFirstLetterOfEveryWord[psh_j + 1] = toupper(psh_chArray[psh_i + 1]);

            // Two characters are copied, so increment psh_i and j
            psh_j++;
            psh_i++;
        }
        else
        {
            psh_chArray_CapitalizedFirstLetterOfEveryWord[psh_j] = psh_chArray[psh_i];
        }

        psh_j++;
    }

    psh_chArray_CapitalizedFirstLetterOfEveryWord[psh_j] = '\0';

    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("String Entered By You Is : \n\n");
    printf("%s\n", psh_chArray);

    printf("\n\n");
    printf("String After Capitalizing First Letter Of Every Word : \n\n");
    printf("%s\n", psh_chArray_CapitalizedFirstLetterOfEveryWord);

    return 0;
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
