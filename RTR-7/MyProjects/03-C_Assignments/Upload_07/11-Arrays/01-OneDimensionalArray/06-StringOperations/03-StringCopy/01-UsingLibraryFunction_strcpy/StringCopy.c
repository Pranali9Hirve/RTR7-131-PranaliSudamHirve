#include <stdio.h>
#include <string.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Variable declarations
    char psh_chArray_Original[PSH_MAX_STRING_LENGTH], psh_chArray_Copy[PSH_MAX_STRING_LENGTH]; // A character array is a string

    // Code
    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter A String:\n\n");
    gets_s(psh_chArray_Original, PSH_MAX_STRING_LENGTH);

    // *** STRING COPY ***
    strcpy(psh_chArray_Copy, psh_chArray_Original);

    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("The Original String Entered By You (i.e. psh_chArray_Original[]) Is:\n\n");
    printf("%s\n", psh_chArray_Original);

    printf("\n\n");
    printf("The Copied String (i.e. chArray_Copy[]) Is:\n\n");
    printf("%s\n", psh_chArray_Copy);

    return 0;
}
