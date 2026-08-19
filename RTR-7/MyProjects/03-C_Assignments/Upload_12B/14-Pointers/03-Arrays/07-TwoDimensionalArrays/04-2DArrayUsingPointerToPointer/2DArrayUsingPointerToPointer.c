#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    // Variable Declarations
    // A pointer to pointer to integer ... but can also hold base address of a 2D array which will can have any number of rows and any number of columns
    int **psh_ptr_iArray = NULL;

    int psh_i, psh_j;
    int psh_num_rows, psh_num_columns;


    // Code

    // *** ACCEPT NUMBER OF ROWS 'num_rows' FROM USER ***
    printf("\n\n");

    printf("Enter Number of Rows: \n");
    scanf("%d", &psh_num_rows);

    printf("Enter Number of Columns: ");
    scanf("%d", &psh_num_columns);

    // *** ALLOCATING MEMORY TO 1D ARRAY CONSISTING OF BASE ADDRESS OF ROWS ***
    printf("\n\n");
    printf("************ MEMORY ALLOCATION TO 2D INTEGER ARRAY ***********\n");
    psh_ptr_iArray = (int **)malloc(psh_num_rows * sizeof(int *));

    if (psh_ptr_iArray == NULL)
    {
        printf("MEMORY ALLOCATION TO THE 1D ARRAY OF BASE ADDRESSES OF %d ROWS FAILED !!! EXITING NOW... \n\n", psh_num_rows);
        exit(0);
    }
    else
    {
        printf("MEMORY ALLOCATION TO THE 1D ARRAY OF BASE ADDRESSES OF %d ROWS HAS SUCCEEDED... \n", psh_num_rows);
    }

    // *** ALLOCATING MEMORY TO EACH ROW WHICH IS A 1D ARRAY CONTAINING CONSISTING OF COLUMNS WHICH CONTAIN THE ACTUAL INTEGERS ***
    for (psh_i = 0; psh_i < psh_num_rows; psh_i++)
    {
        psh_ptr_iArray[psh_i] = (int *)malloc(psh_num_columns * sizeof(int)); // ALLOCATING MEMORY (NUMBER OF COLUMNS * 'size if "int"') TO ROW 'i'
        if (psh_ptr_iArray[psh_i] == NULL) // ROW 'i' MEMORY ALLOCATED
        {
            printf("MEMORY ALLOCATION TO THE 1D ARRAY OF BASE ADDRESSES OF %d ROWS FAILED !!! EXITING NOW... \n", psh_i);
            exit(0);
        }
        else
        {
            printf("MEMORY ALLOCATION TO THE 1D ARRAY OF BASE ADDRESSES OF %d ROWS HAS SUCCEEDED... \n", psh_i);
        }
    }

    // *** ASSIGNING VALUES
    for (psh_i = 0; psh_i < psh_num_rows; psh_i++)
    {

        for (psh_j = 0; psh_j < psh_num_columns; psh_j++)
        {
            // *(*(psh_ptr_iArray + psh_i) + psh_j) = (psh_i + 1) * (psh_j + 1);
            psh_ptr_iArray[psh_i][psh_j] = (psh_i * 1) + (psh_j * 1);
        }
    }

    // *** Displaying Values
    for (psh_i = 0; psh_i < psh_num_rows; psh_i++)
    {
        printf("Base address of Row %d: psh_ptr_iArray[%d] = %p \t At Address: %p\n", psh_i, psh_i, psh_ptr_iArray[psh_i], &psh_ptr_iArray[psh_i]);
    }


    printf("\n\n");

    for (psh_i = 0; psh_i < psh_num_rows; psh_i++)
    {
        for (psh_j = 0; psh_j < psh_num_columns; psh_j++)
        {
           // printf("*(*(psh_ptr_iArray + %d) + %d) = %d \t\t At Address (*(psh_ptr_iArray + %d) + %d) : %p\n", psh_i, psh_j, *(*(psh_ptr_iArray + psh_i) + psh_j), psh_i, psh_j, (*(psh_ptr_iArray + psh_i) + psh_j));
           printf("psh_ptr_iArray[%d][%d] = %d \t At Address: %p\n", psh_i, psh_j, psh_ptr_iArray[psh_i][psh_j], &psh_ptr_iArray[psh_i][psh_j]);
        }
        printf("\n\n");
    }

    // FREEING ALLOCATED MEMORY
    // FREEING MEMORY OF EACH ROW
    for (psh_i = (psh_num_rows-1); psh_i >= 0; psh_i--)
    {
        if (psh_ptr_iArray[psh_i])
        {
            free(psh_ptr_iArray[psh_i]);
            psh_ptr_iArray[psh_i] = NULL;
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
