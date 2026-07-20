#include<stdio.h>

// *** GLOBAL SCOPE ***

int main(void)
{
    // function prototypes
    void change_count(void);

    // Variable declarations
    extern int psh_global_count;

    // Code
    printf("\n");
    printf("Value of global_count before change_count() = %d\n", psh_global_count);
    change_count();
    printf("Value of global_count after change_count() = %d\n", psh_global_count);
    printf("\n");
    return(0);
}

// *** GLOBAL SCOPE ***
//  psh_global_count is a glovbal variable
// Since it is declared before change_count(), it can be accessed and used as any ordinary global variable in change_count()
// Since it is declared after main(), it mut be first re-declared in main(),
// as an external global variable by means of the 'extern' keyword and the type of the variable
// Once this is done, it can be used as an ordinary global variable in main as well.

int psh_global_count = 0;

void change_count(void) 
{
    // Code
    psh_global_count = 5;
    printf("Value of global_count after change_count() = %d\n", psh_global_count);
}
