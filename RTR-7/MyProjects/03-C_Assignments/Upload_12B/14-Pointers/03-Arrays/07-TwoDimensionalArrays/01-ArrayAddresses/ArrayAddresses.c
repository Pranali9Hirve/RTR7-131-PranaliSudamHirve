#include<stdio.h>
#include<stdlib.h>

#define PSH_NUM_ROWS 5
#define PSH_NUM_COLUMNS 3

int main(void)
{
    // Variable Declarations
    int psh_iArray[PSH_NUM_ROWS][PSH_NUM_COLUMNS];
    int psh_i, psh_j;

    // Code
    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS; psh_j++)
        {
            psh_iArray[psh_i][psh_j] = (psh_i + 1) * (psh_j + 1); 
        }
    }

    printf("\n\n");
    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS; psh_j++)
        {
           printf("psh_iArray[%d][%d] = %d \t\t At Address : %p\n", psh_i, psh_j, psh_iArray[psh_i][psh_j], &psh_iArray[psh_i][psh_j]);
        }
        printf("\n\n");
    }

    return(0);
}
