#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    // Function Declaration
    void PshMultiplyArrayElementsByNum(int *, int, int);

    // Variable Declaration
    int *psh_iArray = NULL;
    int psh_num_elements;
    int psh_i, psh_num;

    // Code
    printf("Enter number of elements in integer array: ");
    scanf("%d", &psh_num_elements);

    psh_iArray = (int*)malloc(psh_num_elements * sizeof(int));
    if (psh_iArray == NULL)
    {
        printf("Memory allocation to integer array failed !! Exiting Now....\n\n ");
        exit(0);
    }

    printf("\n\n");
    printf("Enter %d elements for the integer array: \n", psh_num_elements);

    for (psh_i = 0; psh_i < psh_num_elements; psh_i++)
    {
        scanf("%d", &psh_iArray[psh_i]);
    }

    printf("\n");
    printf("Array before passing to PshMultiplyArrayElementsByNum function\n");
    for (psh_i = 0; psh_i < psh_num_elements; psh_i++)
    {
        printf("psh_iArray[%d] = %d\n", psh_i, psh_iArray[psh_i]);
    }

    printf("Enter the number by which you multiply the elements\n");
    scanf("%d", &psh_num);

    PshMultiplyArrayElementsByNum(psh_iArray, psh_num_elements, psh_num);

    printf("Array after passing to PshMultiplyArrayElementsByNum function\n");
    for (psh_i = 0; psh_i < psh_num_elements; psh_i++)
    {
        printf("psh_iArray[%d] = %d\n", psh_i, psh_iArray[psh_i]);
    }

    if (psh_iArray)
    {
        free(psh_iArray);
        psh_iArray = NULL;
        printf("Memory is freed for psh_iArray\n");
    }
    return(0);
}

void PshMultiplyArrayElementsByNum(int *psh_Array, int psh_num_elements, int psh_num)
{
    // Variable Declaration
    int psh_i;

    // Code
    for (psh_i = 0; psh_i < psh_num_elements; psh_i++)
    {
        psh_Array[psh_i] = psh_Array[psh_i] * psh_num;
    }
}
