#include <stdio.h>

#define PSH_NUM_ROWS    5
#define PSH_NUM_COLUMNS 3

int main(void)
{
    // variable declaraions
    int psh_iArray_2D[PSH_NUM_ROWS][PSH_NUM_COLUMNS]; // TOTAL NUMBER OF ELEMENTS = PSH_NUM_ROWS * PSH_NUM_COLUMNS
    int psh_iArray_1D[PSH_NUM_ROWS * PSH_NUM_COLUMNS];

    int psh_i, psh_j;
    int psh_num;

    // code
    printf("Enter Elements Of Your Choice To Fill Up The Integer 2D Array : \n");

    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        printf("For ROW NUMBER %d : \n", (psh_i + 1));

        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS; psh_j++)
        {
            printf("Enter Element Number %d: \n", (psh_j + 1));
            scanf("%d", &psh_num);

            psh_iArray_2D[psh_i][psh_j] = psh_num;
        }

        printf("\n");
    }

    // *** DISPLAY OF 2D ARRAY ***
    printf("\n");
    printf("Two-Dimensional (2D) Array Of Integers : \n\n");

    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        printf("****** ROW %d ******\n", (psh_i + 1));

        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS; psh_j++)
        {
            printf("psh_iArray_2D[%d][%d] = %d\n", psh_i, psh_j, psh_iArray_2D[psh_i][psh_j]);
        }

        printf("\n");
    }

    // CONVERTING 2D INTEGER ARRAY TO 1D INTEGER ARRAY
    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS; psh_j++)
        {
            psh_iArray_1D[(psh_i * PSH_NUM_COLUMNS) + psh_j] = psh_iArray_2D[psh_i][psh_j];
        }
    }

    // *** PRINTING 1D ARRAY ***
    printf("\n");
    printf("One-Dimensional (1D) Array Of Integers : \n\n");

    for (psh_i = 0; psh_i < (PSH_NUM_ROWS * PSH_NUM_COLUMNS); psh_i++)
    {
        printf("psh_iArray_1D[%d] = %d\n", psh_i, psh_iArray_1D[psh_i]);
    }

    printf("\n");

    return (0);
}
