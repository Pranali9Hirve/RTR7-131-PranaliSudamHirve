#include <stdio.h>

#define PSH_MAX_STRING_LENGTH 512
#define PSH_SPACE ' '
#define PSH_FULLSTOP '.'
#define PSH_COMMA ','
#define PSH_EXCLAMATION '!'
#define PSH_QUESTION_MARK '?'

int main(void)
{
    // Function Prototype
    int MyStrLen(char[]);
    char MyToUpper(char);

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
        if (psh_i == 0) // First Letter of any sentence must be a Capital Letter
        {
            psh_chArray_CapitalizedFirstLetterOfEveryWord[psh_j] = MyToUpper(psh_chArray[psh_i]);
        }
        else if (psh_chArray[psh_i] == PSH_SPACE) // First Letter of Every Word in the sentense must be a Capital Letter. Words are separated by spaces
        {
            psh_chArray_CapitalizedFirstLetterOfEveryWord[psh_j] = psh_chArray[psh_i];
            psh_chArray_CapitalizedFirstLetterOfEveryWord[psh_j + 1] = MyToUpper(psh_chArray[psh_i + 1]);

            // Since alresdy two characters (At indices 'i' and 'i+1') have been considered in this else-if block... We are extra incrementing 'i' and 'j' by 1
            
            psh_j++;
            psh_i++;
        }
        else if ((psh_chArray[psh_i] == PSH_FULLSTOP || psh_chArray[psh_i] == PSH_COMMA || psh_chArray[psh_i] == PSH_EXCLAMATION ||
        psh_chArray[psh_i] == PSH_QUESTION_MARK) && (psh_chArray[psh_i] != PSH_SPACE))
        {
            psh_chArray_CapitalizedFirstLetterOfEveryWord[psh_j] = psh_chArray[psh_i];
            psh_chArray_CapitalizedFirstLetterOfEveryWord[psh_j + 1] = PSH_SPACE;
            psh_chArray_CapitalizedFirstLetterOfEveryWord[psh_j + 2] = MyToUpper(psh_chArray[psh_i+1]);
            psh_j = psh_j + 2;
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

char MyToUpper(char ch)
{
    // Variable declaration
    int psh_num;
    int psh_c;

    // Code
    psh_num = 'a' - 'A';

    if ((int)ch >= 97 && (int)ch <= 122)
    {
        psh_c = (int)ch - psh_num;
        return((char)psh_c);
    }
    else
    {
        return(ch);
    }
}
