#include<stdio.h>
#include<stdlib.h>

// DEFINING STRUCT
struct PshMyData
{
    int *psh_ptr_i;
    int psh_i;

    float *psh_ptr_f;
    float psh_f;

    double *psh_ptr_d;
    double psh_d;
};

int main(void)
{
    // Variable Declarations
    struct PshMyData *psh_ptr_data = NULL;

    // Code
    psh_ptr_data = (struct PshMyData *)malloc(sizeof(struct PshMyData));

    if (psh_ptr_data == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY TO 'struct PshMyData' !!! EXITING NOW...\n\n");
        exit(0);
    }
    else
    {
        printf("SUCCESSFULLY ALLOCATED MEMORY TO 'struct PshMyData' !!! \n\n");
    }

    (*psh_ptr_data).psh_i = 131;
    (*psh_ptr_data).psh_ptr_i = &(*psh_ptr_data).psh_i;

    (*psh_ptr_data).psh_f = 13.11f;
    (*psh_ptr_data).psh_ptr_f = &(*psh_ptr_data).psh_f;

    (*psh_ptr_data).psh_d = 11.11;
    (*psh_ptr_data).psh_ptr_d = &(*psh_ptr_data).psh_d;

    printf("\n\n");
    printf("psh_i = %d\n", *((*psh_ptr_data).psh_ptr_i));
    printf("Address of psh_i = %p\n", (*psh_ptr_data).psh_ptr_i);

    printf("\n\n");
    printf("psh_f = %f\n", *((*psh_ptr_data).psh_ptr_f));
    printf("Address of psh_f = %p\n", (*psh_ptr_data).psh_ptr_f);

    printf("\n\n");
    printf("psh_d = %lf\n", *((*psh_ptr_data).psh_ptr_d));
    printf("Address of psh_d = %p\n", (*psh_ptr_data).psh_ptr_d);

    if (psh_ptr_data)
    {
        free(psh_ptr_data);
        psh_ptr_data = NULL;
        printf("MEMORY ALLOCATED TO 'struct PshMyData' HAS BEEN SUCCESSFULLY FREED !!!\n\n");
    }

    return(0);
}
