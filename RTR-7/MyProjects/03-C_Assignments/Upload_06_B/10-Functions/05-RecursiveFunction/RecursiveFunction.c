#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    // Variable declaration
    unsigned int psh_num;

    // Function Prototype
    void recursive(unsigned int);

    // Code
    printf("\n\n");
    printf("Enter Any Number : ");
    scanf("%u", &psh_num);

    printf("\n\n");
    printf("Output Of Recursive Function :\n\n");

    recursive(psh_num);

    printf("\n\n");

    return 0;
}

void recursive(unsigned int psh_n)
{
    // Code
    printf("n = %u\n", psh_n);

    if (psh_n > 0)
    {
        recursive(psh_n - 1);
    }
}
