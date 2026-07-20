#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    // Function prototype or declaration
    int MyAddition(int, int);

    // Variable declarations
    int psh_r;
    int psh_num_01, psh_num_02;
    int psh_num_03, psh_num_04;

    // Code
    psh_num_01 = 10;
    psh_num_02 = 20;
    psh_num_03 = 30;
    psh_num_04 = 40;

    // Return value of MyAddition is sent as a parameter to another call to MyAddition()
    psh_r = MyAddition(MyAddition(psh_num_01, psh_num_02), MyAddition(psh_num_03, psh_num_04));

    printf("\n\n");
    printf("%d + %d + %d + %d = %d\n", psh_num_01, psh_num_02, psh_num_03, psh_num_04, psh_r);
    printf("\n\n");

    return 0;
}

// *** Function definition of MyAddition ***
int MyAddition(int psh_a, int psh_b)
{
    // variable declaration
    int psh_sum;

    // Code
    psh_sum = psh_a + psh_b;

    return(psh_sum);
}
