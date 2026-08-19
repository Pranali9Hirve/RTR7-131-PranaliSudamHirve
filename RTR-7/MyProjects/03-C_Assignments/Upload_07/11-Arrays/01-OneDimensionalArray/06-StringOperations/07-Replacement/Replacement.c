// *** THIS PROGRAM REPLACES ALL VOWELS IN THE INPUT STRING WITH '*' (ASTERISK) SYMBOL***
// FOR EXAMPLE, ORIGINAL STRING 'PRANALI' WILL BECOME 'PR*N*L*'

#include<stdio.h>
#include<string.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Function Prototypes
    int MyStrLen(char[]);
    void MyStrCpy(char[], char[]);

    // Variable declarations
    char psh_chArray_Original[PSH_MAX_STRING_LENGTH], psh_VowelReplaced[PSH_MAX_STRING_LENGTH]; // A character array is a String
    int psh_iStringLength;
    int psh_i;

    // Code
    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter A String:\n\n");
    gets_s(psh_chArray_Original, PSH_MAX_STRING_LENGTH);

    // *** STRING OUTPUT ***

    MyStrCpy(psh_VowelReplaced , psh_chArray_Original);

    psh_iStringLength = MyStrLen(psh_VowelReplaced);

    for (psh_i = 0; psh_i < psh_iStringLength; psh_i++)
    {
        switch (psh_VowelReplaced[psh_i])
        {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            psh_VowelReplaced[psh_i] = '*';
            break;
        
        default:
            break;
        }
    }

    printf("\n\n");
    printf("String Entered By You (i.e. psh_chArray_Original[]) Is:\n\n");
    printf("%s\n", psh_chArray_Original);

    printf("String After Vowel Replaced by * (i.e. psh_VowelReplaced[]) Is:\n\n");
    printf("%s\n", psh_VowelReplaced);

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

void MyStrCpy(char psh_str_destination[], char psh_str_source[])
{
    // Function Prototypes
    int MyStrLen(char[]);

    // Variable Declarations
    int psh_iStringLength = 0;
    int psh_j;

    // Code
    psh_iStringLength = MyStrLen(psh_str_source);

    for (psh_j = 0; psh_j < psh_iStringLength; psh_j++)
    {
        psh_str_destination[psh_j] = psh_str_source[psh_j];
    }

    // Copy the null character
    psh_str_destination[psh_j] = '\0';
}
