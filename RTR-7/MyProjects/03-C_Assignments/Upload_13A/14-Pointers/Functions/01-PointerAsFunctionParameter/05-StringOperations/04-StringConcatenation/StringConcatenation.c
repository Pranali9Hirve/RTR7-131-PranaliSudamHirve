#include<stdio.h>
#include<stdlib.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Function Prototype
    void PshMyStrCat(char *, char *);
    int PshMyStrlen(char *);


    // Variable declarations
    char *psh_chArray_One = NULL, *psh_chArray_Two = NULL; // A character array is a String

    // Code

    // *** STRING INPUT ***
    printf("\n\n");

    psh_chArray_One = (char*)malloc(PSH_MAX_STRING_LENGTH * sizeof(char));
    if (psh_chArray_One == NULL)
    {
        printf("Memory allocation to character array failed !! Exiting Now....\n\n ");
        exit(0);
    }

    printf("Enter First String:\n\n");
    gets_s(psh_chArray_One, PSH_MAX_STRING_LENGTH);


    psh_chArray_Two = (char*)malloc(PSH_MAX_STRING_LENGTH * sizeof(char));
    if (psh_chArray_Two == NULL)
    {
        printf("Memory allocation to character array failed !! Exiting Now....\n\n ");
        exit(0);
    }

    printf("\n\n");
    printf("Enter Second String:\n\n");
    gets_s(psh_chArray_Two, PSH_MAX_STRING_LENGTH);

    // *** STRING CONCAT ***
    printf("\n\n");
    printf("****** Before Concatenation ****** \n\n");

    printf("The One First String Entered By You (i.e. psh_chArray_One *) Is:\n\n");
    printf("%s\n", psh_chArray_One);

    printf("\n\n");

    printf("The One Second String Entered By You (i.e. psh_chArray_Two *) Is:\n\n");
    printf("%s\n", psh_chArray_Two);

    PshMyStrCat(psh_chArray_One, psh_chArray_Two);

    printf("\n\n");
    printf("****** After Concatenation ****** \n\n");

    printf("'psh_chArray_One' is: \n\n");
    printf("%s\n", psh_chArray_One);

    printf("'psh_chArray_Two' is: \n\n");
    printf("%s\n", psh_chArray_Two);

    if (psh_chArray_Two)
    {
        free(psh_chArray_Two);
        psh_chArray_Two = NULL;
        printf("Memmory allocation for Second string has been successfully freed !! \n\n");
    }

    if (psh_chArray_One)
    {
        free(psh_chArray_One);
        psh_chArray_One = NULL;
        printf("Memmory allocation for first string has been successfully freed !! \n\n");
    }

    return(0);
}

void PshMyStrCat(char *psh_str_destination, char *psh_str_source)
{
    // Function Prototype
    int MyStrLength(char *);

    // Variable Declarations
    int psh_iStringLength_Source = 0, psh_iStringLength_Destination = 0;
    int psh_i, psh_j;

    // Code
    psh_iStringLength_Source = MyStrLength(psh_str_source);
    psh_iStringLength_Destination = MyStrLength(psh_str_destination);

    // ARRAY INDICES BEGIN FROM 0, HENCE LAST VALID INDEX OF ARRAY WILL BE (LENGTH -1)
    // SO, CONCATENATION MUST BEGIN FROM INDEX NUMBER EQUAL TO LENGTH OF THE ARRAY 'psh_str_destination'
    // WE NEED TO PUT THE CHARACTER WHICH IS AT FIRST INDEX OF 'psh_str_source' TO THE (LAST INDEX + 1) OF 'psh_str_destination'

    for(psh_i = psh_iStringLength_Destination, psh_j = 0; psh_j < psh_iStringLength_Source; psh_i++, psh_j++)
    {
        *(psh_str_destination + psh_i) = *(psh_str_source + psh_j); 
    }

    *(psh_str_destination + psh_i) = '\0';
}

int MyStrLength(char *psh_str)
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
