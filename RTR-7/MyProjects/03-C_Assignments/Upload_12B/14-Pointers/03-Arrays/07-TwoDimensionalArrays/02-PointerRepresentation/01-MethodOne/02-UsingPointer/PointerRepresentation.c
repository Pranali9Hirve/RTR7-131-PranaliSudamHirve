#include<stdio.h>
#include<stdlib.h>

#define PSH_NUM_ROWS 5
#define PSH_NUM_COLUMNS 3

int main(void)
{
    // Variable Declarations
    int psh_iArray[PSH_NUM_ROWS][PSH_NUM_COLUMNS];
    int psh_i, psh_j;

    int *psh_ptr_iArray_row = NULL;

    // Code

    //  **** EVERY ROW OF A 2D ARRAY IS AN INTEGER ARRAY ITSELF COMPRISING OF 'PSH_NUM_COLUMNS' INTEGER ELEMENTS ****
    // **** THERE ARE 5 ROWS AND 3 COLUMNS IN A 2D INTEGER ARRAY. EACH OF THE 5 ROWS IS A 1D ARRAY OF 3 INTEGERS **** 
    // *** HENCE, EACH OF THESE 5 ROWS THEMSELVES BEING ARRAYS, WILL BE THE BASE ADDRESSES OF THEIR RESPECTIVE ROWS

    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        psh_ptr_iArray_row = psh_iArray[psh_i]; // psh_iArray[psh_i] is the base address of ith row
        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS; psh_j++)
        {
            *(psh_ptr_iArray_row + psh_j) = (psh_i + 1) * (psh_j + 1); // 'psh_ptr_iArray_row' (That is, 'psh_iArray[psh_i]') CAN BE TREATED AS 1D ARRAY USING POINTERS...
        }
    }

    printf("\n\n");
    printf("2D Integer array elements along with addresses: \n");
    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS; psh_j++)
        {
           printf("*(psh_ptr_iArray_row + [%d]) = %d \t\t At Address (psh_ptr_iArray_row + psh_j) : %p\n", psh_j, *(psh_ptr_iArray_row + psh_j), (psh_ptr_iArray_row + psh_j));
        }
        printf("\n\n");
    }

    return(0);
}
