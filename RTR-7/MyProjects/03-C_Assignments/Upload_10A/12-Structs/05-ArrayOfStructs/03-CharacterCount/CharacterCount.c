#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define PSH_MAX_STRING_LENGTH 1024

struct PshCharacterCount
{
    char pshCh;
    int pshChCount;
} pshCharacterAndCount[] = { 
                                { 'A', 0 },
                                { 'B', 0 },
                                { 'C', 0 },
                                { 'D', 0 },
                                { 'E', 0 },
                                { 'F', 0 },
                                { 'G', 0 },
                                { 'H', 0 },
                                { 'I', 0 },
                                { 'J', 0 },
                                { 'K', 0 },
                                { 'L', 0 },
                                { 'M', 0 },
                                { 'N', 0 },
                                { 'O', 0 },
                                { 'P', 0 },
                                { 'Q', 0 },
                                { 'R', 0 },
                                { 'S', 0 },
                                { 'T', 0 },
                                { 'U', 0 },
                                { 'V', 0 },
                                { 'W', 0 },
                                { 'X', 0 },
                                { 'Y', 0 },
                                { 'Z', 0 }
                            };

#define PSH_SIZE_OF_ENTIRE_ARRAY_OF_STRUCTS sizeof(pshCharacterAndCount)
#define PSH_SIZE_OF_ONE_STRUCT_FROM_ARRAY_OF_STRUCTS sizeof(pshCharacterAndCount[0])
#define PSH_NUM_ELEMENT_IN_ARRAY (PSH_SIZE_OF_ENTIRE_ARRAY_OF_STRUCTS/PSH_SIZE_OF_ONE_STRUCT_FROM_ARRAY_OF_STRUCTS)

// ENTRY POINT FUNCTION
int main(void)
{
    // Variable declaration
    char pshStr[PSH_MAX_STRING_LENGTH];
    int psh_i, psh_j, psh_actual_string_length = 0;

    // Code
    printf("\n\n");
    printf("Enter string: \n");
    gets_s(pshStr, PSH_MAX_STRING_LENGTH);

    psh_actual_string_length = strlen(pshStr);

    printf("\n");
    printf("The string you have entered is: \n");
    printf("%s\n", pshStr);

    for (psh_i = 0; psh_i < psh_actual_string_length; psh_i++)
    {
        for (psh_j = 0; psh_j < PSH_NUM_ELEMENT_IN_ARRAY; psh_j++)
        {
            pshStr[psh_i] = toupper(pshStr[psh_i]);
            
            if (pshStr[psh_i] == pshCharacterAndCount[psh_j].pshCh)
            {
                pshCharacterAndCount[psh_j].pshChCount++;
            }
        }
    }

    printf("\n");
    printf("The number of occurances of all characters from the alphabet are as follows:\n");
    for (psh_i = 0; psh_i < PSH_NUM_ELEMENT_IN_ARRAY; psh_i++)
    {
        printf("Character   %c  =   %d\n", pshCharacterAndCount[psh_i].pshCh, pshCharacterAndCount[psh_i].pshChCount);
    }
    printf("\n");

    return(0);
}
