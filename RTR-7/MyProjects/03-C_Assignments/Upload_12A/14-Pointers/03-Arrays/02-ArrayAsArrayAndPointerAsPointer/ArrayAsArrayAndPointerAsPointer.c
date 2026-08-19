#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_iArray[] = {12, 24, 36, 48, 60, 72, 84, 96, 108, 120}; // Integer Array
    int *psh_ptr_iArray = NULL; // Integer Pointer

    // Code
    // *** USING ARRAY NAME AS A ARRAY i.e. Value of the Element of Array: iArray[x] and Address of xth Element of iArray: &iArray[x] ***

    printf("\n\n");
    printf("*** USING ARRAY NAME AS A ARRAY i.e. Value of the Element of Array: iArray[x] and Address of xth Element of iArray: &iArray[x] ***");
    printf("Integer Array Elements And Their Addressed: \n\n");
     printf("psh_iArray[0] = %d \t At Address: %p\n", psh_iArray[0], &psh_iArray[0]);
    printf("psh_iArray[1] = %d \t At Address: %p\n", psh_iArray[1], &psh_iArray[1]);
    printf("psh_iArray[2] = %d \t At Address: %p\n", psh_iArray[2], &psh_iArray[2]);
    printf("psh_iArray[3] = %d \t At Address: %p\n", psh_iArray[3], &psh_iArray[3]);
    printf("psh_iArray[4] = %d \t At Address: %p\n", psh_iArray[4], &psh_iArray[4]);
    printf("psh_iArray[5] = %d \t At Address: %p\n", psh_iArray[5], &psh_iArray[5]);
    printf("psh_iArray[6] = %d \t At Address: %p\n", psh_iArray[6], &psh_iArray[6]);
    printf("psh_iArray[7] = %d \t At Address: %p\n", psh_iArray[7], &psh_iArray[7]);
    printf("psh_iArray[8] = %d \t At Address: %p\n", psh_iArray[8], &psh_iArray[8]);
    printf("psh_iArray[9] = %d \t At Address: %p\n", psh_iArray[9], &psh_iArray[9]);

    // ASSIGNING BASE ADDRESS OF INTEGER ARRAY 'psh_iArray' TO INTEGER POINTER 'psh_ptr_iArray'
    // NAME OF ANY ARRAY IS ITS OWN BASE ADDRESS
    
    psh_ptr_iArray = psh_iArray; // SAME AS psh_ptr_iArray = &psh_iArray[0];

    // USING POINTER AS POINTER i.e. Value of xth Element of psh_iArray: *(psh_ptr_iArray + x)
    // And Address of xth Element of psh_iArray: (psh_ptr_iArray + x)

    printf("\n\n");
    printf("*** USING POINTER AS POINTER i.e. Value of xth Element of psh_iArray: *(psh_ptr_iArray + x) And Address of xth Element of psh_iArray: (psh_ptr_iArray + x) ***");
    printf("Integer Array Elements And Their Addresses: \n\n");
    printf("*(psh_ptr_iArray + 0) = %d \t\t At Address (psh_ptr_iArray + 0): %p\n", *(psh_ptr_iArray + 0), (psh_ptr_iArray + 0));
    printf("*(psh_ptr_iArray + 1) = %d \t\t At Address (psh_ptr_iArray + 1): %p\n", *(psh_ptr_iArray + 1), (psh_ptr_iArray + 1));
    printf("*(psh_ptr_iArray + 2) = %d \t\t At Address (psh_ptr_iArray + 2): %p\n", *(psh_ptr_iArray + 2), (psh_ptr_iArray + 2));
    printf("*(psh_ptr_iArray + 3) = %d \t\t At Address (psh_ptr_iArray + 3): %p\n", *(psh_ptr_iArray + 3), (psh_ptr_iArray + 3));
    printf("*(psh_ptr_iArray + 4) = %d \t\t At Address (psh_ptr_iArray + 4): %p\n", *(psh_ptr_iArray + 4), (psh_ptr_iArray + 4));
    printf("*(psh_ptr_iArray + 5) = %d \t\t At Address (psh_ptr_iArray + 5): %p\n", *(psh_ptr_iArray + 5), (psh_ptr_iArray + 5));
    printf("*(psh_ptr_iArray + 6) = %d \t\t At Address (psh_ptr_iArray + 6): %p\n", *(psh_ptr_iArray + 6), (psh_ptr_iArray + 6));
    printf("*(psh_ptr_iArray + 7) = %d \t\t At Address (psh_ptr_iArray + 7): %p\n", *(psh_ptr_iArray + 7), (psh_ptr_iArray + 7));
    printf("*(psh_ptr_iArray + 8) = %d \t\t At Address (psh_ptr_iArray + 8): %p\n", *(psh_ptr_iArray + 8), (psh_ptr_iArray + 8));
    printf("*(psh_ptr_iArray + 9) = %d \t\t At Address (psh_ptr_iArray + 9): %p\n", *(psh_ptr_iArray + 9), (psh_ptr_iArray + 9));
    return(0);
}