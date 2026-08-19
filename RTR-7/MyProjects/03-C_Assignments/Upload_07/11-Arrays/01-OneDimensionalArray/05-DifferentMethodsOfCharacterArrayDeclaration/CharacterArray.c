#include <stdio.h>

int main(void)
{
    // Variable declarations
    char psh_chArray_01[] = { 'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P', '\0' }; // Must give '\0' explicitly for proper initialization
    char psh_chArray_02[9] = { 'W', 'E', 'L', 'C', 'O', 'M', 'E', 'S', '\0'}; // Must give '\0' explicitly for proper initialization
    char psh_chArray_03[] = { 'Y', 'O', 'U', '\0' }; // Must give '\0' explicitly for proper initialization
    char psh_chArray_04[] = "To";     // '\0' is assumed, size is given as 3 although string has only 2 characters
    char psh_chArray_05[] = "REAL TIME RENDERING BATCH OF 2020-21";     // '\0' is assumed, size is given as 40 although string has only 39 characters

    char chArray_WithoutNullTerminator[] = { 'H', 'e', 'l', 'l', 'o'};

    // Code
    printf("\n\n");

    printf("Size Of chArray_01 : %zu\n", sizeof(psh_chArray_01));
    printf("Size Of chArray_02 : %zu\n", sizeof(psh_chArray_02));
    printf("Size Of chArray_03 : %zu\n", sizeof(psh_chArray_03));
    printf("Size Of chArray_04 : %zu\n", sizeof(psh_chArray_04));
    printf("Size Of chArray_05 : %zu\n", sizeof(psh_chArray_05));

    printf("\n\n");
    printf("The Strings Are :\n\n");

    printf("psh_chArray_01 : %s\n", psh_chArray_01);
    printf("psh_chArray_02 : %s\n", psh_chArray_02);
    printf("psh_chArray_03 : %s\n", psh_chArray_03);
    printf("psh_chArray_04 : %s\n", psh_chArray_04);
    printf("psh_chArray_05 : %s\n", psh_chArray_05);

    printf("\n\n");

    printf("Size Of chArray_WithoutNullTerminator : %zu\n\n",
           sizeof(chArray_WithoutNullTerminator));

    printf("chArray_WithoutNullTerminator : %s\n",
           chArray_WithoutNullTerminator); // Will display garbage characters after "Hello" because there is no '\0' (null terminator).

    return 0;
}
