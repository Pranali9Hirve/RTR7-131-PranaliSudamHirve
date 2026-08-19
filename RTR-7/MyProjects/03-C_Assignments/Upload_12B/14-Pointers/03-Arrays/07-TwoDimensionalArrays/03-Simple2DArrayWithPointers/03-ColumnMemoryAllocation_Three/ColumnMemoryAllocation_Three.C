#include<stdio.h>
#include<stdlib.h>

#define PSH_NUM_ROWS 5
#define PSH_NUM_COLUMNS 5

int main(void)
{
    // Variable Declarations
    // A 2d array which will have 5 rows and number of columns can be decided later on...
    int *psh_iArray[PSH_NUM_ROWS];
    int psh_i, psh_j;

    // Code
    printf("\n\n");
    printf("************ MEMORY ALLOCATION TO 2D INTEGER ARRAY *************\n");
    for ( psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        // ROW 0 WILL HAVE (PSH_NUM_COLUMNS - 0) = (5-0) = 5 COLUMNS
        // ROW 1 WILL HAVE (PSH_NUM_COLUMNS - 1) = (5-1) = 4 COLUMNS
        // ROW 2 WILL HAVE (PSH_NUM_COLUMNS - 2) = (5-2) = 3 COLUMNS
        // ROW 3 WILL HAVE (PSH_NUM_COLUMNS - 3) = (5-3) = 2 COLUMNS
        // ROW 4 WILL HAVE (PSH_NUM_COLUMNS - 4) = (5-4) = 1 COLUMNS

        // BECAUSE OF THIS, THERE IS NO CONTIGUIOUS MEMORY ALLOCATION HENCE,
        // ALTHOUGH WE MAY USE THE DATA AS A 2D ARRAY, IT IS NOT REALLY A 2D ARRAY IN MEMORY...

        psh_iArray[psh_i] = (int *)malloc((PSH_NUM_COLUMNS - 1) * sizeof(int));

        if (psh_iArray[psh_i] == NULL)
        {
            printf("FAILED TO ALLOCATE MEMORY TO ROW %d OF 2D INTEGER ARRAY !!! EXITING NOW...\n", psh_i);
            exit(0);
        }
        else
        {
            printf("MEMORY ALLOCATION TO ROW %d OF 2D INTEGER ARRAY HAS SUCCEEDED... \n", psh_i);
        }
    }

    

    // *** ASSIGNING VALUES
    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {

        for (psh_j = 0; psh_j < ( PSH_NUM_COLUMNS - 1); psh_j++)
        {
            psh_iArray[psh_i][psh_j] = (psh_i + 1) * (psh_j + 1);
        }
    }

    // *** Displaying Values
    printf("\n");
    printf("DISPLAYING 2D ARRAY: \n");
    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS; psh_j++)
        {
           printf("psh_iArray[%d][%d] = %d \t At Address: %p\n", psh_i, psh_j, psh_iArray[psh_i][psh_j], &psh_iArray[psh_i][psh_j]);
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
