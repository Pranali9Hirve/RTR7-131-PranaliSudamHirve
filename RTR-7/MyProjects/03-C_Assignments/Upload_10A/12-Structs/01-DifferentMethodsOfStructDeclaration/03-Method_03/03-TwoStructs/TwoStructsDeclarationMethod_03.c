#include<stdio.h>

int main(void) 
{
    //Defining Struct 
    struct PshMyPoint
    {
        int psh_x;
        int psh_y;
    } psh_point; //Declaring a single variable of type 'struct PshMyPoint' locally...;

    //Defining Struct
    struct PshMyPointProperties {
        int psh_quadrant;
        char psh_axis_location[10];
    } psh_point_properties; //declaring a single variable of type 'struct PshMyPointProperties' locally...
    
    // Code
    // User Input for the data Members of 'struct PshMyPoint' variable 'psh_point'
    printf("\n\n");
    printf("Enter X-coordinate For A Point : ");
    scanf("%d", &psh_point.psh_x);
    
    printf("Enter Y-coordinate For A Point : ");
    scanf("%d", &psh_point.psh_y);

    printf("\n\n");
    printf("Point Co-ordinate (x,y) Are : (%d, %d) !!! \n\n", psh_point.psh_x, psh_point.psh_y);

    if (psh_point.psh_x == 0 && psh_point.psh_y == 0)
    {
        printf("The Point is the origin (%d %d) !!!\n", psh_point.psh_x, psh_point.psh_y);
    }
    else //Atleast One of the two values (either 'X' or 'Y' or Both) is a non-zero value...
    {
        if (psh_point.psh_x == 0) //If 'X' IS ZERO..Obviuosly 'Y' is the Non-ZERO Value...
        {
            if (psh_point.psh_y < 0) //If 'Y' Is -ve
            {
                strcpy(psh_point_properties.psh_axis_location,"Negative Y");
            }

            if(psh_point.psh_y > 0) //If 'Y' Is +ve
            {
                strcpy(psh_point_properties.psh_axis_location, "Positive Y");
            }
            
            psh_point_properties.psh_quadrant  = 0; //A Point lying On Any of the co-ordinate Axes Is Not A Part Of Any_Quadrant...
            printf("The Point Lies on the %s Axis !!!\n\n", psh_point_properties.psh_axis_location);
        }
        else if (psh_point.psh_y == 0) //If 'Y' Is Zero...Obviously 'X' Is the Non-Zero Value
        {
            if (psh_point.psh_x < 0) //If 'X' Is -ve
            {
                strcpy(psh_point_properties.psh_axis_location,"Negative X");
            }

            if(psh_point.psh_x > 0) //If 'X' Is +ve
            {
                strcpy(psh_point_properties.psh_axis_location, "Positive X");
            }
       
            psh_point_properties.psh_quadrant = 0; //A Point Lying on Any of the Co-ordindate Axes Is Not A part of Any_Quadrant...
            printf("The Point Lies on the %s Axis !!!\n\n", psh_point_properties.psh_axis_location);
        }
        else 
        { //Both 'X' And 'Y' Are Non-Zero
            // psh_point_properties.psh_axis_location[0] = '\0'; //A point Lying In Any Of the 4_Quadrant Cannot be lying on any of the Co-ordinate Axes...

            if (psh_point.psh_x > 0 && psh_point.psh_y > 0) //'X' is +ve AND 'Y' Is +ve
            psh_point_properties.psh_quadrant = 1;

            else if (psh_point.psh_x < 0 && psh_point.psh_y > 0) //'X' is -ve AND 'Y' Is +ve
            psh_point_properties.psh_quadrant = 2;

            else if (psh_point.psh_x < 0 && psh_point.psh_y < 0) //'X' is -ve AND 'Y' Is -ve
            psh_point_properties.psh_quadrant = 3;

            else 
            psh_point_properties.psh_quadrant = 4; //'X' Is +ve AND 'Y' is -ve

            printf("The point lies in_Quadrant Number %d !!!\n\n", psh_point_properties.psh_quadrant);
        }
    }
    return(0);
}
