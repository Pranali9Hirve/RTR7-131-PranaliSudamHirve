#include <stdio.h>

int main(void)
{
    // variable declaraions

    // IN-LINE INITIALIZATION
    int psh_iArray[5][3] =
    {{1, 2, 3}, {2, 4, 6}, {3, 6, 9}, {4, 8, 12}, {5, 10, 15}};

    int psh_int_size;
    int psh_iArray_size;
    int psh_iArray_num_elements, psh_iArray_num_rows, psh_iArray_num_columns;
    int psh_i, psh_j, psh_k;

    // code
    printf("\n\n");

    psh_int_size = sizeof(int);
    
    psh_iArray_size = sizeof(psh_iArray);

    printf("Size Of Two Dimensional (2D) Integer Array Is = %d\n\n",
           psh_iArray_size);

    psh_iArray_num_rows = psh_iArray_size / sizeof(psh_iArray[0]);
    printf("Number of Rows In Two Dimensional (2D) Integer Array Is = %d\n\n",
           psh_iArray_num_rows);

    psh_iArray_num_columns = sizeof(psh_iArray[0]) / psh_int_size;
    printf("Number of Columns In Two Dimensional (2D) Integer Array Is = %d\n\n",
           psh_iArray_num_columns);

    psh_iArray_num_elements = psh_iArray_num_rows * psh_iArray_num_columns;
    printf("Number of Elements In Two Dimensional (2D) Integer Array Is = %d\n\n",
           psh_iArray_num_elements);

    printf("\n\n");

    printf("Elements In Integer 2D Array : \n\n");

    // *** PIECE-MEAL DISPLAY***
    // ARRAY INDICES BEGIN FROM 0, HENCE, 1ST ROW IS ACTUALLY 0TH ROW AND 1ST COLUMN IS ACTUALLY 0TH COLUMN

    for(psh_i = 0; psh_i<psh_iArray_num_rows; psh_i++)
    {
        printf("******* ROW %d ********** \n", (psh_i+1));
        for(psh_j = 0; psh_j<psh_iArray_num_columns; psh_j++)
        {
            printf("psh_iArray[%d][%d] = %d\n", psh_i, psh_j, psh_iArray[psh_i][psh_j]);
        }
        printf("\n\n");
    }

    return (0);
}
