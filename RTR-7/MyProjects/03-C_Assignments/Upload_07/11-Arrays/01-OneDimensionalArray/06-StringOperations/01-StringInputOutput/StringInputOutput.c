#include <stdio.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Variable declarations
    char psh_chArray[PSH_MAX_STRING_LENGTH];   // A character array is a string

    // Code
    printf("\n\n");
    printf("Enter A String:\n\n");

    gets_s(psh_chArray, PSH_MAX_STRING_LENGTH);

    printf("\n\n");
    printf("String Entered By You Is:\n\n");
    printf("%s\n", psh_chArray);

    return 0;
}
