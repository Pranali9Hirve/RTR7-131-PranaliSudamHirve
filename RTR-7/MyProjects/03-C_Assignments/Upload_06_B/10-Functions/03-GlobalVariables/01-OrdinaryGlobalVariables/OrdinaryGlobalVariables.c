#include<stdio.h>

// *** GLOBAL SCOPE ***

// If not initialized by us, global variables are initialized to their zero values
// with respect to their data types i.e. 0 for int, 0.0 for float and
// double etc.) by default
// But still, for good programming discipline, we shall explicitly initialize our
// Global variable with 0

int psh_global_count = 0;

int main(void)
{
    // function prototypes
    void change_count_one(void);
    void change_count_two(void);
    void change_count_three(void);

    // Code
    printf("\n");

    printf("main(): Value of global count = %d\n", psh_global_count);

    change_count_one();
    change_count_two();
    change_count_three();

    printf("\n");
    return(0);
}

// *** Global Scope ***
void change_count_one(void) 
{
    // Code
    psh_global_count = 100;
    printf("change_count_one(): Value of global count = %d\n", psh_global_count);
}

// *** Global Scope ***
void change_count_two(void) 
{
    // Code
    psh_global_count = psh_global_count + 1;
    printf("change_count_two(): Value of global count = %d\n", psh_global_count);
}

// *** Global Scope ***
void change_count_three(void) 
{
    // Code
    psh_global_count = psh_global_count + 10;
    printf("change_count_three(): Value of global count = %d\n", psh_global_count);
}
