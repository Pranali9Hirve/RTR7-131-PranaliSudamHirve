#include<stdio.h>

int main(void)
{
    // Variable declarations
    int psh_a;
    int psh_b;

    //code
    printf("\n\n");
    printf("Enter A Number : ");
    scanf("%d", &psh_a);

    printf("\n\n");
    printf("Enter Another Number : ");
    scanf("%d", &psh_b);

    printf("\n\n");

    printf("A = %d\n", psh_a);
    printf("A = %d\n", psh_a++);
    printf("A = %d\n", psh_a);
    printf("A = %d\n", ++psh_a);

    printf("B = %d\n", psh_b);
    printf("B = %d\n", psh_b--);
    printf("B = %d\n", psh_b);
    printf("B = %d\n", --psh_b);

    printf("\n\n");

    return(0);
}