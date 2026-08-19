#include<stdio.h>

#define PSH_NUM_ELEMENT 10

int main(void)
{
    // Variable declarations
    int psh_iArray[PSH_NUM_ELEMENT];
    int psh_i, psh_num, psh_j, psh_count = 0;

    // Code
    printf("\n\n");

    // *** ARRAY ELEMENTS INPUT
    printf("Enter Integer Elements For Array :\n");
    for (psh_i = 0; psh_i < PSH_NUM_ELEMENT; psh_i++)
    {
        scanf("%d", &psh_num);

        // If 'psh_num' is negative (<0), then convert it to positive (multiply by -1)
        
        if (psh_num < 0)
        {
            psh_num = -1 * psh_num;
        }

        psh_iArray[psh_i] = psh_num;
    }

    // *** PRINTING ENTIRE ARRAY ***

    printf("\n\n");
    printf("Array elements are :\n");
    for (psh_i = 0; psh_i < PSH_NUM_ELEMENT; psh_i++)
    {
        printf("%d\n", psh_iArray[psh_i]);
    }

    // *** SEPARATING OUT PRIME NUMBERS FROM ARRAY ELEMENTS ***

    printf("\n\n");
    printf("Prime number amongest the array elements are :\n");
    for (psh_i = 0; psh_i < PSH_NUM_ELEMENT; psh_i++)
    {
        for (psh_j = 1; psh_j <= psh_iArray[psh_i]; psh_j++)
        {
            if ((psh_iArray[psh_i] % psh_j) == 0)
            {
                psh_count++;
            }
        }

        // NUMBER 1 IS NEITHER A PRIME NUMBER FOR A CONSONANT
        // IF A NUMBER IS PRIME, IT IS ONLY DIVISIBLE BY 1 AND ITSELF
        // HENCE IF A NUMBER IS PRIME THE VALUE OF 'COUNT' WILL BE EXACTLY 2
        // IF VALUE OF COUNT IS GEARTER THAN 2, THE NUMBER IS DIVISIBLE BY NUMBERS OTHER THAN 1 AND ITSELF AND HENCE IT IS NOT PRIME
        // THE VALUE OF COUNT WILL BE 1 ONLY IF psh_iArray[psh_i] IS 1

        if (psh_count == 2)
        {
            printf("%d\n", psh_iArray[psh_i]);
        }
        psh_count = 0; // RESET count to 0 for checking the next number
    }

    return(0);
}
