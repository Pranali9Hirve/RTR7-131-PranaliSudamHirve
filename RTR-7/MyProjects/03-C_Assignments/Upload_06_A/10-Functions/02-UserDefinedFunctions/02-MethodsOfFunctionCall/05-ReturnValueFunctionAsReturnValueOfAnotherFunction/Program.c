#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    // Function prototype or declarations
    int MyAddition(int, int);

    // Variable declarations
    int psh_num_01, psh_num_02;

    // Code
    psh_num_01 = 10;
    psh_num_02 = 20;

    printf("\n\n");
    printf("%d + %d = %d\n", psh_num_01, psh_num_02, MyAddition(psh_num_01, psh_num_02));
    printf("\n\n");

    return 0;
}

// *** Function Definition Of MyAddition() ***
int MyAddition(int psh_a, int psh_b)
{
    // Function prototype or declarations
    int Add(int, int);

    // Return value of Add() is returned by MyAddition()
    return Add(psh_a, psh_b);
}

// *** Function Definition Of Add() ***
int Add(int psh_x, int psh_y)
{
    return (psh_x + psh_y);
}
