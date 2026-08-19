#include<stdio.h>
#include<string.h>

#define PSH_MAX_STRING_LENGTH 512

int main(void)
{
    // Variable declarations
    char psh_chArray_One[PSH_MAX_STRING_LENGTH], psh_chArray_Two[PSH_MAX_STRING_LENGTH]; // A character array is a String

    // Code

    // *** STRING INPUT ***
    printf("\n\n");
    printf("Enter First String:\n\n");
    gets_s(psh_chArray_One, PSH_MAX_STRING_LENGTH);

    printf("\n\n");
    printf("Enter Second String:\n\n");
    gets_s(psh_chArray_Two, PSH_MAX_STRING_LENGTH);

    // *** STRING CONCAT ***
    printf("\n\n");
    printf("****** Before Concatenation ****** \n\n");

    printf("The Original First String Entered By You (i.e. psh_chArray_One[]) Is:\n\n");
    printf("%s\n", psh_chArray_One);

    printf("\n\n");

    printf("The Original Second String Entered By You (i.e. psh_chArray_Two[]) Is:\n\n");
    printf("%s\n", psh_chArray_Two);

    strcat(psh_chArray_One, psh_chArray_Two);

    printf("\n\n");
    printf("****** After Concatenation ****** \n\n");

    printf("'psh_chArray_One' is: \n\n");
    printf("%s\n", psh_chArray_One);

    printf("'psh_chArray_Two' is: \n\n");
    printf("%s\n", psh_chArray_Two);

    return(0);
}
