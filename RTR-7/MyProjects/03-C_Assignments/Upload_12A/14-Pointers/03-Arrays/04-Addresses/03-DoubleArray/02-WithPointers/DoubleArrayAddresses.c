// DoubleArrayAddresses.c

#include <stdio.h>

int main(void)
{
    // Variable declarations
    double psh_dArray[10];
    double *psh_ptr_dArray = NULL;
    int psh_i;

    // Code
    for (psh_i = 0; psh_i < 10; psh_i++)
        psh_dArray[psh_i] = (float)(psh_i + 1) * 1.333333f;

    // *** NAME OF ANY ARRAY IS ITS BASE ADDRESS ***
    // *** HENCE, 'dArray' IS THE BASE ADDRESS OF ARRAY dArray[] OR
    // *** 'dArray' IS THE ADDRESS OF ELEMENT dArray[0] ***
    // *** ASSIGNING BASE ADDRESS OF ARRAY "dArray[]" TO DOUBLE POINTER
    // *** 'ptr_dArray'

    psh_ptr_dArray = psh_dArray; // ptr_dArray = &dArray[0];

    printf("\n\n");
    printf("Elements Of The 'double' Array : \n\n");

    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        printf("psh_dArray[%d] = %lf\n", psh_i, *(psh_ptr_dArray + psh_i));
    }
    printf("\n\n");
    printf("Elements Of The 'double' Array : \n\n");

    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        printf("psh_dArray[%d] = %lf \t \t Address = %p\n", psh_i, *(psh_ptr_dArray + psh_i), (psh_ptr_dArray + psh_i));
    }
    printf("\n\n");

    return (0);
}
