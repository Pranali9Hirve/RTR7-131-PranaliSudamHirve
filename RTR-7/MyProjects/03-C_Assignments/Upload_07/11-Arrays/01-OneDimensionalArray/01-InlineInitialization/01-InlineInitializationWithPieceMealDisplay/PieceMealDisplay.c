#include<stdio.h>
int main(void)
{
    // Variable Declarations
    int psh_iArray[] = {9, 30, 6, 12, 95, 20, 23, 2, 45};
    int psh_int_size;
    int psh_iArray_size;
    int psh_iArray_num_elements;

    float psh_fArray[] = {1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f, 7.8f, 8.9f};
    int psh_float_size;
    int psh_fArray_size;
    int psh_fArray_num_elements;

    char psh_cArray[] = {'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P', '\0'};
    
    int psh_char_size;
    int psh_cArray_size;
    int psh_cArray_num_elements;

    // ************ iArray[] **************
    printf("\n\n");
    printf("In-line Initialization And Piece-meal Display Of Elements Of Array 'iArray[]':\n\n");

    printf("psh_iArray[0] (1st Element) = %d\n", psh_iArray[0]);
    printf("psh_iArray[1] (2nd Element) = %d\n", psh_iArray[1]);
    printf("psh_iArray[2] (3rd Element) = %d\n", psh_iArray[2]);
    printf("psh_iArray[3] (4th Element) = %d\n", psh_iArray[3]);
    printf("psh_iArray[4] (5th Element) = %d\n", psh_iArray[4]);
    printf("psh_iArray[5] (6th Element) = %d\n", psh_iArray[5]);
    printf("psh_iArray[6] (7th Element) = %d\n", psh_iArray[6]);
    printf("psh_iArray[7] (8th Element) = %d\n", psh_iArray[7]);
    printf("psh_iArray[8] (9th Element) = %d\n", psh_iArray[8]);
    printf("psh_iArray[9] (10th Element) = %d\n\n", psh_iArray[9]);

    psh_int_size = sizeof(int);
    psh_iArray_size = sizeof(psh_iArray);
    psh_iArray_num_elements = psh_iArray_size / psh_int_size;

    printf("Size Of Data Type 'int' = %d Bytes\n", psh_int_size);
    printf("Number Of Elements In 'int' Array 'iArray[]' = %d Elements\n", psh_iArray_num_elements);
    printf("Size Of Array 'iArray[]' (%d Elements * %d Bytes) = %d Bytes\n\n", psh_iArray_num_elements, psh_int_size, psh_iArray_size);

    // ************ fArray[] **************
    printf("\n\n");
    printf("In-line Initialization And Piece-meal Display Of Elements Of Array 'fArray[]':\n\n");

    printf("psh_fArray[0] (1st Element) = %d\n", psh_fArray[0]);
    printf("psh_fArray[1] (2nd Element) = %d\n", psh_fArray[1]);
    printf("psh_fArray[2] (3rd Element) = %d\n", psh_fArray[2]);
    printf("psh_fArray[3] (4th Element) = %d\n", psh_fArray[3]);
    printf("psh_fArray[4] (5th Element) = %d\n", psh_fArray[4]);
    printf("psh_fArray[5] (6th Element) = %d\n", psh_fArray[5]);
    printf("psh_fArray[6] (7th Element) = %d\n", psh_fArray[6]);
    printf("psh_fArray[7] (8th Element) = %d\n", psh_fArray[7]);
    printf("psh_fArray[8] (9th Element) = %d\n", psh_fArray[8]);
    printf("psh_fArray[9] (10th Element) = %d\n\n", psh_fArray[9]);

    psh_float_size = sizeof(float);
    psh_fArray_size = sizeof(psh_fArray);
    psh_fArray_num_elements = psh_fArray_size / psh_float_size;

    printf("Size Of Data Type 'float' = %d Bytes\n", psh_float_size);
    printf("Number Of Elements In 'float' Array 'fArray[]' = %d Elements\n", psh_fArray_num_elements);
    printf("Size Of Array 'fArray[]' (%d Elements * %d Bytes) = %d Bytes\n\n", psh_fArray_num_elements, psh_float_size, psh_fArray_size);


    // ************ cArray[] **************
    printf("\n\n");
    printf("In-line Initialization And Piece-meal Display Of Elements Of Array 'cArray[]':\n\n");

    printf("psh_cArray[0] (1st Element) = %d\n", psh_cArray[0]);
    printf("psh_cArray[1] (2nd Element) = %d\n", psh_cArray[1]);
    printf("psh_cArray[2] (3rd Element) = %d\n", psh_cArray[2]);
    printf("psh_cArray[3] (4th Element) = %d\n", psh_cArray[3]);
    printf("psh_cArray[4] (5th Element) = %d\n", psh_cArray[4]);
    printf("psh_cArray[5] (6th Element) = %d\n", psh_cArray[5]);
    printf("psh_cArray[6] (7th Element) = %d\n", psh_cArray[6]);
    printf("psh_cArray[7] (8th Element) = %d\n", psh_cArray[7]);
    printf("psh_cArray[8] (9th Element) = %d\n", psh_cArray[8]);
    printf("psh_cArray[9] (10th Element) = %d\n\n", psh_cArray[9]);
    printf("psh_cArray[10] (11th Element) = %d\n", psh_cArray[10]);
    printf("psh_cArray[11] (12th Element) = %d\n", psh_cArray[11]);
    printf("psh_cArray[12] (13th Element) = %d\n\n", psh_cArray[12]);
    printf("psh_cArray[13] (14th Element) = %d\n\n", psh_cArray[13]);

    psh_char_size = sizeof(char);
    psh_cArray_size = sizeof(psh_cArray);
    psh_cArray_num_elements = psh_cArray_size / psh_char_size;

    printf("Size Of Data Type 'char' = %d Bytes\n", psh_char_size);
    printf("Number Of Elements In 'char' Array 'cArray[]' = %d Elements\n", psh_cArray_num_elements);
    printf("Size Of Array 'cArray[]' (%d Elements * %d Bytes) = %d Bytes\n\n", psh_cArray_num_elements, psh_char_size, psh_cArray_size);

    return(0);
}
