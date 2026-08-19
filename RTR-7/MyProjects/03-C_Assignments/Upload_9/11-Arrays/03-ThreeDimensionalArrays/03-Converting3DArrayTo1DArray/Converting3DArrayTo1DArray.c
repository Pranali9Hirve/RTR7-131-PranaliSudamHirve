#include <stdio.h>

#define PSH_NUM_ROWS    5
#define PSH_NUM_COLUMNS 3
#define PSH_DEPTH       2

int main(void)
{
    // variable declaraions

    // IN-LINE INITIALIZATION
    int psh_iArray[PSH_NUM_ROWS][PSH_NUM_COLUMNS][PSH_DEPTH] =
    {
        { { 9, 18 }, { 27, 36 }, { 45, 54 } },
        { { 8, 16 }, { 24, 32 }, { 40, 48 } },
        { { 7, 14 }, { 21, 28 }, { 35, 42 } },
        { { 6, 12 }, { 18, 24 }, { 30, 36 } },
        { { 5, 10 }, { 15, 20 }, { 25, 30 } }
    };

    int psh_i, psh_j, psh_k;

    int psh_iArray_1D[PSH_NUM_ROWS * PSH_NUM_COLUMNS * PSH_DEPTH]; // 5 * 3 * 2 = 30 ELEMENTS IN 1D ARRAY

    // code

    // ****** DISPLAY 3D ARRAY ******
    printf("\n\n");
    printf("Elements In The 3D Array : \n\n");

    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        printf("****** ROW %d ******\n", (psh_i + 1));

        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS; psh_j++)
        {
            printf("****** COLUMN %d ******\n", (psh_j + 1));

            for (psh_k = 0; psh_k < PSH_DEPTH; psh_k++)
            {
                printf("psh_iArray[%d][%d][%d] = %d\n",
                       psh_i, psh_j, psh_k, psh_iArray[psh_i][psh_j][psh_k]);
            }

            printf("\n");
        }

        printf("\n");
    }

    // ****** CONVERTING 3D TO 1D ******
    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS; psh_j++)
        {
            for (psh_k = 0; psh_k < PSH_DEPTH; psh_k++)
            {
                psh_iArray_1D[(psh_i * PSH_NUM_COLUMNS * PSH_DEPTH) + (psh_j * PSH_DEPTH) + psh_k] =
                    psh_iArray[psh_i][psh_j][psh_k];
            }
        }
    }

    // ****** DISPLAY 1D ARRAY ******
    printf("\n\n");
    printf("Elements In The 1D Array : \n");

    for (psh_i = 0; psh_i < (PSH_NUM_ROWS * PSH_NUM_COLUMNS * PSH_DEPTH); psh_i++)
    {
        printf("psh_iArray_1D[%d] = %d\n", psh_i, psh_iArray_1D[psh_i]);
    }

    return (0);
}
