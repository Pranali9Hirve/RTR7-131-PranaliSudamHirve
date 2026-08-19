#include<stdio.h>

int main(void)
{
    // Function Prototype
    void Swap(int *, int *);

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

    Swap(&psh_a, &psh_b); // ARGUMENTS PASSED BY REFERENCE / ADDRESS

    printf("\n\n");
    printf("******** After Swapping ************\n");
    printf("Value of 'psh_a' = %d\n", psh_a);
    printf("Value of 'psh_b' = %d\n", psh_b);

    return(0);
}

// ADDRESS OF 'psh_a' IS COPIED INTO 'psh_x' AND ADDRESS OF 'psh_b' IS COPIED INTO 'psh_y'
// SO, '&psh_a' and 'psh_x' are pointing to one and the same address and '&psh_b' and 'psh_y' are pointing to one and the same address  
// Swapping takes place between 'Value at address of 'psh_x' (Value at &psh_a i.e L 'psh_a') and 
// 'Value at address of 'psh_y' (Value at &psh_b i.e L 'psh_b')
// Hence Swapping in this case takes place between '*psh_x' and '*psh_y' as well as between 'psh_a' and 'psh_b' 

void Swap(int *psh_x, int *psh_y)
{
    // Variable Declarations
    int psh_temp;

    // Code
    printf("\n\n");
    printf("******** Brfore Swapping in Swap Function ************\n");
    printf("Value of 'psh_x' = %d\n", *psh_x);
    printf("Value of 'psh_y' = %d\n", *psh_y);

    psh_temp = *psh_x;
    *psh_x = *psh_y;
    *psh_y = psh_temp;

    printf("******** After Swapping in Swap Function ************\n");
    printf("Value of 'psh_x' = %d\n", *psh_x);
    printf("Value of 'psh_y' = %d\n", *psh_y);
}
