#include<stdio.h>

// *** GLOBAL SCOPE ***

int main(void)
{
    // *** Local Scope of main() begins ***

    // Variable Declarations
    // 'a' is a Local Varible. It is local to main() only

    int psh_a = 5;

    // Function Prototypes
    void change_count(void);

    // Code
    printf("\n");
    printf("A = %d\n\n", psh_a);

    // local_count is initialized to 0
    // local_count = local_count + 1 = 0 + 1 = 1
    change_count();
    return(0);

    // *** Local Scope of main() Ends ***
}

// *** Global Scope ***

void change_count(void)
{
    // *** Local Scope of change_count() begins ***

    // Variable Declarations
    // 'psh_local_count' is a Local Varible. It is local to change_count() only.

    int psh_local_count = 0;

    // Code
    psh_local_count = psh_local_count + 1;

    printf("Local count = %d\n", psh_local_count);

    // *** Local Scope of change_count() ends ***
}
