// IntegerArrayAddresses.c

#include <stdio.h>

int main(void)
{
    // Variable declarations
    int psh_iArray[10];
    int *psh_ptr_iArray = NULL;
    int psh_i;

    // Code
    for (psh_i = 0; psh_i < 10; psh_i++)
        psh_iArray[psh_i] = (psh_i + 1) * 3;

    // *** NAME OF ANY ARRAY IS ITS BASE ADDRESS ***
    // *** HENCE, 'iArray' IS THE BASE ADDRESS OF ARRAY iArray[] OR
    // *** 'iArray' IS THE ADDRESS OF ELEMENT iArray[0] ***
    // *** ASSIGNING BASE ADDRESS OF ARRAY "iArray[]" TO INTEGER POINTER
    // *** 'ptr_iArray'

    psh_ptr_iArray = psh_iArray; // ptr_iArray = &iArray[0];

    printf("\n\n");
    printf("Elements Of The Integer Array : \n\n");

    for (psh_i = 0; psh_i < 10; psh_i++)
        printf("psh_iArray[%d] = %d\n", psh_i, *(psh_ptr_iArray + psh_i));

    printf("\n\n");
    printf("Elements Of The Integer Array : \n\n");

    for (psh_i = 0; psh_i < 10; psh_i++)
        printf("psh_iArray[%d] = %d \t \t Address = %p\n", psh_i, *(psh_ptr_iArray + psh_i), (psh_ptr_iArray + psh_i));

    printf("\n\n");

    return (0);
}
