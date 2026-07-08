#include<stdio.h>

int main(void)
{
    // Variable Declarations
    char psh_option, psh_ch='\0';

    // Code
    printf("\n\n");
    printf("Once the infinite loop begins, Enter 'Q' or 'q' to Quit the Infinite while Loop: \n\n");
    printf("Enter 'Y' or 'y' to initiate user controlled Infinite Loop:");
    printf("\n\n");
    psh_option = getch();

    if (psh_option == 'Y' || psh_option == 'y')
    {
        while (1) //Infinite Loop
        {
            printf("In Loop...\n");
            psh_ch = getch();
            if (psh_ch == 'Q' || psh_ch == 'q')
            {
                break; // User Controlled Exitting from Infinite Loop
            }
        }
        printf("\n\n");
        printf("EXITTING USER CONTROLLED INFINITE LOOP...");
        printf("\n\n");
    }
    else
    {
        printf("You must press 'Y' or 'y' to initiate the User Controlled Infinite Loop.... Please Try Again...\n\n");
    }
    return(0);
}
