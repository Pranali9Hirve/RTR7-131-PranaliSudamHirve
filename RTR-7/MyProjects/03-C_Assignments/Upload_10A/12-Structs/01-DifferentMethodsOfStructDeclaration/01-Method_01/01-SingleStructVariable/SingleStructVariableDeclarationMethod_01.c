
#include<stdio.h>

//Defining Struct
struct PSHMyData
{
    int psh_i;
    float psh_f;
    double psh_d;
    char psh_c;
} psh_data;

int main(void) 
{
    //variable declarations
    int psh_i_size;
    int psh_f_size;
    int psh_d_size;
    int psh_c_size;
    int struct_PSHMyData_size;

    //Code
    //Assigning Data Values To the Data Members Of 'struct PSH_MyData'
    psh_data.psh_i = 30;
    psh_data.psh_f = 11.45f;
    psh_data.psh_d = 1.2995;
    psh_data.psh_c = 'A';

    //Displaying Values of the data memebers of 'Struct PSH_MyData'
    printf("\n\n");
    printf("DATA Members of 'struct MyData' ARE: \n\n");
    printf("i = %d\n", psh_data.psh_i);
    printf("f = %f\n", psh_data.psh_f);
    printf("d = %f\n", psh_data.psh_d);
    printf("c = %c\n", psh_data.psh_c);

    //Calculating sizes (In Bytes) of the data members of 'struct PSH_MyData'
    psh_i_size = sizeof(psh_data.psh_i);
    psh_f_size = sizeof(psh_data.psh_f);
    psh_d_size = sizeof(psh_data.psh_d);
    psh_c_size = sizeof(psh_data.psh_c);

    //Diplaying sizes (In Bytes) of the Data Members of 'Struct PSH_MyData'
    printf("\n\n");
    printf("SIZES (In Bytes) OF DATA MEMBERS OF 'struct MyData' ARE : \n\n ");
    printf("Size of 'i' = %d bytes \n", psh_i_size);
    printf("Size of 'f' = %d bytes \n", psh_f_size);
    printf("Size of 'd' = %d bytes \n", psh_d_size);
    printf("Size of 'c' = %d bytes \n", psh_c_size);

    //Calculating size (In Bytes) Of the entire 'struct PSH_MyData'
    struct_PSHMyData_size = sizeof(struct PSHMyData); //can also give struct name -> sizeof(PSH_MyData)

    //Displaying Sizes (In Bytes) of the entire 'struct MyData'
    printf("\n\n");
    printf("Size of 'struct PSH_MYData' :%d bytes\n\n", struct_PSHMyData_size);

    return(0);
}
