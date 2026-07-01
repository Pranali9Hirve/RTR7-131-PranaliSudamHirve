#include <stdio.h>

int main(void)
{
    // Function Prototype
    void PrintBinaryFormOfNumber(unsigned int);

    // Variable declarations
    unsigned int psh_a;
    unsigned int psh_result;

    // Code
    printf("\n\n");
    printf("Enter An Integer = ");
    scanf("%u", &psh_a);

    printf("\n\n\n\n");
    psh_result = ~psh_a;
    printf("Bitwise COMPLEMENTING Of \n psh_a = %d (Decimal) gives Result = %d (Decimal).\n\n", psh_a, psh_result);

    PrintBinaryFormOfNumber(psh_a);
    PrintBinaryFormOfNumber(psh_result);

    return 0;
    }

/*
 * BEGINNERS TO C PROGRAMMING LANGUAGE:
 * PLEASE IGNORE THE CODE OF THE FOLLOWING FUNCTION
 * 'PrintBinaryFormOfNumber()'
 *
 * YOU MAY COME BACK TO THIS CODE AND WILL UNDERSTAND IT
 * MUCH BETTER AFTER YOU HAVE COVERED ARRAYS, LOOPS AND FUNCTIONS.
 *
 * THE ONLY OBJECTIVE OF WRITING THIS FUNCTION WAS TO OBTAIN
 * THE BINARY REPRESENTATION OF DECIMAL INTEGERS SO THAT
 * BITWISE AND-ing, OR-ing, COMPLEMENT AND BIT-SHIFTING
 * COULD BE UNDERSTOOD WITH GREAT EASE.
 */

void PrintBinaryFormOfNumber(unsigned int psh_decimal_number)
{
    // Variable declarations
    unsigned int psh_quotient;
    unsigned int psh_remainder;
    unsigned int psh_num;
    unsigned int psh_binary_array[8];
    int psh_i;

    // Initialize array with zeros
    for (psh_i = 0; psh_i < 8; psh_i++)
    {
        psh_binary_array[psh_i] = 0;
    }

    printf(
        "The Binary Form Of The Decimal Integer %d Is\t=\t",
        psh_decimal_number
    );

    psh_num = psh_decimal_number;
    psh_i = 7;

    while (psh_num != 0 && psh_i >= 0)
    {
        psh_quotient = psh_num / 2;
        psh_remainder = psh_num % 2;

        psh_binary_array[psh_i] = psh_remainder;

        psh_num = psh_quotient;
        psh_i--;
    }

    for (psh_i = 0; psh_i < 8; psh_i++)
    {
        printf("%u", psh_binary_array[psh_i]);
    }

    printf("\n\n");
}
