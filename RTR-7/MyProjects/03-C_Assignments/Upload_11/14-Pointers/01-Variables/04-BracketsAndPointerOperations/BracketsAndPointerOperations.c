#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_num;
    int *psh_ptr = NULL;
    int psh_ans;

    // Code
    psh_num = 5;
    psh_ptr = &psh_num;

    printf("\n\n");
    printf("psh_num = %d\n", psh_num);
    printf("&psh_num = %p\n", &psh_num);
    printf("*(&psh_num) = %d\n", *(&psh_num));
    printf("psh_ptr = %p\n", psh_ptr);
    printf("*psh_ptr = %d\n", *psh_ptr);
    printf("\n\n");

    printf("Answer of (psh_ptr + 10)  = %p\n\n", (psh_ptr + 10));
    printf("Answer of *(psh_ptr + 10)  = %d\n\n", *(psh_ptr + 10));
    printf("Answer of (*psh_ptr + 10)  = %d\n\n", (*psh_ptr + 10));
    ++*psh_ptr;
    printf("Answer of ++*psh_ptr  = %p\n\n", psh_ptr);

    *psh_ptr++;
    printf("Answer of *psh_ptr++  = %p\n\n", psh_ptr);

    psh_ptr = &psh_num;
    (*psh_ptr)++;
    printf("Answer of (*psh_ptr)++  = %p\n\n", psh_ptr);

    return(0);
}
