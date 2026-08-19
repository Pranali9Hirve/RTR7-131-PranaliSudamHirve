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

    // *** ARRAY ELEMENTS INPUT
    for (psh_i = 0; psh_i < PSH_NUM_ELEMENT; psh_i++)
    {
        scanf("%d", &psh_num);
        psh_iArray[psh_i] = psh_num;
    }

    // *** SEPARATING OUT EVEN NUMBERS FROM ARRAY ELEMENTS ***

    printf("\n\n");
    printf("Even number amongest the array elements are :\n");
    for (psh_i = 0; psh_i < PSH_NUM_ELEMENT; psh_i++)
    {
        if ((psh_iArray[psh_i] % 2) == 0)
        {
            printf("%d\n", psh_iArray[psh_i]);
        }
    }

    // *** SEPARATING OUT ODD NUMBERS FROM ARRAY ELEMENTS ***

    printf("\n\n");
    printf("Odd number amongest the array elements are :\n");
    for (psh_i = 0; psh_i < PSH_NUM_ELEMENT; psh_i++)
    {
        if ((psh_iArray[psh_i] % 2) != 0)
        {
            printf("%d\n", psh_iArray[psh_i]);
        }
    }

    return(0);
}
