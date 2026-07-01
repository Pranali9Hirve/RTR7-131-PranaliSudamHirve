#include<stdio.h>
int main(void)
{
    // Variable Declarations
    int psh_age;

    // Code
    printf("\n\n");
    printf("Enter Age : ");
    scanf("%d", &psh_age);

    if (psh_age >= 18)
    {
        printf("You are eligible for Voting !!!\n\n");
    }

    return(0);
}