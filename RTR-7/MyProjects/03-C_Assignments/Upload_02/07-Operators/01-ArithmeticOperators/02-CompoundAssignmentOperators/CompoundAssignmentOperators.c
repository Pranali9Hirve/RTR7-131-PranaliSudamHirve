#include<stdio.h>

int main(void)
{
    //variable declarations
    int psh_a;
    int psh_b;
    int psh_x;

    //code
    printf("\n\n");
    printf("Enter A Number : ");
    scanf("%d", &psh_a);

    printf("\n\n");
    printf("Enter Another Number : ");
    scanf("%d", &psh_b);

    printf("\n\n");

    /**
        Since, in all the following 5 Cases, The Operand on the left 'psh_a' Is
        getting repeated immediately on the right (e.g. : psh_a = psh_a + psh_b or psh_a = psh_a - psh_b),
        We Are Using Compound Assignment Operators +=, -=, *=, /= and %=

        Since, 'psh_a' Will Be Assigned The Value Of (psh_a + psh_b) At The Expression (psh_a += psh_b),
        We Must Save The Original Value Of 'psh_a' To Another Variable psh_x)
    */

    psh_x = psh_a;
    psh_a += psh_b; // psh_a = psh_a + psh_b
    printf("Addition Of A = %d And B = %d Gives %d.\n", psh_x, psh_b, psh_a);

    /**
        Value Of 'psh_a' Altered In The Above Expression Is Used Here...
        Since, 'psh_a' Will Be Assigned The Value Of (psh_a - psh_b) At The Expression (psh_a -= psh_b),
        We Must Save The Original Value Of 'psh_a' To Another Variable (psh_x)
    */

    psh_x = psh_a;
    psh_a -= psh_b; // psh_a = psh_a - psh_b
    printf("Subtraction Of A = %d And B = %d Gives %d.\n", psh_x, psh_b, psh_a);

    /**
        Value Of 'psh_a' Altered In The Above Expression Is Used Here...
        Since, 'psh_a' Will Be Assigned The Value Of (psh_a * psh_b) At The Expression (psh_a *= psh_b),
        We Must Save The Original Value Of 'psh_a' To Another Variable (psh_x)
    */

    psh_x = psh_a;
    psh_a *= psh_b; // psh_a = psh_a * psh_b
    printf("Multiplication Of A = %d And B = %d Gives %d.\n", psh_x, psh_b, psh_a);

    /**
        Value Of 'psh_a' Altered In The Above Expression Is Used Here...
        Since, 'psh_a' Will Be Assigned The Value Of (psh_a / psh_b) At The Expression (psh_a /= psh_b),
        We Must Save The Original Value Of 'psh_a' To Another Variable (psh_x)
    */ 

    psh_x = psh_a;
    psh_a /= psh_b; // psh_a = psh_a / psh_b
    printf("Division Of A = %d And B = %d Gives Quotient %d.\n", psh_x, psh_b, psh_a);

    /**
        Value Of 'a' Altered In The Above Expression Is Used Here...
        Since, 'a' Will Be Assigned The Value Of (a % b) At The Expression (a %= b),
        We Must Save The Original Value Of 'a' To Another Variable (x)
    */
    
    psh_x = psh_a;
    psh_a %= psh_b; // psh_a = psh_a % psh_b
    printf("Division Of A = %d And B = %d Gives Remainder %d.\n", psh_x, psh_b, psh_a);

    printf("\n\n");

    return(0);
}
