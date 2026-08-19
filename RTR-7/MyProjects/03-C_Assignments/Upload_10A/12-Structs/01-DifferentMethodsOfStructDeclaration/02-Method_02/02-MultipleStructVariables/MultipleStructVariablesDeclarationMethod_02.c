
#include<stdio.h>

//Defining STRUCT ...
struct PshMyPoint 
{
    int psh_x;
    int psh_y;
};

// Declaring 5 struct variable of type 'struct PshMyPoint' globally...
struct PshMyPoint psh_point_A, psh_point_B, psh_point_C, psh_point_D, psh_point_E; 

int main(void) 
{
    //Code
    //Assigning Data values to the data members of 'struct PshMyPoint' variable 'psh_point_A'
    psh_point_A.psh_x = 10;
    psh_point_A.psh_y = 11;

    //Assigning Data values to the Data Members Of 'struct PshMyPoint' variable 'psh_point_B'
    psh_point_B.psh_x = 12;
    psh_point_B.psh_y = 6;

    //Assigning Data values to the Data Members Of 'struct PshMyPoint' variable 'psh_point_C'
    psh_point_C.psh_x = 9;
    psh_point_C.psh_y = 16;

    //Assigning Data values to the Data Members Of 'struct PshMyPoint' variable 'psh_point_D'
    psh_point_D.psh_x = 18;
    psh_point_D.psh_y = 12;
    
    //Assigning Data values to the Data Members Of 'struct PshMyPoint' variable 'psh_point_E'
    psh_point_E.psh_x = 11;
    psh_point_E.psh_y = 8;
    
    //Displaying values of the Data Members of 'struct PshMyPoint' (all variables)
    printf("\n\n");
    printf("Co-ordinates (x,y) Of Point 'A' Are: (%d, %d)\n\n", psh_point_A.psh_x, psh_point_A.psh_y);
    printf("Co-ordinates (x,y) Of Point 'B' Are: (%d, %d)\n\n", psh_point_B.psh_x, psh_point_B.psh_y);
    printf("Co-ordinates (x,y) Of Point 'C' Are: (%d, %d)\n\n", psh_point_C.psh_x, psh_point_C.psh_y);
    printf("Co-ordinates (x,y) Of Point 'D' Are: (%d, %d)\n\n", psh_point_D.psh_x, psh_point_D.psh_y);
    printf("Co-ordinates (x,y) Of Point 'E' Are: (%d, %d)\n\n", psh_point_E.psh_x, psh_point_E.psh_y);

    return(0);
}
