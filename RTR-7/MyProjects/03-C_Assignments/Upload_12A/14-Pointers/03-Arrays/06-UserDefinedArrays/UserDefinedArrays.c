#include<stdio.h>
#include<stdlib.h> //Contains prototype of malloc and free

#define PSH_INT_SIZE sizeof(int)
#define PSH_FLOAT_SIZE sizeof(float)
#define PSH_DOUBLE_SIZE sizeof(double)
#define PSH_CHAR_SIZE sizeof(char)

int main(void)
{
    // Variable Declarations
    int *psh_ptr_iArray = NULL;
    unsigned int pshIntArrayLength = 0;

    float *psh_ptr_fArray = NULL;
    unsigned int pshFloatArrayLength = 0;

    double *psh_ptr_dArray = NULL;
    unsigned int pshDoubleArrayLength = 0;

    char *psh_ptr_cArray = NULL;
    unsigned int pshCharArrayLength = 0;

    int psh_i;

    // Code
    //*** Integer Array ***
    printf("\n\n");
    printf("Enter the number of elements you want in your integer array: ");
    scanf("%d", &pshIntArrayLength);

    psh_ptr_iArray = (int*)malloc(sizeof(int) * pshIntArrayLength);

    if (psh_ptr_iArray == NULL)
    {
        printf("\n\n");
        printf("MEMORY ALLOCATION FOR INTEGER ARRAY HAS FAILED!!! EXITING NOW ... \n\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("MEMORY ALLOCATION FOR INTEGER ARRAY HAS SUCCEEDED!!! \n\n");
    }

    printf("\n\n");
    printf("Enter %d Integer Elements To fill up the integer array: \n\n", pshIntArrayLength);
    for (psh_i = 0; psh_i < pshIntArrayLength; psh_i++)
    {
        scanf("%d", (psh_ptr_iArray + psh_i));
    }

    // *** Float Array ***
    printf("\n\n");
    printf("Enter the number of elements you want in your Float array: ");
    scanf("%d", &pshFloatArrayLength);

    psh_ptr_fArray = (float*)malloc(PSH_FLOAT_SIZE * pshFloatArrayLength);

    if (psh_ptr_fArray == NULL)
    {
        printf("\n\n");
        printf("MEMORY ALLOCATION FOR FLOATING ARRAY HAS FAILED!!! EXITING NOW ... \n\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("MEMORY ALLOCATION FOR FLOATING-POINT ARRAY HAS SUCCEEDED!!! \n\n");
    }

    printf("\n\n");
    printf("Enter %d floating point Elements To fill up the float array: \n\n", pshFloatArrayLength);
    for (psh_i = 0; psh_i < pshFloatArrayLength; psh_i++)
    {
        scanf("%f", (psh_ptr_fArray + psh_i));
    }

    // *** Double Array ***
    printf("\n\n");
    printf("Enter the number of elements you want in your Double array: ");
    scanf("%d", &pshDoubleArrayLength);

    psh_ptr_dArray = (double*)malloc(PSH_DOUBLE_SIZE * pshDoubleArrayLength);

    if (psh_ptr_dArray == NULL)
    {
        printf("\n\n");
        printf("MEMORY ALLOCATION FOR DOUBLE ARRAY FAILED!!! EXITING NOW ... \n\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("MEMORY ALLOCATION FOR DOUBLE ARRAY HAS SUCCEEDED!!! \n\n");
    }

    printf("\n\n");
    printf("Enter %d double Elements To fill up the double array: \n\n", pshDoubleArrayLength);
    for (psh_i = 0; psh_i < pshDoubleArrayLength; psh_i++)
    {
        scanf("%lf", (psh_ptr_dArray + psh_i));
    }

    // *** Character Array ***
    printf("\n\n");
    printf("Enter the number of elements you want in your character array: ");
    scanf("%d", &pshCharArrayLength);

    psh_ptr_cArray = (char*)malloc(PSH_CHAR_SIZE * pshCharArrayLength);

    if (psh_ptr_cArray == NULL)
    {
        printf("\n\n");
        printf("MEMORY ALLOCATION FOR CHARACTER ARRAY FAILED!!! EXITING NOW ... \n\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("MEMORY ALLOCATION FOR CHARACTER ARRAY HAS SUCCEEDED!!! \n\n");
    }

    printf("\n\n");
    printf("Enter %d character Elements To fill up the character array: \n\n", pshCharArrayLength);
    for (psh_i = 0; psh_i < pshCharArrayLength; psh_i++)
    {
        *(psh_ptr_cArray + psh_i) = getch();
        printf("%c\n", *(psh_ptr_cArray + psh_i));
    }

    // ***** DISPLAY OF ARRAYS ******
    // ******* INTEGER ARRAY *********
    printf("\n\n");
    printf("The integer array entered by you, consisting of %d elements is as follows: \n", pshIntArrayLength);

    for (psh_i = 0; psh_i < pshIntArrayLength; psh_i++)
    {
        printf(" %d\t\t at address : %p\n", *(psh_ptr_iArray + psh_i), (psh_ptr_iArray + psh_i));
    }

    // ******* FLOAT ARRAY *********
    printf("\n\n");
    printf("The float array entered by you, consisting of %d elements is as follows: \n", pshFloatArrayLength);

    for (psh_i = 0; psh_i < pshFloatArrayLength; psh_i++)
    {
        printf(" %f\t\t at address : %p\n", *(psh_ptr_fArray + psh_i), (psh_ptr_fArray + psh_i));
    }

    // ******* DOUBLE ARRAY *********
    printf("\n\n");
    printf("The double array entered by you, consisting of %d elements is as follows: \n", pshDoubleArrayLength);

    for (psh_i = 0; psh_i < pshDoubleArrayLength; psh_i++)
    {
        printf(" %lf\t\t at address : %p\n", *(psh_ptr_dArray + psh_i), (psh_ptr_dArray + psh_i));
    }

    // ******* CHARACTER ARRAY *********
    printf("\n\n");
    printf("The character array entered by you, consisting of %d elements is as follows: \n", pshCharArrayLength);

    for (psh_i = 0; psh_i < pshCharArrayLength; psh_i++)
    {
        printf(" %c\t\t at address : %p\n", *(psh_ptr_cArray + psh_i), (psh_ptr_cArray + psh_i));
    }

    // FREEING MEMORY OCCUPIED BY ARRAYS (IN REVERSE ORDER OF ALLOCATION)

    if (psh_ptr_cArray)
    {
        free(psh_ptr_cArray);
        psh_ptr_cArray = NULL;

        printf("\n\n");
        printf("MEMORY OCCUPIED BY CHARACTER ARRAY HAS BEEN SUCCESSFULLY FREED!!!\n\n");
    }

    if (psh_ptr_dArray)
    {
        free(psh_ptr_dArray);
        psh_ptr_dArray = NULL;

        printf("\n\n");
        printf("MEMORY OCCUPIED BY DOUBLE ARRAY HAS BEEN SUCCESSFULLY FREED!!!\n\n");
    }

    if (psh_ptr_fArray)
    {
        free(psh_ptr_fArray);
        psh_ptr_fArray = NULL;

        printf("\n\n");
        printf("MEMORY OCCUPIED BY FLOAT ARRAY HAS BEEN SUCCESSFULLY FREED!!!\n\n");
    }

    if (psh_ptr_iArray)
    {
        free(psh_ptr_iArray);
        psh_ptr_iArray = NULL;

        printf("\n\n");
        printf("MEMORY OCCUPIED BY INTEGER ARRAY HAS BEEN SUCCESSFULLY FREED!!!\n\n");
    }
    return(0);
}
