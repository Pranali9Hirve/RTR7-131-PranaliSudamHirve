#include<stdio.h>
#include<stdarg.h>

#define PSH_NUM_TO_BE_FOUND 131
#define PSH_NUM_ELEMENTS 10

int main(void)
{
    // Function Prototype
    void FindNumber(int, int, ...);

    // Code
    printf("\n\n");

    FindNumber(PSH_NUM_TO_BE_FOUND, PSH_NUM_ELEMENTS, 131, 5, 9, 2, 131, 6, 9, 131, 1, 3);

    return(0);
}

void FindNumber(int psh_num_to_be_found, int psh_num, ...) //Variadic Function
{
    // Function Prototype
    int va_FindNumber(int, int, va_list);

    // Variable Declaration
    int pshCount = 0;
    int psh_n;

    va_list psh_number_list;

    // Code
    va_start(psh_number_list, psh_num);

    pshCount = va_FindNumber(psh_num_to_be_found, psh_num, psh_number_list);

    if (pshCount == 0)
    {
        printf("Number %d Could not be found !!!\n\n", psh_num_to_be_found);
    }
    else
    {
        printf("Number %d found %d times !!!\n\n", psh_num_to_be_found, pshCount);
    }

    va_end(psh_number_list);
}

int va_FindNumber(int psh_num_to_be_found, int psh_num, va_list psh_list)
{
    // Variable Declarations
    int psh_count_of_num = 0;
    int psh_n;

    // Code
    while(psh_num)
    {
        psh_n = va_arg(psh_list, int);

        if (psh_n == psh_num_to_be_found)
        {
            psh_count_of_num++;
        }
        psh_num--;
    }

    return(psh_count_of_num);
}
