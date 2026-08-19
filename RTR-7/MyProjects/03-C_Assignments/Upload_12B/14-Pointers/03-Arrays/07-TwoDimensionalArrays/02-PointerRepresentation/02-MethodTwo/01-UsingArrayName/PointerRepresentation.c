#include<stdio.h>
#include<stdlib.h>

#define PSH_NUM_ROWS 5
#define PSH_NUM_COLUMNS 3

int main(void)
{
    // Variable Declarations
    int psh_iArray[PSH_NUM_ROWS][PSH_NUM_COLUMNS];
    int psh_i, psh_j;

    // Code
    // *** NAME OF AN ARRAY ITSELF IS ITS BASE ADDRESS ***
    // *** HENCE, 'psh_iArray' IS BASE ADDRESS OF 2D INTEGER ARRAY psh_iArray[][]

    // psh_iArray[5][3] => psh_iArray IS A 2D ARRAY HAVING 5 ROWS AND 3 COLUMNS
    // EACH OF THESE 5 ROWS IS A 1D INTEGER ARRAY OF 3 INTEGERS

    // psh_iArray[0] => IS THE 0TH ROW .... HENCE IS THE BASE ADDRESS OF ROW 0
    // psh_iArray[1] => IS THE 1ST ROW .... HENCE IS THE BASE ADDRESS OF ROW 1
    // psh_iArray[4] => IS THE 4TH ROW .... HENCE IS THE BASE ADDRESS OF ROW 4

    // (psh_iArray[0] + 0) => ADDRESS OF 0TH INTEGER FROM BASE ADDRESS OF 0TH ROW (psh_iArray[0][0])
    // (psh_iArray[0] + 1) => ADDRESS OF 1ST INTEGER FROM BASE ADDRESS OF 0TH ROW (psh_iArray[0][1])
    // (psh_iArray[0] + 2) => ADDRESS OF 2ND INTEGER FROM BASE ADDRESS OF 0TH ROW (psh_iArray[0][2])

    // (psh_iArray[1] + 0) => ADDRESS OF 0TH INTEGER FROM BASE ADDRESS OF 1ST ROW (psh_iArray[1][0])
    // (psh_iArray[1] + 1) => ADDRESS OF 1ST INTEGER FROM BASE ADDRESS OF 1ST ROW (psh_iArray[1][1])
    // (psh_iArray[1] + 2) => ADDRESS OF 2ND INTEGER FROM BASE ADDRESS OF 1ST ROW (psh_iArray[1][2])

    // ((psh_iArray[0], psh_iArray[1]... ARE ID INTEGER ARRAYS AND HENCE CAN BE TREATED AS 1D INTEGER ARRAYS USING POINTERS..
    // psh_iArray IS THE NAME AND BASE ADDRESS OF 2D INTEGER ARRAYS ***
    // *((psh_iArray + 0) + 0) = (psh_iArray[0] + 0) = ADDRESS OF 0TH ELEMENT FROM BASE ADDRESS OF 0TH ROW = (psh_iArray[0] + 0) = (psh_iArray[0][0])
    // *((psh_iArray + 0) + 1) = (psh_iArray[0] + 1) = ADDRESS OF 1ST ELEMENT FROM BASE ADDRESS OF 0TH ROW = (psh_iArray[0] + 1) = (psh_iArray[0][1])
    // *((psh_iArray + 0) + 2) = (psh_iArray[0] + 2) = ADDRESS OF 2ND ELEMENT FROM BASE ADDRESS OF 0TH ROW = (psh_iArray[0] + 2) = (psh_iArray[0][2])

    // *((psh_iArray + 1) + 0) = (psh_iArray[1] + 0) = ADDRESS OF 0TH ELEMENT FROM BASE ADDRESS OF 1ST ROW = (psh_iArray[1] + 0) = (psh_iArray[1][0])
    // *((psh_iArray + 1) + 1) = (psh_iArray[1] + 1) = ADDRESS OF 1ST ELEMENT FROM BASE ADDRESS OF 1ST ROW = (psh_iArray[1] + 1) = (psh_iArray[1][1])
    // *((psh_iArray + 1) + 2) = (psh_iArray[1] + 2) = ADDRESS OF 2ND ELEMENT FROM BASE ADDRESS OF 1ST ROW = (psh_iArray[1] + 2) = (psh_iArray[1][2])


    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS; psh_j++)
        {
            *(*(psh_iArray + psh_i) + psh_j) = (psh_i + 1) * (psh_j + 1); // 'psh_iArray[psh_i]' CAN BE TREATED AS 1D ARRAY USING POINTERS...
        }
    }

    printf("\n\n");
    printf("2D Integer array elements along with addresses: \n");
    for (psh_i = 0; psh_i < PSH_NUM_ROWS; psh_i++)
    {
        for (psh_j = 0; psh_j < PSH_NUM_COLUMNS; psh_j++)
        {
           printf("*(*(psh_iArray + %d ) + %d) = %d \t\t At Address (* (psh_iArray + %d )+ %d) : %p\n", psh_i, psh_j, *(*(psh_iArray + psh_i) + psh_j), psh_i, psh_j, (*(psh_iArray + psh_i) + psh_j));
        }
        printf("\n\n");
    }

    return(0);
}
