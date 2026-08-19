#include<stdio.h>

struct PshMyNumber
{
    int pshNum;
    int pshNumTable[10];
};

struct PshNumTables
{
    struct PshMyNumber pshA;
    struct PshMyNumber pshB;
    struct PshMyNumber pshC;
};

int main(void)
{
    // Variable Declarations
    struct PshNumTables pshTables;

    int psh_i;

    // Code
    pshTables.pshA.pshNum = 2;
    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        pshTables.pshA.pshNumTable[psh_i] = pshTables.pshA.pshNum * (psh_i + 1);
    }
    printf("\n\n");
    printf("Table of %d : \n\n", pshTables.pshA.pshNum);
    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        printf("%d * %d = %d\n", pshTables.pshA.pshNum, (psh_i + 1), pshTables.pshA.pshNumTable[psh_i]);
    }

    pshTables.pshB.pshNum = 3;
    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        pshTables.pshB.pshNumTable[psh_i] = pshTables.pshB.pshNum * (psh_i + 1);
    }
    printf("\n\n");
    printf("Table of %d : \n\n", pshTables.pshB.pshNum);
    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        printf("%d * %d = %d\n", pshTables.pshB.pshNum, (psh_i + 1), pshTables.pshB.pshNumTable[psh_i]);
    }

    pshTables.pshC.pshNum = 4;
    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        pshTables.pshC.pshNumTable[psh_i] = pshTables.pshC.pshNum * (psh_i + 1);
    }
    printf("\n\n");
    printf("Table of %d : \n\n", pshTables.pshC.pshNum);
    for (psh_i = 0; psh_i < 10; psh_i++)
    {
        printf("%d * %d = %d\n", pshTables.pshC.pshNum, (psh_i + 1), pshTables.pshC.pshNumTable[psh_i]);
    }

    return(0);
}
