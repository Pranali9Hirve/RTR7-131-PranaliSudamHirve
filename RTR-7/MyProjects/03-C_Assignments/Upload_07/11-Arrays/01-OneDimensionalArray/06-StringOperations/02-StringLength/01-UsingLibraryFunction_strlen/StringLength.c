#include <stdio.h>
#include <string.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Variable declarations
    char psh_chArray[PSH_MAX_STRING_LENGTH];   // A character array is a string
    int psh_iStringLength = 0;

    // Code
    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter A String: \n\n");
    gets_s(psh_chArray, PSH_MAX_STRING_LENGTH);

    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("String Entered By You Is:\n\n");
    printf("%s", psh_chArray);

    // *** STRING LENGTH ***
    printf("\n");
    psh_iStringLength = strlen(psh_chArray);

    printf("Length Of String Is = %d Characters !!!\n", psh_iStringLength);

    return 0;
}
