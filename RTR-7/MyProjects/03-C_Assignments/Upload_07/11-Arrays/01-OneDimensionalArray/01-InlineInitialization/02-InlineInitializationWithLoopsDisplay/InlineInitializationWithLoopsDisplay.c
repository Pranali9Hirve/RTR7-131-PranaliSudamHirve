#include<stdio.h>
int main(void)
{
    // Variable Declarations
    int psh_iArray[] = {15, 30, 45, 5, 20, 35, 13, 18, 32};
    int psh_int_size;
    int psh_iArray_size;
    int psh_iArray_num_elements;

    float psh_fArray[] = {1.2f, 2.46f, 3.f, 4.8f, 6.0f, 7.2f, 8.4f, 9.6f};
    int psh_float_size;
    int psh_fArray_size;
    int psh_fArray_num_elements;

    char psh_cArray[] = {'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P'};
    
    int psh_char_size;
    int psh_cArray_size;
    int psh_cArray_num_elements;

    int psh_i;

    // Code
    // ************ iArray[] **************
    printf("\n\n");
    printf("In-line Initialization And loop (for) Display Of Elements Of Array 'iArray[]':\n\n");

    psh_int_size = sizeof(int);
    psh_iArray_size = sizeof(psh_iArray);
    psh_iArray_num_elements = psh_iArray_size / psh_int_size;

    for (psh_i = 0; psh_i < psh_iArray_num_elements; psh_i++)
    {
        printf("psh_iArray[%d] (Element %d) = %d\n", psh_i, (psh_i + 1), psh_iArray[psh_i]);
    }

    printf("Size Of Data Type 'int' = %d Bytes\n", psh_int_size);
    printf("Number Of Elements In 'int' Array 'iArray[]' = %d Elements\n", psh_iArray_num_elements);
    printf("Size Of Array 'iArray[]' (%d Elements * %d Bytes) = %d Bytes\n\n", psh_iArray_num_elements, psh_int_size, psh_iArray_size);

    // ************ fArray[] **************
    printf("\n\n");
    printf("In-line Initialization And Piece-meal Display Of Elements Of Array 'fArray[]':\n\n");

    psh_float_size = sizeof(float);
    psh_fArray_size = sizeof(psh_fArray);
    psh_fArray_num_elements = psh_fArray_size / psh_float_size;

    for (psh_i = 0; psh_i < psh_fArray_num_elements; psh_i++)
    {
        printf("psh_fArray[%d] (Element %d) = %f\n", psh_i, (psh_i + 1), psh_fArray[psh_i]);
    }

    printf("Size Of Data Type 'float' = %d Bytes\n", psh_float_size);
    printf("Number Of Elements In 'float' Array 'fArray[]' = %d Elements\n", psh_fArray_num_elements);
    printf("Size Of Array 'fArray[]' (%d Elements * %d Bytes) = %d Bytes\n\n", psh_fArray_num_elements, psh_float_size, psh_fArray_size);


    // ************ cArray[] **************
    printf("\n\n");
    printf("In-line Initialization And Piece-meal Display Of Elements Of Array 'cArray[]':\n\n");

    psh_char_size = sizeof(char);
    psh_cArray_size = sizeof(psh_cArray);
    psh_cArray_num_elements = psh_cArray_size / psh_char_size;

    for (psh_i = 0; psh_i < psh_cArray_num_elements; psh_i++)
    {
        printf("psh_cArray[%d] (Element %d) = %c\n", psh_i, (psh_i + 1), psh_cArray[psh_i]);
    }

    printf("Size Of Data Type 'char' = %d Bytes\n", psh_char_size);
    printf("Number Of Elements In 'char' Array 'cArray[]' = %d Elements\n", psh_cArray_num_elements);
    printf("Size Of Array 'cArray[]' (%d Elements * %d Bytes) = %d Bytes\n\n", psh_cArray_num_elements, psh_char_size, psh_cArray_size);

    return(0);
}
