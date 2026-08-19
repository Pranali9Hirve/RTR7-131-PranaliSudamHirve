#include<stdio.h>

//Defining STRUCT ...
struct PshRectangle 
{
    struct PshMyPoint
    {
        int psh_x;
        int psh_y;
    } PshPoint01, PshPoint02;
} pshRect = { {2, 3}, {5, 6}};

int main(void)
{
    // Variable Declarations
    int pshLength, pshBreadth, pshArea;

    // Code

    pshLength = pshRect.PshPoint02.psh_y - pshRect.PshPoint01.psh_y;
    if (pshLength < 0)
    {
        pshLength = pshLength * -1;
    }

    pshBreadth = pshRect.PshPoint02.psh_x - pshRect.PshPoint01.psh_x;
    if (pshBreadth < 0)
    {
        pshBreadth = pshBreadth * -1;
    }

    pshArea = pshLength * pshBreadth;

    printf("\n\n");
    printf("Lenght of Rectangle = %d\n\n", pshLength);
    printf("Breadth of Rectangle = %d\n\n", pshBreadth);
    printf("Area of Rectangle = %d\n\n", pshArea);

    return(0);
}
