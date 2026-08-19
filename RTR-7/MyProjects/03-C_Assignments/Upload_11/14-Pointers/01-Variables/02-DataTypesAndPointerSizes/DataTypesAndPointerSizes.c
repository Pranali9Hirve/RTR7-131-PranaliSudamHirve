#include<stdio.h>

struct Employee
{
    char psh_name[100];
    int psh_age;
    float psh_salary;
    char psh_sex;
    char psh_marital_status;
};

int main(void)
{
    // Code
    printf("\n\n");
    printf("SIZES OF DATA TYPES AND PONITERS TO THOSE RESPECTIVE DATA TYPES ARE: \n \n");

    printf("Size of (int) : %zu \t\t\t Size of pointer to int (int*): %zu\n\n", sizeof(int), sizeof(int*));
    printf("Size of (float) : %zu \t\t\t Size of pointer to float (float*): %zu\n\n", sizeof(float), sizeof(float*));
    printf("Size of (double) : %zu \t\t\t Size of pointer to double (double*): %zu\n\n", sizeof(double), sizeof(double*));
    printf("Size of (char) : %zu \t\t\t Size of pointer to char (char*): %zu\n\n", sizeof(char), sizeof(char*));
    printf("Size of (struct Employee) : %zu \t\t\t Size of pointer to struct Employee (struct Employee*): %zu\n\n", sizeof(struct Employee), sizeof(struct Employee*));

    return(0);
}
