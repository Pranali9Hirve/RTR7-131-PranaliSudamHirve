#include<stdio.h>
#include<string.h>

#define PSH_INT_ARRAY_SIZE 10
#define PSH_FLOAT_ARRAY_SIZE 5
#define PSH_CHAR_ARRAY_SIZE 26

#define PSH_NUM_STRINGS 10
#define PSH_MAX_CHARACTERS_PER_STRING 20

#define PSH_ALPHABET_BEGINNING 65 // 'A'

struct PshDataOne
{
    int pshIArray[PSH_INT_ARRAY_SIZE];
    float pshFArray[PSH_FLOAT_ARRAY_SIZE];
};

struct PshDataTwo
{
    char pshCArray[PSH_CHAR_ARRAY_SIZE];
    char pshStrArray[PSH_NUM_STRINGS][PSH_MAX_CHARACTERS_PER_STRING];
};

int main(void)
{
    // Variable Declarations
    struct PshDataOne pshDataOne;
    struct PshDataTwo pshDataTwo;
    int psh_i;

    // Code
    // *** PIECE-MEAL ASSIGNMENT (HARD CODED) ***
    pshDataOne.pshFArray[0] = 0.1f;
    pshDataOne.pshFArray[1] = 1.2f;
    pshDataOne.pshFArray[2] = 2.3f;
    pshDataOne.pshFArray[3] = 3.4f;
    pshDataOne.pshFArray[4] = 5.6f;

    // *** LOOP ASSIGNMENT (USER INPUT)
    printf("\n\n");
    printf("Enter %d Integers : \n\n", PSH_INT_ARRAY_SIZE);
    for (psh_i = 0; psh_i < PSH_INT_ARRAY_SIZE; psh_i++)
    {
        scanf("%d", &pshDataOne.pshIArray[psh_i]);
    }

    // *** LOOP ASSIGNMENT (HARD CODED)
    printf("\n\n");
    for (psh_i = 0; psh_i < PSH_CHAR_ARRAY_SIZE; psh_i++)
    {
        pshDataTwo.pshCArray[psh_i] = (char) (psh_i + PSH_ALPHABET_BEGINNING);
    }

    // *** PIECE-MEAL ASSIGNMENT (HARD CODED) ***
    strcpy(pshDataTwo.pshStrArray[0], "India");
    strcpy(pshDataTwo.pshStrArray[1], "is");
    strcpy(pshDataTwo.pshStrArray[2], "my");
    strcpy(pshDataTwo.pshStrArray[3], "Country");
    strcpy(pshDataTwo.pshStrArray[4], "All");
    strcpy(pshDataTwo.pshStrArray[5], "Indians");
    strcpy(pshDataTwo.pshStrArray[6], "are");
    strcpy(pshDataTwo.pshStrArray[7], "My");
    strcpy(pshDataTwo.pshStrArray[8], "Brothers and");
    strcpy(pshDataTwo.pshStrArray[9], "Sisters");

    // *** Displaying data members of 'struct PshDataOne' and their values ***
    printf("\n\n");
    printf("Members of 'struct PshDataOne' alongwith their assigned values are : \n\n");
    printf("Integer array (pshDataOne.pshIArray[]): \n\n");
    for (psh_i = 0; psh_i < PSH_INT_ARRAY_SIZE; psh_i++)
    {
        printf("pshDataOne.pshIArray[%d] = %d\n", psh_i, pshDataOne.pshIArray[psh_i]);
    }

    printf("\n\n");
    printf("Floating point array (pshDataOne.pshFArray[]): \n\n");
    for (psh_i = 0; psh_i < PSH_FLOAT_ARRAY_SIZE; psh_i++)
    {
        printf("pshDataOne.pshFArray[%d] = %f\n", psh_i, pshDataOne.pshFArray[psh_i]);
    }

     // *** Displaying data members of 'struct PshDataTwo' and their values ***
    printf("\n\n");
    printf("Members of 'struct PshDataTwo' alongwith their assigned values are : \n\n");
    printf("Character array (pshDataTwo.pshCArray[]): \n\n");
    for (psh_i = 0; psh_i < PSH_CHAR_ARRAY_SIZE; psh_i++)
    {
        printf("pshDataTwo.pshCArray[%d] = %c\n", psh_i, pshDataTwo.pshCArray[psh_i]);
    }

    printf("\n\n");
    printf("String array (pshDataTwo.pshStrArray[]): \n\n");
    for (psh_i = 0; psh_i < PSH_NUM_STRINGS; psh_i++)
    {
        printf("%s ", pshDataTwo.pshStrArray[psh_i]);
    }

    printf("\n\n");

    return(0);
}
