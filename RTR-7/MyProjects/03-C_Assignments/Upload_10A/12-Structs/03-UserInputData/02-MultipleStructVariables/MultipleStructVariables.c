#include<stdio.h>

//Defining Struct 
struct PshMyPoint
{
    int psh_x;
    int psh_y;
};

int main(void) 
{
    // Variable Declarations
    struct PshMyPoint psh_point_A, psh_point_B, psh_point_C, psh_point_D, psh_point_E; //Declaring a 5 variables of type 'struct PshMyPoint' locally...

    // Code
    // User Input for the data Members of 'struct PshMyPoint' variable 'psh_point_A'
    printf("\n\n");
    printf("Enter X-coordinate For A Point : ");
    scanf("%d", &psh_point_A.psh_x);
    
    printf("Enter Y-coordinate For A Point : ");
    scanf("%d", &psh_point_A.psh_y);

    // User Input for the data Members of 'struct PshMyPoint' variable 'psh_point_B'
    printf("\n\n");
    printf("Enter X-coordinate For B Point : ");
    scanf("%d", &psh_point_B.psh_x);
    
    printf("Enter Y-coordinate For B Point : ");
    scanf("%d", &psh_point_B.psh_y);

    // User Input for the data Members of 'struct PshMyPoint' variable 'psh_point_C'
    printf("\n\n");
    printf("Enter X-coordinate For C Point : ");
    scanf("%d", &psh_point_C.psh_x);
    
    printf("Enter Y-coordinate For C Point : ");
    scanf("%d", &psh_point_C.psh_y);

    // User Input for the data Members of 'struct PshMyPoint' variable 'psh_point_D'
    printf("\n\n");
    printf("Enter X-coordinate For D Point : ");
    scanf("%d", &psh_point_D.psh_x);
    
    printf("Enter Y-coordinate For D Point : ");
    scanf("%d", &psh_point_D.psh_y);

    // User Input for the data Members of 'struct PshMyPoint' variable 'psh_point_E'
    printf("\n\n");
    printf("Enter X-coordinate For E Point : ");
    scanf("%d", &psh_point_E.psh_x);
    
    printf("Enter Y-coordinate For E Point : ");
    scanf("%d", &psh_point_E.psh_y);

    // Displaying Values of the Data Members of 'struct PshMyPoint' (all variables)
    printf("\n\n");
    printf("Point Co-ordinate (x,y) of 'psh_point_A' Are : (%d, %d) !!! \n\n", psh_point_A.psh_x, psh_point_A.psh_y);
    printf("Point Co-ordinate (x,y) of 'psh_point_B' Are : (%d, %d) !!! \n\n", psh_point_B.psh_x, psh_point_B.psh_y);
    printf("Point Co-ordinate (x,y) of 'psh_point_C' Are : (%d, %d) !!! \n\n", psh_point_C.psh_x, psh_point_C.psh_y);
    printf("Point Co-ordinate (x,y) of 'psh_point_D' Are : (%d, %d) !!! \n\n", psh_point_D.psh_x, psh_point_D.psh_y);
    printf("Point Co-ordinate (x,y) of 'psh_point_E' Are : (%d, %d) !!! \n\n", psh_point_E.psh_x, psh_point_E.psh_y);

    return(0);
}
