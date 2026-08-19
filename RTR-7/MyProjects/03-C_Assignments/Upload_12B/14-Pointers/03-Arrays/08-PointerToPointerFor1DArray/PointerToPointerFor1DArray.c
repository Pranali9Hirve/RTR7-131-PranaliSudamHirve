#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    void MyAlloc(int **psh_ptr, unsigned int pshNumberOfElements);

    // Variable declarations
    int *pshPiArray = NULL;
    unsigned int psh_num_elements;
    int psh_i;

    // Code
    printf("\n\n");
    printf("How many elements you want in integer array? \n\n");
    scanf("%u", &psh_num_elements);

    printf("\n\n");
    MyAlloc(&pshPiArray, psh_num_elements);

    printf("Enter %u elements to fill up your integer array: \n\n", psh_num_elements);
    for (psh_i = 0; psh_i < psh_num_elements; psh_i++)
    {
        scanf("%d", &pshPiArray[psh_i]);
    }

    printf("\n\n");
    printf("The %u elements entered by you in integer array: \n\n", psh_num_elements);
    for (psh_i = 0; psh_i < psh_num_elements; psh_i++)
    {
        printf("%u", pshPiArray[psh_i]);
    }

    printf("\n\n");
    if (pshPiArray)
    {
        free(pshPiArray);
        pshPiArray = NULL;
        printf("Memory Allocated Has Now Been Successfully Freed !!! \n\n");
    }

    return(0);
}

void MyAlloc(int **ptr, unsigned int numberOfElements)
{
    *ptr = (int *)malloc(numberOfElements * sizeof(int));
    if (*ptr == NULL)
    {
        printf("Could not allocate Memory !!! Exiting Now... \n\n");
        exit(0);
    }
    printf("MyAlloc() has successfully allocated %zu bytes for integer array !!! \n", (numberOfElements * sizeof(int)));
}
