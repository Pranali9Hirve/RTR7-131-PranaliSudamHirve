#include <stdio.h>

int main(void)
{
    // variable declaraions

    int psh_iArray[3][5]; // 3 Rows (0, 1, 2) AND 5 COLUMNS (0, 1, 2, 3, 4)
    int psh_int_size;
    int psh_iArray_size;
    int psh_iArray_num_elements, psh_iArray_num_rows, psh_iArray_num_columns;
    int psh_i, psh_j;

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

    // *** PIECE-MEAL ASSIGNMENT***
    // ****** ROW 1 ******
    psh_iArray[0][0] =  10;
    psh_iArray[0][1] =  20;
    psh_iArray[0][2] =  30;
    psh_iArray[0][3] =  40;
    psh_iArray[0][4] =  50;
    printf("\n");

    // ****** ROW 2 ******

    psh_iArray[1][0] = 60;
    psh_iArray[1][1] = 70;
    psh_iArray[1][2] = 80;
    psh_iArray[1][3] = 90;
    psh_iArray[1][4] = 10;
    printf("\n");

    // ****** ROW 3 ******

    psh_iArray[2][0] = 100;
    psh_iArray[2][1] = 200;
    psh_iArray[2][2] = 300;
    psh_iArray[2][3] = 400;
    psh_iArray[2][4] = 500;
    printf("\n");


    // *** DISPLAY ***
    for (psh_i = 0; psh_i < psh_iArray_num_rows; psh_i++)
    {
        printf("****** ROW %d *******\n", (psh_i + 1));
        for (psh_j = 0; psh_j < psh_iArray_num_columns; psh_j++)
        {
            printf("psh_iArray[%d][%d] = %d \n", psh_i, psh_j, psh_iArray[psh_i][psh_j]);
        }
        printf("\n\n");
    }
    return (0);
}
