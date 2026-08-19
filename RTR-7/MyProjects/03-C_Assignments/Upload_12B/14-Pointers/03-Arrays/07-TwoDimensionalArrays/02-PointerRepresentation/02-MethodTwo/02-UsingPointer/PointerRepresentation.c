#include<stdio.h>
#include<stdlib.h>

#define PSH_NUM_ROWS 5
#define PSH_NUM_COLUMNS 3

int main(void)
{
    // Variable Declarations
    int psh_i, psh_j;

    int **psh_ptr_iArray = NULL;

    // Code

    //  **** EVERY ROW OF A 2D ARRAY IS AN INTEGER ARRAY ITSELF COMPRISING OF 'PSH_NUM_COLUMNS' INTEGER ELEMENTS ****
    // **** THERE ARE 5 ROWS AND 3 COLUMNS IN A 2D INTEGER ARRAY. EACH OF THE 5 ROWS IS A 1D ARRAY OF 3 INTEGERS **** 
    // *** HENCE, EACH OF THESE 5 ROWS THEMSELVES BEING ARRAYS, WILL BE THE BASE ADDRESSES OF THEIR RESPECTIVE ROWS

    printf("\n\n");

    // MEMORY ALLOCATION
    // psh_ptr_iArray is the name and base address of 1d array containing 5 integer pointer to 5 integer arrays so it is an array contaning elements of data type (int *)
    psh_ptr_iArray = (int **)malloc(PSH_NUM_ROWS * sizeof(int *));

    if (psh_ptr_iArray == NULL)
    {
        printf("MEMORY ALLOCATION TO THE 1D ARRAY OF BASE ADDRESSES OF %d ROWS FAILED !!! EXITING NOW... \n\n", PSH_NUM_ROWS);
        exit(0);
    }
    else
    {
        printf("MEMORY ALLOCATION TO THE 1D ARRAY OF BASE ADDRESSES OF %d ROWS HAS SUCCEEDED... \n", PSH_NUM_ROWS);
    }

    // *** ALLOCATING MEMORY TO EACH ROW ***
    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        psh_ptr_iArray[psh_i] = (int *)malloc(PSH_NUM_COLUMNS * sizeof(int)); // psh_iArray[psh_i] is the base address of ith row
        if (psh_ptr_iArray == NULL)
        {
            printf("MEMORY ALLOCATION TO THE 1D ARRAY OF BASE ADDRESSES OF %d ROWS FAILED !!! EXITING NOW... \n", PSH_NUM_ROWS);
            exit(0);
        }
        else
        {
            printf("MEMORY ALLOCATION TO THE 1D ARRAY OF BASE ADDRESSES OF %d ROWS HAS SUCCEEDED... \n", PSH_NUM_ROWS);
        }
    }

    // *** ASSIGNING VALUES
    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {

        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS; psh_j++)
        {
            *(*(psh_ptr_iArray + psh_i) + psh_j) = (psh_i + 1) * (psh_j + 1);
        }
    }

    // *** Displaying Values
    printf("\n\n");
    printf("2D Integer array elements along with addresses: \n");
    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS; psh_j++)
        {
           printf("*(*(psh_ptr_iArray + %d) + %d) = %d \t\t At Address (*(psh_ptr_iArray + %d) + %d) : %p\n", psh_i, psh_j, *(*(psh_ptr_iArray + psh_i) + psh_j), psh_i, psh_j, (*(psh_ptr_iArray + psh_i) + psh_j));
        }
        printf("\n\n");
    }

    // FREEING ALLOCATED MEMORY
    // FREEING MEMORY OF EACH ROW
    for (psh_i = (PSH_NUM_ROWS-1); psh_i >= 0; psh_i--)
    {
        if (*(psh_ptr_iArray + psh_i))
        {
            free(*(psh_ptr_iArray + psh_i)); // free(psh_ptr_iArray[psh_i])
            *(psh_ptr_iArray + psh_i) = NULL;
            printf("MEMORY ALLOCATED TO ROW %d HAS BEEN SUCCESSFULLY FREED !!! \n\n", psh_i);
        }
    }

    // *** FREEING MEMORY OF psh_ptr_iArray WHICH IS THE ARRAY OF 5 INTEGER POINTERS ... THAT IS, 
    // IT IS AN ARRAY HAVING 5 INTEGER ADDRESSES (TYPE int *) ***
    if (psh_ptr_iArray)
    {
        free(psh_ptr_iArray);
        psh_ptr_iArray = NULL;
        printf("MEMORY ALLOCATED TO psh_ptr_iArray HAS BEEN SUCCESSFULLY FREED !!! \n\n");
    }

    return(0);
}
