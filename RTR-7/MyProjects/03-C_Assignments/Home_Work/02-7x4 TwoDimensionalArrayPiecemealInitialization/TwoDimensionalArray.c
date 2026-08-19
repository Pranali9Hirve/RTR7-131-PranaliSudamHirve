#include <stdio.h>

int main(void)
{
    // variable declaraions

    int psh_iArray[7][4]; // 7 Rows (0, 1, 2, 3, 4, 5, 6) AND 4 COLUMNS (0, 1, 2, 3)
    int psh_i, psh_j;

    // code

    printf("Elements In Integer 2D Array : \n");

    // *** PIECE-MEAL ASSIGNMENT***
    // ****** ROW 1 ******
    psh_iArray[0][0] =  1;
    psh_iArray[0][1] =  2;
    psh_iArray[0][2] =  3;
    psh_iArray[0][3] =  4;


    // ****** ROW 2 ******

    psh_iArray[1][0] = 11;
    psh_iArray[1][1] = 12;
    psh_iArray[1][2] = 13;
    psh_iArray[1][3] = 14;


    // ****** ROW 3 ******

    psh_iArray[2][0] = 21;
    psh_iArray[2][1] = 22;
    psh_iArray[2][2] = 23;
    psh_iArray[2][3] = 24;

    // ****** ROW 4 ******

    psh_iArray[3][0] = 31;
    psh_iArray[3][1] = 32;
    psh_iArray[3][2] = 33;
    psh_iArray[3][3] = 34;

    // ****** ROW 5 ******

    psh_iArray[4][0] = 41;
    psh_iArray[4][1] = 42;
    psh_iArray[4][2] = 43;
    psh_iArray[4][3] = 44;

    // ****** ROW 6 ******

    psh_iArray[5][0] = 51;
    psh_iArray[5][1] = 52;
    psh_iArray[5][2] = 53;
    psh_iArray[5][3] = 54;

    // ****** ROW 7 ******

    psh_iArray[6][0] = 61;
    psh_iArray[6][1] = 62;
    psh_iArray[6][2] = 63;
    psh_iArray[6][3] = 64;


    // *** DISPLAY ***
    for (psh_i = 0; psh_i < 7; psh_i++)
    {
        printf("****** ROW %d *******\n", (psh_i + 1));
        for (psh_j = 0; psh_j < 4; psh_j++)
        {
            printf("psh_iArray[%d][%d] = %d \n", psh_i, psh_j, psh_iArray[psh_i][psh_j]);
        }
        printf("\n\n");
    }
    return (0);
}
