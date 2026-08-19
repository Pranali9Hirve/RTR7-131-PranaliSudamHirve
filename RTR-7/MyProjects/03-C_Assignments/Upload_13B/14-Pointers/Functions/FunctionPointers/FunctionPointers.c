#include<stdio.h>

int main(void)
{
    // Function Declarations
    int PshAddIntegers(int, int);
    int PshSubtractIntegers(int, int);
    float PshAddFloats(float, float);

    // Variable Declaration
    typedef int (*PshAddIntsFnPtr) (int, int);
    PshAddIntsFnPtr pshPtrAddTwoIntegers = NULL;
    PshAddIntsFnPtr pshPtrFunc = NULL;

    typedef float (*PshAddFloatsFnPtr) (float, float);
    PshAddFloatsFnPtr pshPtrAddTwoFloats = NULL;

    int pshIAnswer = 0;
    float pshFAnswer = 0.0f;

    // Code
    pshPtrAddTwoIntegers = PshAddIntegers;
    pshIAnswer = pshPtrAddTwoIntegers(9, 131);
    printf("\n\n");
    printf("Sum of Integers = %d\n\n", pshIAnswer);

    pshPtrFunc = PshSubtractIntegers;
    pshIAnswer = pshPtrFunc(9, 131);
    printf("\n\n");
    printf("Subtraction of Integers = %d\n\n", pshIAnswer);

    pshPtrAddTwoFloats = PshAddFloats;
    pshFAnswer = pshPtrAddTwoFloats(9.43f, 3.1f);
    printf("\n\n");
    printf("Sum of Floating point numbers = %f\n\n", pshFAnswer);

    return(0);
}

int PshAddIntegers(int psh_a, int psh_b)
{
    // Variable Declarations
    int psh_c;

    // Code
    psh_c = psh_a + psh_b;
    return(psh_c);
}

int PshSubtractIntegers(int psh_a, int psh_b)
{
    // Variable Declarations
    int psh_c;

    // Code
    if (psh_a > psh_b)
        psh_c = psh_a - psh_b;
    else
        psh_c = psh_b - psh_a;

    return(psh_c);
}

float PshAddFloats(float psh_fa, float psh_fb)
{
    // Variable Declarations
    float psh_fc;

    // Code
    psh_fc = psh_fa + psh_fb;

    return(psh_fc);
}
