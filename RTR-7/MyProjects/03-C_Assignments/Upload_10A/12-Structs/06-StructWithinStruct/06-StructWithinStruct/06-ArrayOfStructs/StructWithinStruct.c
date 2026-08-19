#include<stdio.h>

struct PshMyNumber
{
    int pshNum;
    int pshNumTable[10];
};

struct PshNumTables
{
    struct PshMyNumber pshN;
};

int main(void)
{
    // Variable Declarations
    struct PshNumTables pshTables[10]; // An array of 10 struct PshNumTables

    int psh_i, psh_j;

    // Code
    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        pshTables[psh_i].pshN.pshNum = (psh_i + 1);
    }

    for (psh_i = 0; psh_i < 10; psh_i++)
    { 
        printf("\n\n");
        printf("Table of %d : \n\n", pshTables[psh_i].pshN.pshNum);
        for (psh_j = 0; psh_j < 10; psh_j++)
        {
            pshTables[psh_i].pshN.pshNumTable[psh_j] = pshTables[psh_i].pshN.pshNum * (psh_j + 1);
            printf("%d * %d = %d\n", pshTables[psh_i].pshN.pshNum, (psh_j + 1), pshTables[psh_i].pshN.pshNumTable[psh_j]);
        }
    }

    return(0);
}
