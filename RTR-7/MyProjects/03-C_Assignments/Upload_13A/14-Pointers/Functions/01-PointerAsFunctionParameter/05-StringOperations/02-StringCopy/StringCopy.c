#include<stdio.h>
#include<stdlib.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Function Prototypes
    void PshMyStrcpy(char *, char *);
    int PshMyStrlen(char *);

    // Variable declarations
    char *psh_chArray_Original = NULL, *psh_chArray_Copy = NULL;
    int psh_iStringLength = 0;

    // *** STRING INPUT ***
    printf("\n\n");
    psh_chArray_Original = (char*)malloc(PSH_MAX_STRING_LENGTH * sizeof(char));
    if (psh_chArray_Original == NULL)
    {
        printf("Memory allocation to character array failed !! Exiting Now....\n\n ");
        exit(0);
    }

    printf("Enter A String:\n\n");
    gets_s(psh_chArray_Original, PSH_MAX_STRING_LENGTH);

    psh_iStringLength = PshMyStrlen(psh_chArray_Original);

    psh_chArray_Copy = (char*)malloc(PSH_MAX_STRING_LENGTH * sizeof(char));
    if (psh_chArray_Copy == NULL)
    {
        printf("Memory allocation to character array failed !! Exiting Now....\n\n ");
        exit(0);
    }

    // *** STRING COPY ***
    PshMyStrcpy(psh_chArray_Copy, psh_chArray_Original);

    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("The Original String Entered By You Is:\n\n");
    printf("%s\n", psh_chArray_Original);

    printf("\n\n");
    printf("The Copied String Is:\n\n");
    printf("%s\n", psh_chArray_Copy);

    if (psh_chArray_Copy)
    {
        free(psh_chArray_Copy);
        psh_chArray_Copy = NULL;
        printf("Memmory allocation for copied string has been successfully freed !! \n\n");
    }

    if (psh_chArray_Original)
    {
        free(psh_chArray_Original);
        psh_chArray_Original = NULL;
        printf("Memmory allocation for original string has been successfully freed !! \n\n");
    }

    return 0;
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
