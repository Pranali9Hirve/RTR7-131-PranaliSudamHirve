#include<stdio.h>
#include<stdlib.h> //Contains prototype of malloc and free

int main(void)
{
    //Variable Declarations
    int *psh_ptr_iArray = NULL;
    unsigned int pshIntArrayLength = 0;
    int psh_i;

    //Code
    printf("\n\n");
    printf("Enter the number of elements you want in your integer array: ");
    scanf("%d", &pshIntArrayLength);

    psh_ptr_iArray = (int*)malloc(sizeof(int) * pshIntArrayLength);

    if (psh_ptr_iArray == NULL)
    {
        printf("\n\n");
        printf("MEMORY ALLOCATION FOR INTEGER ARRAY HAS FAILED!!! EXITING NOW ... \n\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("MEMORY ALLOCATION FOR INTEGER ARRAY HAS SUCCEEDED!!! \n\n");
        printf("MEMORY ADDRESSES FROM %p TO %p HAVE BEEN ALLOCATED TO INTEGER ARRAY !!!\n\n", psh_ptr_iArray, (psh_ptr_iArray + (pshIntArrayLength -1)));
    }

    printf("\n\n");
    printf("Enter %d elements for the integer array: \n\n", pshIntArrayLength);
    for (psh_i = 0; psh_i < pshIntArrayLength; psh_i++)
    {
        scanf("%d", (psh_ptr_iArray + psh_i));
    }
    printf("\n\n");
    printf("The integer array entered by you, consisting of %d elements: \n", pshIntArrayLength);

    for (psh_i = 0; psh_i < pshIntArrayLength; psh_i++)
    {
        printf("psh_ptr_iArray[%d] = %d\t\t at address &psh_ptr_iArray[%d] : %p\n", psh_i, psh_ptr_iArray[psh_i], psh_i, &psh_ptr_iArray[psh_i]);
    }

    printf("\n\n");
    for (psh_i = 0; psh_i < pshIntArrayLength; psh_i++)
    {
        printf("*(psh_ptr_iArray + %d) = %d\t\t at address (psh_ptr_iArray + %d) : %p\n", psh_i, *(psh_ptr_iArray + psh_i), psh_i, (psh_ptr_iArray + psh_i));
    }
    
    if (psh_ptr_iArray)
    {
        free(psh_ptr_iArray);
        psh_ptr_iArray = NULL;

        printf("\n\n");
        printf("MEMORY ALLOCATED FOR INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED!!!\n\n");
    }
    return(0);
}
