#include<stdio.h>
#include<string.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Function Prototypes
    int MyStrLen(char[]);

    // Variable declarations
    char psh_chArray[PSH_MAX_STRING_LENGTH]; // A character array is a String
    int psh_iStringLength;
    int psh_i;
    int psh_word_count = 0, psh_space_count=0;

    // Code
    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter A String:\n\n");
    gets_s(psh_chArray, PSH_MAX_STRING_LENGTH);

    psh_iStringLength = MyStrLen(psh_chArray);

    for (psh_i=0; psh_i < psh_iStringLength; psh_i++)
    {
        switch (psh_chArray[psh_i])
        {
        case 32: //'32' is ASCII value for space (' ')character
            psh_space_count++;
            break;
        
        default:
            break;
        }
    }

    psh_word_count = psh_space_count + 1;

    printf("\n\n");
    printf("String Entered By You (i.e. psh_chArray[]) Is:\n\n");
    printf("%s\n", psh_chArray);

    printf("Number of spaces in the Input String Is:\n\n");
    printf("%d\n", psh_space_count);

    printf("Number of words in the Input String Is:\n\n");
    printf("%d\n", psh_word_count);

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
