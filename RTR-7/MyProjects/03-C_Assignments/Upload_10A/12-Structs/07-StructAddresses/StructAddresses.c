
#include<stdio.h>

//Defining Struct
struct PSHMyData
{
    int psh_i;
    float psh_f;
    double psh_d;
    char psh_c;
};

int main(void) 
{
    //variable declarations
    struct PSHMyData psh_data;

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
    printf("d = %lf\n", psh_data.psh_d);
    printf("c = %c\n\n", psh_data.psh_c);

    printf("\n\n");
    printf("Addresses of Data Members of 'struct MyData' ARE: \n\n");
    printf("i Occupies Addesses from %p\n", &psh_data.psh_i);
    printf("f Occupies Addesses from %p\n", &psh_data.psh_f);
    printf("d Occupies Addesses from %p\n", &psh_data.psh_d);
    printf("c Occupies Addesses from %p\n\n", &psh_data.psh_c);

    printf("Starting Address of 'struct MyData' variable 'psh_data' :%p\n\n", &psh_data);

    return(0);
}
