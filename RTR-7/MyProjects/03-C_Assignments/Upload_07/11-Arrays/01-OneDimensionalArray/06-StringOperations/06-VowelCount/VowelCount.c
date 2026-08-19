#include <stdio.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Function Prototypes
    int MyStringLen(char[]);

    // Variable Declarations
    char psh_chArray[PSH_MAX_STRING_LENGTH]; // A Character Array Is A String
    int psh_iStringLength;
    int psh_Count_A = 0, psh_Count_E = 0, psh_Count_I = 0, psh_Count_O = 0, psh_Count_U = 0; // Initial Count = 0
    int psh_i;

    // Code

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter A String:\n\n");
    gets_s(psh_chArray, PSH_MAX_STRING_LENGTH);

    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("String Entered By You (i.e. psh_chArray[]) Is:\n\n");
    printf("%s\n", psh_chArray);

    psh_iStringLength = MyStringLen(psh_chArray);

    for (psh_i = 0; psh_i < psh_iStringLength; psh_i++)
    {
        switch (psh_chArray[psh_i])
        {
        case 'A':
        case 'a':
            psh_Count_A++;
            break;
        case 'E':
        case 'e':
            psh_Count_E++;
            break;
        case 'I':
        case 'i':
            psh_Count_I++;
            break;
        case 'O':
        case 'o':
            psh_Count_O++;
            break;
        case 'U':
        case 'u':
            psh_Count_U++;
            break;
        
        default:
            break;
        }
    }

    printf("\n\n");
    printf("In the string entered by you, The Vowels and the number of their occurances are as follows: \n\n");
    printf("'A' Has Occured = %d Times !!! \n\n", psh_Count_A);
    printf("'E' Has Occured = %d Times !!! \n\n", psh_Count_E);
    printf("'I' Has Occured = %d Times !!! \n\n", psh_Count_I);
    printf("'O' Has Occured = %d Times !!! \n\n", psh_Count_O);
    printf("'U' Has Occured = %d Times !!! \n\n", psh_Count_U);

    return(0);
}

int MyStringLen(char psh_str[])
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
