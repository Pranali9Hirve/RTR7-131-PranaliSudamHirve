#include<stdio.h>

int main(void)
{
    // Code 
    printf("\n\n");

    printf("Going On To Next Line... Using \\n Escape Sequence\n\n");
    printf("Demonstrating \t Horizontal \t Tab \t Using \t \\t Escape Sequence !!!\n\n");
    printf("\"This Is A Double Quoted Output\" Done Using \\\" \\\" Escape Sequence\n\n");
    printf("\'This Is A Single Quoted Output\' Done Using \\\' \\\' Escape Sequence\n\n");
    printf("BACKSPACE Turned To BACKSPACE\b Using Escape Sequence \\b\n\n");
    printf("\rDemonstrating Carriage Return Using \\r Escape Sequence\n\n");
    printf("Demonstrating \rCarriage Return Using \\r Escape Sequence\n\n");
    printf("Demonstrating Carriage \r Return Using \\r Escape Sequence\n\n");
    printf("Demonstrating \x41 Using \\xhh Escape Sequence\n\n");
    // 0x41 is the Hexadecimal Code for letter 'A'.
    // 'xhh' is the placeholder for 'x' followed by 2 digits (hh), altogether forming a Hexadecimal Number
    printf("Demonstrating \102 Using \\ooo Escape Sequence\n\n");
    // 102 is the Otal Code for letter 'B'.
    // 'ooo' is the placeholder for 3 digits forming An Octal Number.
    return(0);
}
