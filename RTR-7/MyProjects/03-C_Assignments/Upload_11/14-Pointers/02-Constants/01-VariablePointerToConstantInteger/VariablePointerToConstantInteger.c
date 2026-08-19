#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_num = 131;
    const int *psh_ptr = NULL;

    // Code
    psh_ptr = &psh_num;
    printf("\n");
    printf("Current value of 'psh_num' = %d\n", psh_num);
    printf("Current 'psh_ptr' (Address of 'psh_num') = %p\n", psh_ptr);

    psh_num++;
    printf("\n\n");
    printf("After 'psh_num++', value of 'psh_num' = %d\n", psh_num);

    psh_ptr++;
    printf("\n\n");
    printf("After 'psh_ptr++', value of 'psh_ptr' = %p\n", psh_ptr);
    printf("Value of this new 'ptr' = %d\n", *psh_ptr);
    printf("\n\n");
    return(0);
}
