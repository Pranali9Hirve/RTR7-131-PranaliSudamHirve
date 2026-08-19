#include<stdio.h>

int main(void)
{
    // Variable Declarations
    int psh_iArray[] = {12, 24, 36, 48, 60, 72, 84, 96, 108, 120};
    float psh_fArray[] = {9.8f, 8.7f, 7.6f, 6.5f, 5.4f};
    double psh_dArray[] = {1.222222, 2.333333, 3.444444};
    char psh_cArray[] = {'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P', '\0'};

    // Code
    printf("\n\n");
    printf("Integer Array Elements and The Addresses They Occupy Are As Follows: \n\n");
    printf("psh_iArray[0] = %d \t At Address: %p\n", *(psh_iArray + 0), (psh_iArray + 0));
    printf("psh_iArray[1] = %d \t At Address: %p\n", *(psh_iArray + 1), (psh_iArray + 1));
    printf("psh_iArray[2] = %d \t At Address: %p\n", *(psh_iArray + 2), (psh_iArray + 2));
    printf("psh_iArray[3] = %d \t At Address: %p\n", *(psh_iArray + 3), (psh_iArray + 3));
    printf("psh_iArray[4] = %d \t At Address: %p\n", *(psh_iArray + 4), (psh_iArray + 4));
    printf("psh_iArray[5] = %d \t At Address: %p\n", *(psh_iArray + 5), (psh_iArray + 5));
    printf("psh_iArray[6] = %d \t At Address: %p\n", *(psh_iArray + 6), (psh_iArray + 6));
    printf("psh_iArray[7] = %d \t At Address: %p\n", *(psh_iArray + 7), (psh_iArray + 7));
    printf("psh_iArray[8] = %d \t At Address: %p\n", *(psh_iArray + 8), (psh_iArray + 8));
    printf("psh_iArray[9] = %d \t At Address: %p\n", *(psh_iArray + 9), (psh_iArray + 9));

    printf("\n\n");
    printf("Float Array Elements and The Addresses They Occupy Are As Follows: \n\n");
    printf("psh_fArray[0] = %f \t At Address: %p\n", *(psh_fArray + 0), (psh_fArray + 0));
    printf("psh_fArray[1] = %f \t At Address: %p\n", *(psh_fArray + 1), (psh_fArray + 1));
    printf("psh_fArray[2] = %f \t At Address: %p\n", *(psh_fArray + 2), (psh_fArray + 2));
    printf("psh_fArray[3] = %f \t At Address: %p\n", *(psh_fArray + 3), (psh_fArray + 3));
    printf("psh_fArray[4] = %f \t At Address: %p\n", *(psh_fArray + 4), (psh_fArray + 4));
    
    printf("\n\n");
    printf("Double Array Elements and The Addresses They Occupy Are As Follows: \n\n");
    printf("psh_dArray[0] = %lf \t At Address: %p\n", *(psh_dArray + 0), (psh_dArray + 0));
    printf("psh_dArray[1] = %lf \t At Address: %p\n", *(psh_dArray + 1), (psh_dArray + 1));
    printf("psh_dArray[2] = %lf \t At Address: %p\n", *(psh_dArray + 2), (psh_dArray + 2));

    printf("\n\n");
    printf("Character Array Elements and The Addresses They Occupy Are As Follows: \n\n");
    printf("psh_cArray[0] = %c \t At Address: %p\n", *(psh_cArray + 0), (psh_cArray + 0));
    printf("psh_cArray[1] = %c \t At Address: %p\n", *(psh_cArray + 1), (psh_cArray + 1));
    printf("psh_cArray[2] = %c \t At Address: %p\n", *(psh_cArray + 2), (psh_cArray + 2));
    printf("psh_cArray[3] = %c \t At Address: %p\n", *(psh_cArray + 3), (psh_cArray + 3));
    printf("psh_cArray[4] = %c \t At Address: %p\n", *(psh_cArray + 4), (psh_cArray + 4));
    printf("psh_cArray[5] = %c \t At Address: %p\n", *(psh_cArray + 5), (psh_cArray + 5));
    printf("psh_cArray[6] = %c \t At Address: %p\n", *(psh_cArray + 6), (psh_cArray + 6));
    printf("psh_cArray[7] = %c \t At Address: %p\n", *(psh_cArray + 7), (psh_cArray + 7));
    printf("psh_cArray[8] = %c \t At Address: %p\n", *(psh_cArray + 8), (psh_cArray + 8));
    printf("psh_cArray[9] = %c \t At Address: %p\n", *(psh_cArray + 9), (psh_cArray + 9));
    printf("psh_cArray[10] = %c \t At Address: %p\n", *(psh_cArray + 10), (psh_cArray + 10));
    printf("psh_cArray[11] = %c \t At Address: %p\n", *(psh_cArray + 11), (psh_cArray + 11));
    printf("psh_cArray[12] = %c \t At Address: %p\n", *(psh_cArray + 12), (psh_cArray + 12));
    printf("psh_cArray[13] = %c \t At Address: %p\n", *(psh_cArray + 13), (psh_cArray + 13));

    return(0);
}
