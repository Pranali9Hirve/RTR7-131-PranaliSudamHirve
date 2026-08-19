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

    // ****** ROW 1 ******
    printf("****** ROW 1 ******\n");
    printf("psh_iArray[0][0] = %d\n", psh_iArray[0][0]);
    printf("psh_iArray[0][1] = %d\n", psh_iArray[0][1]);
    printf("psh_iArray[0][2] = %d\n", psh_iArray[0][2]);
    printf("\n");

    // ****** ROW 2 ******
    printf("****** ROW 2 ******\n");

    printf("psh_iArray[1][0] = %d\n", psh_iArray[1][0]);
    printf("psh_iArray[1][1] = %d\n", psh_iArray[1][1]);
    printf("psh_iArray[1][2] = %d\n", psh_iArray[1][2]);
    printf("\n");

    // ****** ROW 3 ******
    printf("****** ROW 3 ******\n");

    printf("psh_iArray[2][0] = %d\n", psh_iArray[2][0]);
    printf("psh_iArray[2][1] = %d\n", psh_iArray[2][1]);
    printf("psh_iArray[2][2] = %d\n", psh_iArray[2][2]);
    printf("\n");

    // ****** ROW 4 ******
    printf("****** ROW 4 ******\n");

    printf("psh_iArray[3][0] = %d\n", psh_iArray[3][0]);
    printf("psh_iArray[3][1] = %d\n", psh_iArray[3][1]);
    printf("psh_iArray[3][2] = %d\n", psh_iArray[3][2]);
    printf("\n");

    // ****** ROW 5 ******
    printf("****** ROW 5 ******\n");

    printf("psh_iArray[4][0] = %d\n", psh_iArray[4][0]);
    printf("psh_iArray[4][1] = %d\n", psh_iArray[4][1]);
    printf("psh_iArray[4][2] = %d\n", psh_iArray[4][2]);
    printf("\n\n");

    return (0);
}
