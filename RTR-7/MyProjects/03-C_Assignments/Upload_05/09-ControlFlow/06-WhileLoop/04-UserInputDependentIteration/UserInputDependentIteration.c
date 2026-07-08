#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_i_num, psh_num, psh_i;

    // Code
    printf("\n\n");

    printf("Enter an Integer value from which iteration must begin: ");
    scanf("%d", &psh_i_num);

    printf("How many digits do you want to print from %d onwards? : ", psh_i_num);
    scanf("%d", &psh_num);

    printf("Printing Digits %d to %d : \n\n", psh_i_num, (psh_i_num + psh_num));
    psh_i = psh_i_num;

    while ( psh_i <= (psh_i_num + psh_num))
    {
        printf("\t%d\n", psh_i);
        psh_i++;
    }

    printf("\n\n");
    return(0);
}
