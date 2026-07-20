
// *** GLOBAL SCOPE ***
// psh_global_count is a global variable declared in source code file MultipleFiles.c
// To access it in this file, it must first be re-declared as an external variable
// in the local scope of this file along with the 'extern' keyword and its proper data type
// Then, it can be used as any ordinary global variable throughout this file as well 
// Here, re-declaring 'psh_global_count' as a local variable using 'extern' keyword within change_count_two()

# include<stdio.h>

void change_count_two(void) 
{
    // Code
    extern int psh_global_count;
    psh_global_count = psh_global_count + 1;
    printf("change_count_two(): Value of global count in File_02 = %d\n", psh_global_count);
}
