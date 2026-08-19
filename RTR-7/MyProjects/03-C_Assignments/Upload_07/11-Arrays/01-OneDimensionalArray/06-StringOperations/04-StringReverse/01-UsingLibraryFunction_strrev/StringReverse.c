#include <stdio.h>
#include <string.h>   // for strrev()

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Variable declarations
    char psh_chArray_Original[PSH_MAX_STRING_LENGTH]; // A character array is a String

    // Code
    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter A String:\n\n");
    gets_s(psh_chArray_Original, PSH_MAX_STRING_LENGTH);

    // *** STRING OUTPUT ***
    printf("\n\n");
    printf("The Original String Entered By You (i.e. psh_chArray_Original[]) Is:\n\n");
    printf("%s\n", psh_chArray_Original);

    printf("\n\n");
    printf("The Reversed String (i.e. psh_chArray_Reverse[]) Is:\n\n");
    printf("%s\n", strrev(psh_chArray_Original));

    return 0;
}
