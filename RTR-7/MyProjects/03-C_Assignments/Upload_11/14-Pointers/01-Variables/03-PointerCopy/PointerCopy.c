#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_num;
    int *psh_ptr = NULL;
    int *psh_copy_ptr = NULL;

    // Code
    psh_num = 131;
    psh_ptr = &psh_num;

    printf("\n\n");
    printf("*********** Before psh_copy_ptr = ptr **************\n\n");
    printf("psh_num = %d\n", psh_num);
    printf("&psh_num = %p\n", &psh_num);
    printf("*(&psh_num) = %d\n", *(&psh_num));
    printf("psh_ptr = %p\n", psh_ptr);
    printf("*psh_ptr = %d\n", *psh_ptr);


    psh_copy_ptr = psh_ptr; //psh_copy_ptr = psh_ptr = &psh_num;

    printf("\n\n");
    printf("*********** After psh_copy_ptr = ptr **************\n\n");
    printf("psh_num = %d\n", psh_num);
    printf("&psh_num = %p\n", &psh_num);
    printf("*(&psh_num) = %d\n", *(&psh_num));
    printf("psh_ptr = %p\n", psh_ptr);
    printf("*psh_ptr = %d\n", *psh_ptr);
    printf("psh_copy_ptr = %p\n", psh_copy_ptr);
    printf("*psh_copy_ptr = %d\n", *psh_copy_ptr);
    return(0);
}
