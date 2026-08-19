// CharArrayAddresses.c

#include <stdio.h>

int main(void)
{
    // Variable declarations
    char psh_cArray[10];
    char *psh_ptr_cArray = NULL;
    int psh_i;

    // Code
    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        psh_cArray[psh_i] = (char)(psh_i + 65);
    }
    // *** NAME OF ANY ARRAY IS ITS BASE ADDRESS ***
    // *** HENCE, 'cArray' IS THE BASE ADDRESS OF ARRAY cArray[] OR
    // *** 'cArray' IS THE ADDRESS OF ELEMENT cArray[0] ***
    // *** ASSIGNING BASE ADDRESS OF ARRAY "cArray[]" TO CHAR POINTER
    // *** 'ptr_cArray'

    psh_ptr_cArray = psh_cArray; // ptr_cArray = &cArray[0];

    printf("\n\n");
    printf("Elements Of The Character Array : \n\n");

    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        printf("psh_cArray[%d] = %c\n", psh_i, *(psh_ptr_cArray + psh_i));
    }
    printf("\n\n");
    printf("Elements Of The Character Array : \n\n");

    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        printf("psh_cArray[%d] = %c \t \t Address = %p\n", psh_i, *(psh_ptr_cArray + psh_i), (psh_ptr_cArray + psh_i));
    }
    
    printf("\n\n");

    return (0);
}
