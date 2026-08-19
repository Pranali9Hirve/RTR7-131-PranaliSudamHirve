#include<stdio.h>
#include<stdlib.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Function Prototypes
    char* PshReplaceVowelsWithHashSymbol(char *);

    // Variable declarations
    char psh_string[PSH_MAX_STRING_LENGTH];
    char *psh_replaced_string = NULL;

    // Code
    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter A String:\n\n");
    gets_s(psh_string, PSH_MAX_STRING_LENGTH);

    psh_replaced_string = PshReplaceVowelsWithHashSymbol(psh_string);
    if (psh_replaced_string == NULL)
    {
        printf("PshReplaceVowelsWithHashSymbol() function has failed !! Exiting Now....\n\n ");
        exit(0);
    }

    printf("\n\n");
    printf("String Entered By You (i.e. psh_string) Is:\n\n");
    printf("%s\n", psh_string);

    printf("String After Vowel Replaced Is:\n\n");
    printf("%s\n", psh_replaced_string);

    if (psh_replaced_string)
    {
        free(psh_replaced_string);
        psh_replaced_string = NULL;
        printf("Memory is freed for psh_replaced_string\n");
    }

    return(0);
}

char* PshReplaceVowelsWithHashSymbol(char *psh_arr)
{
    // fuction Prototype
    void PshMyStrcpy(char *, char *);
    int PshMyStrlen(char *);

    // Variable Declaration
    char *psh_new_string = NULL;
    int psh_i;

    // Code

    psh_new_string = (char *)malloc(PshMyStrlen(psh_arr) * sizeof(char));
    if (psh_new_string == NULL)
    {
        printf("Could not allocate memory\n");
        return(NULL);
    }

    PshMyStrcpy(psh_new_string, psh_arr);

    for (psh_i = 0; psh_i < PshMyStrlen(psh_arr); psh_i++)
    {
        switch (psh_new_string[psh_i])
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
                psh_new_string[psh_i] = '#';
                break;
        
            default:
                break;
        }
    }
    return(psh_new_string);
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


void PshMyStrcpy(char* psh_str_destination, char* psh_str_source)
{
    // Function Prototypes
    int PshMyStrlen(char *);

    // Variable Declarations
    int psh_iStringLength = 0;
    int psh_j;

    // Code
    psh_iStringLength = PshMyStrlen(psh_str_source);

    for (psh_j = 0; psh_j < psh_iStringLength; psh_j++)
    {
        *(psh_str_destination + psh_j) = *(psh_str_source + psh_j);
    }

    // Copy the null character
    *(psh_str_destination + psh_j) = '\0';
}

int PshMyStrlen(char* psh_str)
{
    // Variable declarations
    int psh_i;
    int psh_string_length = 0;

    // Code
    // Determining exact length of the string by detecting the first occurance of NULL-TERMINATING CHARACTER (\0)
    for (psh_i = 0; psh_i < PSH_MAX_STRING_LENGTH; psh_i++)
    {
        if (*(psh_str + psh_i) == '\0')
            break;
        else
            psh_string_length++;
    }

    return psh_string_length;
}
