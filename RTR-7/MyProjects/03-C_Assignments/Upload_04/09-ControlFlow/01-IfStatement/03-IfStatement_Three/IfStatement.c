#include<stdio.h>
int main(void)
{
    // Variable Declarations
    int psh_num;

    // Code
    printf("\n\n");

    printf("Enter Value For 'PSH_NUM' : ");
    scanf("%d", &psh_num);

    if (psh_num < 0)
    {
        printf("PSH_NUM = %d Is Less Than 0 (NEGATIVE).\n\n", psh_num);
    }

    if ((psh_num > 0) && (psh_num <= 100))
    {
        printf("PSH_NUM = %d Is Between 0 AND 100.\n\n", psh_num);
    }

    if ((psh_num > 100) && (psh_num <= 200))
    {
        printf("PSH_NUM = %d Is Between 100 AND 200.\n\n", psh_num);
    }

    if ((psh_num > 200) && (psh_num <= 300))
    {
        printf("PSH_NUM = %d Is Between 200 AND 300.\n\n", psh_num);
    }

    if ((psh_num > 300) && (psh_num <= 400))
    {
        printf("PSH_NUM = %d Is Between 300 AND 400.\n\n", psh_num);
    }

    if ((psh_num > 400) && (psh_num <= 500))
    {
        printf("PSH_NUM = %d Is Between 400 AND 500.\n\n", psh_num);
    }

    if ((psh_num > 500))
    {
        printf("PSH_NUM = %d Is Greater than 500.\n\n", psh_num);
    }

    return(0);
}