#include<stdio.h>

int main(void)
{
    // Function Prototype
    void Swap(int, int);

    // Variable Declaration
    int psh_a, psh_b;

    // Code
    printf("\n\n");
    printf("Enter Value of 'psh_a': \n");
    scanf("%d", &psh_a);

    printf("Enter Value of 'psh_b': \n");
    scanf("%d", &psh_b);

    printf("******** Brfore Swapping ************\n");
    printf("Value of 'psh_a' = %d\n", psh_a);
    printf("Value of 'psh_b' = %d\n", psh_b);

    Swap(psh_a, psh_b);

    printf("\n\n");
    printf("******** After Swapping ************\n");
    printf("Value of 'psh_a' = %d\n", psh_a);
    printf("Value of 'psh_b' = %d\n", psh_b);

    return(0);
}

// Value of 'psh_a' is copied into 'psh_x' and value of 'psh_b' is copied into 'psh_y'
// Swapping takes place between psh_x and psh_y, not between psh_a and psh_b
void Swap(int psh_x, int psh_y)
{
    // Variable Declarations
    int psh_temp;

    // Code
    printf("\n\n");
    printf("******** Brfore Swapping in Swap Function ************\n");
    printf("Value of 'psh_x' = %d\n", psh_x);
    printf("Value of 'psh_y' = %d\n", psh_y);

    psh_temp = psh_x;
    psh_x = psh_y;
    psh_y = psh_temp;

    printf("******** After Swapping in Swap Function ************\n");
    printf("Value of 'psh_x' = %d\n", psh_x);
    printf("Value of 'psh_y' = %d\n", psh_y);
}
