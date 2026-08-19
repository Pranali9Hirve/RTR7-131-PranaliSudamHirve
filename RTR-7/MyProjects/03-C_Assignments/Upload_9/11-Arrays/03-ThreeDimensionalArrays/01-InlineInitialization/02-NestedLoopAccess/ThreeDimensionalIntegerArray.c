#include <stdio.h>

int main(void)
{
    // variable declaraions

    // IN-LINE INITIALIZATION
    int psh_iArray[5][3][2] =
    {
        { { 9, 18 }, { 27, 36 }, { 45, 54 } },
        { { 8, 16 }, { 24, 32 }, { 40, 48 } },
        { { 7, 14 }, { 21, 28 }, { 35, 42 } },
        { { 6, 12 }, { 18, 24 }, { 30, 36 } },
        { { 5, 10 }, { 15, 20 }, { 25, 30 } }
    };

    int psh_int_size;
    int psh_iArray_size;
    int psh_iArray_num_elements, psh_iArray_width, psh_iArray_height, psh_iArray_depth;
    int psh_i, psh_j, psh_k;

    // code
    printf("\n\n");

    psh_int_size = sizeof(int);
    psh_iArray_size = sizeof(psh_iArray);

    printf("Size Of Three Dimensional (3D) Integer Array Is = %d\n\n",
           psh_iArray_size);

    psh_iArray_width = psh_iArray_size / sizeof(psh_iArray[0]);
    printf("Number of Rows (Width) In Three Dimensional (3D) Integer Array Is = %d\n\n",
           psh_iArray_width);

    psh_iArray_height = sizeof(psh_iArray[0]) / sizeof(psh_iArray[0][0]);
    printf("Number of Columns (Height) In Three Dimensional (3D) Integer Array Is = %d\n\n",
           psh_iArray_height);

    psh_iArray_depth = sizeof(psh_iArray[0][0]) / psh_int_size;
    printf("Depth In Three Dimensional (3D) Integer Array Is = %d\n\n",
           psh_iArray_depth);

    psh_iArray_num_elements = psh_iArray_width * psh_iArray_height * psh_iArray_depth;
    printf("Number of Elements In Three Dimensional (3D) Integer Array Is = %d\n\n",
           psh_iArray_num_elements);

    printf("\n\n");
    printf("Elements In Integer 3D Array : \n\n");

    for (psh_i = 0; psh_i < psh_iArray_width; psh_i++)
    {
        printf("****** ROW %d ******\n", (psh_i + 1));

        for (psh_j = 0; psh_j < psh_iArray_height; psh_j++)
        {
            printf("****** COLUMN %d ******\n", (psh_j + 1));

            for (psh_k = 0; psh_k < psh_iArray_depth; psh_k++)
            {
                printf("psh_iArray[%d][%d][%d] = %d\n",
                       psh_i, psh_j, psh_k, psh_iArray[psh_i][psh_j][psh_k]);
            }

            printf("\n");
        }

        printf("\n\n");
    }

    return (0);
}
