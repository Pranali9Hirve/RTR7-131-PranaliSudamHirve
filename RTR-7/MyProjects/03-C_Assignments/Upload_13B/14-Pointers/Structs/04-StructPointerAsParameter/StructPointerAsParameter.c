#include<stdio.h>
#include <stdlib.h>

// DEFINING STRUCT
struct PshMyData
{
    int psh_i;
    float psh_f;
    double psh_d;
};

int main(void)
{
    // Function Prototype
    void PshChangeValues(struct PshMyData *);

    // Variable Declarations
    struct PshMyData *pshPtrData = NULL;

    // Code
    printf("\n\n");
    pshPtrData = (struct PshMyData *)malloc(sizeof(struct PshMyData));

    if (pshPtrData == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY TO 'struct PshMyData' !!! EXITING NOW...\n\n");
        exit(0);
    }
    else
    {
        printf("SUCCESSFULLY ALLOCATED MEMORY TO 'struct PshMyData' !!! \n\n");
    }

    // Assigning data values to the data members of 'struct PshMyData'
    pshPtrData->psh_i = 131;
    pshPtrData->psh_f = 131.07f;
    pshPtrData->psh_d = 23.6543;

    // Displaying Values of the data members of 'struct PshMyData'
    printf("\n\n");
    printf("data members of 'struct PshMyData' are: \n\n");
    printf("psh_i = %d\n", pshPtrData->psh_i);
    printf("psh_f = %f\n", pshPtrData->psh_f);
    printf("psh_d = %lf\n", pshPtrData->psh_d);

    PshChangeValues(pshPtrData);

    // Displaying Values of the data members of 'struct PshMyData'
    printf("\n\n");
    printf("data members of 'struct PshMyData' are: \n\n");
    printf("psh_i = %d\n", pshPtrData->psh_i);
    printf("psh_f = %f\n", pshPtrData->psh_f);
    printf("psh_d = %lf\n", pshPtrData->psh_d);

    if (pshPtrData)
    {
        free(pshPtrData);
        pshPtrData = NULL;
        printf("MEMORY ALLOCATED TO 'struct PshMyData' HAS BEEN SUCCESSFULLY FREED !!!\n\n");
    }

    return(0);
}

void PshChangeValues(struct PshMyData *pshPtrParamData)
{
    // Code
    pshPtrParamData->psh_i = 312;
    pshPtrParamData->psh_f = 3.14f;
    pshPtrParamData->psh_d = 23.4567;

    // Can also do this
    // (*pshPtrParamData).psh_i = 32;
    // (*pshPtrParamData).psh_f = 6.14f;
    // (*pshPtrParamData).psh_d = 89.543;
}
