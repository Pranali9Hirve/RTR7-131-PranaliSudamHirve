#include<stdio.h>

// *** GLOBAL SCOPE ***

int psh_global_count = 0;

int main(void)
{
    // function prototypes
    void change_count(void);
    void change_count_one(void);   // Function defines in File_01.c
    void change_count_two(void);   // Function defines in File_02.c

    // Code
    printf("\n");

    change_count();
    change_count_one();
    change_count_two();
    
    return(0);
}

void change_count(void) 
{
    // Code
    psh_global_count = psh_global_count + 1;
    printf("change_count(): Value of global count = %d\n", psh_global_count);
}
