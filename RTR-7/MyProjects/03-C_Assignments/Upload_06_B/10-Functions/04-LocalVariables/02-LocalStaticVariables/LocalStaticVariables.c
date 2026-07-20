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

    // Since 'local_count' is a local static variable of change_count(),
    // it WILL retain its value from the previous call to change_count().
    // So local_count is 1.
    // local_count = local_count + 1 = 1 + 1 = 2
    change_count();

    // Since 'local_count' is a local static variable of change_count(),
    // it WILL retain its value from the previous call to change_count().
    // So local_count is 2.
    // local_count = local_count + 1 = 2 + 1 = 3
    change_count();

    return(0);
    // *** Local Scope of main() ends ***
}

// *** GLOBAL SCOPE ***

void change_count(void)
{
    // *** LOCAL SCOPE OF change_count() begins ***

    // Variable declaration
    // 'psh_local_count' is a local static variable.
    // It is local to change_count() only.
    // It will retain its value between calls to change_count().

    static int psh_local_count = 0;

    // Code
    psh_local_count = psh_local_count + 1;
    printf("Local Count = %d\n", psh_local_count);

    // *** LOCAL SCOPE OF change_count() ends ***
}
