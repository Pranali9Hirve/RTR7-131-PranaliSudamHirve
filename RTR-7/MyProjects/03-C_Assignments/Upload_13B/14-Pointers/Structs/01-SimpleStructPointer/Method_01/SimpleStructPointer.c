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
    // Variable declarations
    int psh_i_size;
    int psh_f_size;
    int psh_d_size;
    int psh_struct_PshMyData_size;
    int psh_pointer_to_struct_PshMyData_size;

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
    (*pshPtrData).psh_i = 131;
    (*pshPtrData).psh_f = 131.07f;
    (*pshPtrData).psh_d = 23.6543;

    // Displaying Values of the data members of 'struct PshMyData'
    printf("\n\n");
    printf("data members of 'struct PshMyData' are: \n\n");
    printf("i = %d\n", (*pshPtrData).psh_i);
    printf("f = %f\n", (*pshPtrData).psh_f);
    printf("d = %lf\n", (*pshPtrData).psh_d);

    // Calculating Sizes (In Bytes) of the Data Members of 'struct PshMyData' 
    psh_i_size = sizeof((*pshPtrData).psh_i);
    psh_f_size = sizeof((*pshPtrData).psh_f);
    psh_d_size = sizeof((*pshPtrData).psh_d);

    // Displaying sizes (in bytes) of data members of 'struct PshMyData'
    printf("\n\n");
    printf("SIZES (in bytes) OF DATA MEMBERS OF 'struct PshMyData' ARE: \n\n");
    printf("Size of 'psh_i': %d bytes\n", psh_i_size);
    printf("Size of 'psh_f': %d bytes\n", psh_f_size);
    printf("Size of 'psh_d': %d bytes\n", psh_d_size);

    // Calculating sizes (in bytes) of entire 'struct PshMyData'
    psh_struct_PshMyData_size = sizeof(struct PshMyData);
    psh_pointer_to_struct_PshMyData_size = sizeof(struct PshMyData *);

    // Displaying sizes (in bytes) of entire 'struct PshMyData'
    printf("\n\n");
    printf("Size of 'struct PshMyData': %d bytes\n", psh_struct_PshMyData_size);
    printf("Size of pointer to 'struct PshMyData': %d bytes\n", psh_pointer_to_struct_PshMyData_size);

    if (pshPtrData)
    {
        free(pshPtrData);
        pshPtrData = NULL;
        printf("MEMORY ALLOCATED TO 'struct PshMyData' HAS BEEN SUCCESSFULLY FREED !!!\n\n");
    }

    return(0);
}
