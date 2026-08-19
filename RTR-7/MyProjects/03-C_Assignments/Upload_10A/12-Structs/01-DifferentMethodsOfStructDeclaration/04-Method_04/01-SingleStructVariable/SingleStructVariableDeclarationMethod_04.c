
#include<stdio.h>

//Defining Struct
struct PshMyData
{
    int psh_i;
    float psh_f;
    double psh_d;
};

int main(void) 
{
    // Variable Declarations
    struct PshMyData psh_data; // Declaring a single struct variable of type 'struct PshMyData' locally
    int psh_i_size;
    int psh_f_size;
    int psh_d_size;
    int struct_PshMyData_size;

    //Code
    //Assigning Data Values To the Data Members Of 'struct PshMyData'
    psh_data.psh_i = 30;
    psh_data.psh_f = 11.45f;
    psh_data.psh_d = 1.2995;

    //Displaying Values of the data memebers of 'Struct PshMyData'
    printf("\n\n");
    printf("DATA Members of 'struct PshMyData' ARE: \n\n");
    printf("psh_i = %d\n", psh_data.psh_i);
    printf("psh_f = %f\n", psh_data.psh_f);
    printf("psh_d = %f\n", psh_data.psh_d);

    //Calculating sizes (In Bytes) of the data members of 'struct PshMyData'
    psh_i_size = sizeof(psh_data.psh_i);
    psh_f_size = sizeof(psh_data.psh_f);
    psh_d_size = sizeof(psh_data.psh_d);

    //Diplaying sizes (In Bytes) of the Data Members of 'Struct PshMyData'
    printf("\n\n");
    printf("SIZES (In Bytes) OF DATA MEMBERS OF 'struct PshMyData' ARE : \n\n ");
    printf("Size of 'psh_i' = %d bytes \n", psh_i_size);
    printf("Size of 'psh_f' = %d bytes \n", psh_f_size);
    printf("Size of 'psh_d' = %d bytes \n", psh_d_size);

    //Calculating size (In Bytes) Of the entire 'struct PshMyData'
    struct_PshMyData_size = sizeof(struct PshMyData); //can also give struct name -> sizeof(PshMyData)

    //Displaying Sizes (In Bytes) of the entire 'struct MyData'
    printf("\n\n");
    printf("Size of 'struct PshMyData' :%d bytes\n\n", struct_PshMyData_size);

    return(0);
}
