#include<stdio.h>
int main(void)
{
    // Variable Declarations
    int psh_i;
    char psh_ch;

    // Code
    printf("\n\n");

    printf("Printing Numbers from 1 to 100 for every user input. Exiting the loop ehen user enter character 'Q' or 'q': \n\n");
    printf("Enter Character 'Q' or 'q' To Exit Loop : \n\n");

    for (psh_i = 1; psh_i <= 100; psh_i++)
    {
        printf("\t %d \n", psh_i);
        psh_ch = getch();

        if(psh_ch == 'Q' || psh_ch == 'q')
        {
            break;
        }
    }

    printf("\n\n");
    printf("Exitting Loop....");
    printf("\n\n");

    return(0);
}
