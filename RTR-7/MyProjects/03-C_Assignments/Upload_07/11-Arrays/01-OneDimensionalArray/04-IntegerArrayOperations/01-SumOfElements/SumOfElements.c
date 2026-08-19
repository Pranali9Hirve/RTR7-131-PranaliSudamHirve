#include<stdio.h>

#define PSH_NUM_ELEMENT 10

int main(void)
{
    // Variable declarations
    int psh_iArray[PSH_NUM_ELEMENT];
    int psh_i, psh_num, psh_sum = 0;

    // Code
    printf("\n\n");
    printf("Enter Integer Elements For Array :\n");

    for (psh_i = 0; psh_i < PSH_NUM_ELEMENT; psh_i++)
    {
        scanf("%d", &psh_num);
        psh_iArray[psh_i] = psh_num;
    }

    for (psh_i = 0; psh_i < PSH_NUM_ELEMENT; psh_i++)
    {
        psh_sum = psh_sum + psh_iArray[psh_i];
    }

    printf("\n\n");
    printf("Sum of all elements of Array = %d\n\n", psh_sum);

    return(0);
}
