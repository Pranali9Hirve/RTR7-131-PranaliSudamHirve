#include<stdio.h>

int main(void)
{
    // Variable Declarations
    char psh_option, psh_ch='\0';

    // Code
    printf("\n\n");
    printf("Once the infinite loop begins, Enter 'Q' or 'q' to Quit the Infinite For Loop: \n\n");
    printf("Enter 'Y' or 'y' to initiate user controlled Infinite Loop:");
    printf("\n\n");
    psh_option = getch();

    if (psh_option == 'Y' || psh_option == 'y')
    {
        for(;;) //Infinite Loop
        {
            printf("In Loop...\n");
            psh_ch = getch();
            if (psh_ch == 'Q' || psh_ch == 'q')
            {
                break; // User Controlled Exitting from Infinite Loop
            }
        }
    }
    printf("\n\n");
    printf("EXITTING USER CONTROLLED INFINITE LOOP...");
    printf("\n\n");

    return(0);
}
