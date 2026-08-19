#include<stdio.h>

int main(void)
{
    // Variable Declaration
    int psh_num;
    // Declaration Method 2: 'psh_ptr' is a variable of type 'int*'
    int* psh_ptr = NULL; 

    // Code
    psh_num = 10;

    printf("\n\n");

    printf("*********** Before Pointer **************\n\n");
    printf("Value of 'psh_num' = %d\n\n", psh_num);
    printf("Address of 'psh_num' = %p\n\n", &psh_num);
    printf("Value at Address of 'psh_num' = %d\n\n", *(&psh_num));

    // Assigning address of variable 'psh_num' to pointer variable 'ptr'
    // 'ptr' now contains address of 'psh_num', hence 'ptr' is SAME as '&num'

    psh_ptr = &psh_num;

    printf("\n\n");

    printf("*********** After psh_ptr = &psh_num **************\n\n");
    printf("Value of 'psh_num' = %d\n\n", psh_num);
    printf("Address of 'psh_num' = %p\n\n", psh_ptr);
    printf("Value at Address of 'psh_num' = %d\n\n", *psh_ptr);

    return(0);
}
