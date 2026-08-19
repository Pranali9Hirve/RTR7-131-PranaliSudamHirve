#include <stdio.h>

int main(void)
{
    // variable declaration
    int psh_iArray_One[5];
    int psh_iArray_Two[5][3];
    int psh_iArray_Three[100][100][5];

    int psh_num_rows_2D;
    int psh_num_columns_2D;

    int psh_num_rows_3D;
    int psh_num_columns_3D;
    int psh_depth_3D;

    // code
    printf("\n\n");

    printf("Size of 1-D integer array psh_iArray_One = %zu\n",
           sizeof(psh_iArray_One));

    printf("Number of elements in 1-D integer array psh_iArray_One = %zu\n",
           (sizeof(psh_iArray_One) / sizeof(int)));

    printf("\n\n");

    printf("Size of 2-D integer array psh_iArray_Two = %zu\n",
           sizeof(psh_iArray_Two));

    psh_num_rows_2D = (sizeof(psh_iArray_Two) / sizeof(psh_iArray_Two[0]));
    printf("Number rows in 2-D integer array psh_iArray_Two = %d\n",
           psh_num_rows_2D);

    psh_num_columns_2D = (sizeof(psh_iArray_Two[0]) / sizeof(psh_iArray_Two[0][0]));
    printf("Number of elements (columns) in each row in 2-D integer array psh_iArray_Two = %d\n",
           psh_num_columns_2D);

    printf("Number of elements in total in 2-D Array psh_iArray_Two = %d\n",
           (psh_num_rows_2D * psh_num_columns_2D));

    printf("\n\n");

    printf("Size of 3-D integer array psh_iArray_Three = %zu\n",
           sizeof(psh_iArray_Three));

    psh_num_rows_3D = (sizeof(psh_iArray_Three) / sizeof(psh_iArray_Three[0]));
    printf("Number rows in 3-D integer array psh_iArray_Three = %d\n",
           psh_num_rows_3D);

    psh_num_columns_3D = (sizeof(psh_iArray_Three[0]) / sizeof(psh_iArray_Three[0][0]));
    printf("Number of elements (columns) in one row in 3-D integer array psh_iArray_Three = %d\n",
           psh_num_columns_3D);

    psh_depth_3D = (sizeof(psh_iArray_Three[0][0]) / sizeof(psh_iArray_Three[0][0][0]));
    printf("Number of elements (depth) in one column in one row in 3-D integer array psh_iArray_Three = %lu\n",
           psh_depth_3D);

    printf("Number of elements in total in 3-D Array psh_iArray_Three = %d\n",
           (psh_num_rows_3D * psh_num_columns_3D * psh_depth_3D));

    printf("\n\n");

    return (0);
}
