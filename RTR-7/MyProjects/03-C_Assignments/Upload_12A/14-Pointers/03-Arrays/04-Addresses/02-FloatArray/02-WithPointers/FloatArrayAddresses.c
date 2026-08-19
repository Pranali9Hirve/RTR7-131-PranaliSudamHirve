// FloatArrayAddresses.c

#include <stdio.h>

int main(void)
{
    // Variable declarations
    float psh_fArray[10];
    float *psh_ptr_fArray = NULL;
    int psh_i;

    // Code
    for (psh_i = 0; psh_i < 10; psh_i++)
        psh_fArray[psh_i] = (float)(psh_i + 1) * 1.5f;

    // *** NAME OF ANY ARRAY IS ITS BASE ADDRESS ***
    // *** HENCE, 'fArray' IS THE BASE ADDRESS OF ARRAY fArray[] OR
    // *** 'fArray' IS THE ADDRESS OF ELEMENT fArray[0] ***
    // *** ASSIGNING BASE ADDRESS OF ARRAY "fArray[]" TO FLOAT POINTER
    // *** 'ptr_fArray'

    psh_ptr_fArray = psh_fArray; // ptr_fArray = &fArray[0];

    printf("\n\n");
    printf("Elements Of The 'float' Array : \n\n");

    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        printf("fArray[%d] = %f\n", psh_i, *(psh_ptr_fArray + psh_i));
    }
    printf("\n\n");
    printf("Elements Of The 'float' Array : \n\n");

    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        printf("psh_fArray[%d] = %f \t \t Address = %p\n", psh_i, *(psh_ptr_fArray + psh_i), (psh_ptr_fArray + psh_i));
    }
    printf("\n\n");

    return (0);
}
