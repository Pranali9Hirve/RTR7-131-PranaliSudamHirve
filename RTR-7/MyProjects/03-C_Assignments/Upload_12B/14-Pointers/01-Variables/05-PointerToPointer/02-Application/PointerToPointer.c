#include<stdio.h>

int main(void)
{
    // Variable Declaration
    int psh_num;
    int *psh_ptr = NULL;

    // Declaration Method 1: **pptr is a variable of type 'int'
    int **psh_pptr = NULL;

    // Code
    psh_num = 131;

    printf("\n\n");

    printf(" ***** BEFORE ptr = &num ***** \n\n");
    printf("Value of 'psh_num' = %d\n", psh_num);
    printf("Address of 'psh_num' = %p\n", &psh_num);
    printf("Value at Address of 'psh_num' = %d\n", *(&psh_num));
   
    // Assigning address of variable 'psh_num' to pointer variable 'psh_ptr' to pointer-to-pointer variable 'psh_pptr'
    // 'psh_pptr' now contains the address of 'psh_ptr' which contains the address of 'psh_num'
    // Hence, 'psh_pptr' is Same as '&psh_ptr'
    // 'psh_ptr' is same as '&psh_num'
    // Hence, psh_pptr = &psh_ptr = &(&psh_num)
    // If psh_ptr = &psh_num and *psh_ptr = *(&psh_num) = Value at address of 'psh_ptr'
    // then , psh_pptr = &psh_ptr and *psh_pptr = *(&psh_ptr) = psh_ptr = Value at address of 'psh_ptr'
    // i.e: 'psh_ptr' i.e: address of 'psh_num'
    // Then, **psh_pptr = **(&psh_ptr) = *(*(&psh_ptr)) = *psh_ptr = *(&psh_num) =  psh_num = 10
    // Hence, psh_num = *(&psh_num) = *psh_ptr = *(*psh_pptr) = **psh_pptr

    psh_pptr = &psh_ptr;
    printf("\n\n");

    printf(" ***** After psh_pptr = &psh_ptr ***** \n\n");
    printf("Value of 'psh_num' = %d\n", psh_num);
    printf("Address of 'psh_num' (ptr)= %p\n", psh_ptr);
    printf("Address of 'psh_ptr' (pptr)= %p\n", psh_pptr);
    printf("Value at Address of 'psh_ptr' (*psh_pptr) = %p\n", *psh_pptr);
    printf("Value at Address of 'psh_num' (*psh_ptr) (*psh_pptr) = %d\n", **psh_pptr);
    return(0);
}
