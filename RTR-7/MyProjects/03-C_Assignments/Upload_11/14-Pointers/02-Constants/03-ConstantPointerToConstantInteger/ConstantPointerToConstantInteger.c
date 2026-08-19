#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_num = 131;
    const int* const psh_ptr = &psh_num;

    // Code
    printf("\n");
    printf("Current value of 'psh_num' = %d\n", psh_num);
    printf("Current 'psh_ptr' (Address of 'psh_num') = %p\n", psh_ptr);

    psh_num++;
    printf("\n\n");
    printf("After 'psh_num++', value of 'psh_num' = %d\n", psh_num);

    return(0);
}
