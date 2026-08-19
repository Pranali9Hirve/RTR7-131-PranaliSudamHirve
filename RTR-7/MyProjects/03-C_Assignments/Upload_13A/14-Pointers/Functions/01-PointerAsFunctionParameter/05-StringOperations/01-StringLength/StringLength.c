#include<stdio.h>
#include<stdlib.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Function prototype
    int PshMyStrlen(char*);

    // Variable declarations
    char* psh_chArray = NULL;
    int psh_iStringLength = 0;

    // Code
    // *** STRING INPUT ***
    printf("\n\n");
    psh_chArray = (char*)malloc(PSH_MAX_STRING_LENGTH * sizeof(char));
    if (psh_chArray == NULL)
    {
        printf("Memory allocation to character array failed !! Exiting Now....\n\n ");
        exit(0);
    }

    printf("Enter A String: \n\n");
    gets_s(psh_chArray, PSH_MAX_STRING_LENGTH);

    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("String Entered By You Is:\n\n");
    printf("%s", psh_chArray);

    // *** STRING LENGTH ***
    printf("\n");
    psh_iStringLength = PshMyStrlen(psh_chArray);

    printf("Length Of String Is = %d Characters !!!\n", psh_iStringLength);

    if (psh_chArray)
    {
        free(psh_chArray);
        psh_chArray = NULL;
    }
    return(0);
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
