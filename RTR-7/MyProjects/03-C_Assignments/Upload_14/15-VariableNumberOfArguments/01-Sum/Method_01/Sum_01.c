#include<stdio.h>
#include<stdarg.h>

int main(void)
{
    // Function Prototypes
    int PshCalculateSum(int, ...);

    // Variable Declarations
    int pshAnswer;

    // Code
    printf("\n\n");

   // pshAnswer = PshCalculateSum(10, 20, 30, 40, 50, 60, 70, 80, 90);
    pshAnswer = PshCalculateSum(5, 10, 20, 30, 40, 50);
    printf("Answer = %d\n\n", pshAnswer);

    pshAnswer = PshCalculateSum(10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    printf("Answer = %d\n\n", pshAnswer);

    pshAnswer = PshCalculateSum(0);
    printf("Answer = %d\n\n", pshAnswer);

    return(0);
}

int PshCalculateSum(int num, ...) // VARIADIC FUNCTION
{
    // VARIABLE DECLARATION
    int pshSumTotal = 0;
    int psh_n;

    va_list pshNumberList;

    // Code
    va_start(pshNumberList, num);

    while (num)
    {
        psh_n = va_arg(pshNumberList, int);
        pshSumTotal = pshSumTotal + psh_n;
        num--;
    }
    va_end(pshNumberList);
    return(pshSumTotal);
}
