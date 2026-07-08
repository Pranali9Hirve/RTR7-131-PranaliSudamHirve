#include<stdio.h>

int main(void)
{
    // Variable Declarations
    char psh_option, psh_ch='\0';

    // Code
    printf("\n\n");
    printf("Once the infinite loop begins, Enter 'Q' or 'q' to Quit the Infinite do-while Loop: \n\n");
    
    do
    {
        do
        {
            printf("\n");
            printf("In Loop...\n");
            psh_ch = getch(); // Control flow waits for character input...
        }while (psh_ch == 'Q' || psh_ch == 'q'); 
        printf("\n\n");
        printf("EXITTING USER CONTROLLED INFINITE LOOP...");
        printf("\n\n");
        printf("DO YOU WANT TO BEGIN USER CONTROLLED INFINITE LOOP AGAIN?...(Y/y - Yes, Any Other key - No) :");
        psh_option = getch();
    }while(psh_option == 'Y' || psh_option == 'y');
    return(0);
}
