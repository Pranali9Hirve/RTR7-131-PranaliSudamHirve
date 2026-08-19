#include<stdio.h>

int main(void)
{
    // Variable Declaration
    char psh_ch;
    // Declaration Method 1: '*psh_ptr' is a variable of type 'Char'
    char *psh_ptr = NULL; 

    // Code
    psh_ch = 'P';

    printf("\n\n");

    printf("*********** Before Pointer **************\n\n");
    printf("Value of 'psh_ch' = %c\n\n", psh_ch);
    printf("Address of 'psh_ch' = %p\n\n", &psh_ch);
    printf("Value at Address of 'psh_ch' = %c\n\n", *(&psh_ch));

    // Assigning address of variable 'psh_ch' to pointer variable 'ptr'
    // 'ptr' now contains address of 'psh_ch', hence 'ptr' is SAME as '&num'

    psh_ptr = &psh_ch;

    printf("\n\n");

    printf("*********** After psh_ptr = &psh_ch **************\n\n");
    printf("Value of 'psh_ch' = %c\n\n", psh_ch);
    printf("Address of 'psh_ch' = %p\n\n", psh_ptr);
    printf("Value at Address of 'psh_ch' = %c\n\n", *psh_ptr);

    return(0);
}
