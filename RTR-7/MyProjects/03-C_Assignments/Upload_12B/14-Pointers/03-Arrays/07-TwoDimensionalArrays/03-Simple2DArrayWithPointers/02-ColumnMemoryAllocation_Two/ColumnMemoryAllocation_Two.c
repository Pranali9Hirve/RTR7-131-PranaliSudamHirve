#include<stdio.h>
#include<stdlib.h>

#define PSH_NUM_ROWS 5
#define PSH_NUM_COLUMNS_ONE 3
#define PSH_NUM_COLUMNS_TWO 8

int main(void)
{
    // Variable Declarations
    // A 2d array which will have 5 rows and number of columns can be decided later on...
    int *psh_iArray[PSH_NUM_ROWS];
    int psh_i, psh_j;

    // Code
    // *** ONE (ALLOCATING MEMORY FOR AN ARRAY OF 3 INTEGER PER ROW) ***
    printf("\n\n");
    printf("******** FIRST MEMORY ALLOCATION TO 2D INTEGER ARRAY *********\n");
    for ( psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        psh_iArray[psh_i] = (int *)malloc(PSH_NUM_COLUMNS_ONE * sizeof(int));
    }

    if (psh_iArray[psh_i] == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY TO ROW %d OF 2D INTEGER ARRAY !!! EXITING NOW...\n", psh_i);
        exit(0);
    }
    else
    {
        printf("MEMORY ALLOCATION TO ROW %d OF 2D INTEGER ARRAY HAS SUCCEEDED... \n", psh_i);
    }

    // *** ASSIGNING VALUES
    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {

        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS_ONE; psh_j++)
        {
            psh_iArray[psh_i][psh_j] = (psh_i + 1) * (psh_j + 1);
        }
    }

    // *** Displaying Values
    printf("\n");
    printf("DISPLAYING 2D ARRAY: \n");
    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS_ONE; psh_j++)
        {
           printf("psh_iArray[%d][%d] = %d\n", psh_i, psh_j, psh_iArray[psh_i][psh_j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // FREEING MEMORY ADDINGED TO 2D ARRAY (MUST BE DONE IN REVERSE ORDER)
    for (psh_i = (PSH_NUM_ROWS-1); psh_i >= 0; psh_i--)
    {
        if (psh_iArray[psh_i])
        {
            free(psh_iArray[psh_i]);
            psh_iArray[psh_i] = NULL;
            printf("MEMORY ALLOCATED TO ROW %d OF 2D ARRAY HAS BEEN SUCCESSFULLY FREED !!! \n", psh_i);
        }
    }

    // *** TWO (ALLOCATING MEMORY FOR AN ARRAY OF 8 INTEGER PER ROW) ***
    printf("\n\n");
    printf("******** SECOND MEMORY ALLOCATION TO 2D INTEGER ARRAY *********\n");
    for ( psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        psh_iArray[psh_i] = (int *)malloc(PSH_NUM_COLUMNS_TWO * sizeof(int));
    }

    if (psh_iArray[psh_i] == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY TO ROW %d OF 2D INTEGER ARRAY !!! EXITING NOW...\n", psh_i);
        exit(0);
    }
    else
    {
        printf("MEMORY ALLOCATION TO ROW %d OF 2D INTEGER ARRAY HAS SUCCEEDED... \n", psh_i);
    }

    // *** ASSIGNING VALUES
    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {

        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS_TWO; psh_j++)
        {
            psh_iArray[psh_i][psh_j] = (psh_i + 1) * (psh_j + 1);
        }
    }

    // *** Displaying Values
    printf("\n");
    printf("DISPLAYING 2D ARRAY: \n");
    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS_TWO; psh_j++)
        {
           printf("psh_iArray[%d][%d] = %d\n", psh_i, psh_j, psh_iArray[psh_i][psh_j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // FREEING MEMORY ADDINGED TO 2D ARRAY (MUST BE DONE IN REVERSE ORDER)
    for (psh_i = (PSH_NUM_ROWS-1); psh_i >= 0; psh_i--)
    {
        if (psh_iArray[psh_i])
        {
            free(psh_iArray[psh_i]);
            psh_iArray[psh_i] = NULL;
            printf("MEMORY ALLOCATED TO ROW %d OF 2D ARRAY HAS BEEN SUCCESSFULLY FREED !!! \n", psh_i);
        }
    }

    return(0);
}
