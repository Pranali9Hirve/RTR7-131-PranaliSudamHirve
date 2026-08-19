#include<stdio.h>

// MACRO CONSTANT USED AS ARRAY SIZE IN SUBSCRIPT AND AS ARRAY LENGTH
// HENCE, THIS PROGRAM ARRAYS SIZES CAN BE SIMPLY CHANGED BY CHANGING THESE
// FOLLOWING 3 GLOBAL MACRO CONSTANT VALUES, BEFORE COMPILING, LINKING AND EXECUTING THE PROGRAM !!!

#define PSH_INT_ARRAY_NUM_ELEMENTS 5
#define PSH_FLOAT_ARRAY_NUM_ELEMENTS 3
#define PSH_CHAR_ARRAY_NUM_ELEMENTS 15

int main(void)
{
    // Variable declarations
    int psh_iArray[PSH_INT_ARRAY_NUM_ELEMENTS];
    float psh_fArray[PSH_FLOAT_ARRAY_NUM_ELEMENTS];
    char psh_cArray[PSH_CHAR_ARRAY_NUM_ELEMENTS];
    int psh_i, psh_num;

    // Code 
    // ARRAY ELEMENTS INPUT

    printf("\n\n");
    printf("Enter Elements For 'Integer' Array :\n");

    for (psh_i = 0; psh_i < PSH_INT_ARRAY_NUM_ELEMENTS; psh_i++)
    {
        scanf("%d", &psh_iArray[psh_i]);
    }

    printf("\n\n");
    printf("Enter Elements For 'Floating-Point' Array :\n");

    for (psh_i = 0; psh_i < PSH_FLOAT_ARRAY_NUM_ELEMENTS; psh_i++)
    {
        scanf("%f", &psh_fArray[psh_i]);
    }

    printf("\n\n");
    printf("Enter Elements For 'Character' Array :\n");

    for (psh_i = 0; psh_i < PSH_CHAR_ARRAY_NUM_ELEMENTS; psh_i++)
    {
        psh_cArray[psh_i] = getch();
        printf("%c\n", psh_cArray[psh_i]);
    }

    // ********** ARRAY ELEMENTS OUTPUT **********

    printf("\n\n");
    printf("Integer Array Entered By You :\n\n");

    for (psh_i = 0; psh_i < PSH_INT_ARRAY_NUM_ELEMENTS; psh_i++)
    {
        printf("%d\n", psh_iArray[psh_i]);
    }

    printf("\n\n");
    printf("Floating-Point Array Entered By You :\n\n");

    for (psh_i = 0; psh_i < PSH_FLOAT_ARRAY_NUM_ELEMENTS; psh_i++)
    {
        printf("%f\n", psh_fArray[psh_i]);
    }

    printf("\n\n");
    printf("Character Array Entered By You :\n\n");

    for (psh_i = 0; psh_i < PSH_CHAR_ARRAY_NUM_ELEMENTS; psh_i++)
    {
        printf("%c\n", psh_cArray[psh_i]);
    }

    printf("\n\n");

    return 0;
}
