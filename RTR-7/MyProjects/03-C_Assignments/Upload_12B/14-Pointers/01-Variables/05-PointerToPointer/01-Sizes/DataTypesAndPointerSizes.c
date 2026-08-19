#include<stdio.h>

struct PshEmployee
{
    char psh_name[100];
    int psh_age;
    float psh_slary;
    char psh_sex;
    char psh_material_status;
};

int main(void)
{
    // Code
    printf("\n\n");
    printf("SIZES OF DATA TYPES AND PONITERS TO THOSE RESPECTIVE DATA TYPES ARE: \n\n");

    printf("size of (int) : %zu \n Size of pointer to int (int*) : %zu \n Size of pointer to pointer to int (int**) : %zu\n\n",
    sizeof(int), sizeof(int*), sizeof(int**));

    printf("size of (float) : %zu \n Size of pointer to float (float*) : %zu \n Size of pointer to pointer to float (float**) : %zu\n\n",
    sizeof(float), sizeof(float*), sizeof(float**));

    printf("size of (double) : %zu \n Size of pointer to double (double*) : %zu \n Size of pointer to pointer to double (double**) : %zu\n\n",
    sizeof(double), sizeof(double*), sizeof(double**));

    printf("size of (char) : %zu \n Size of pointer to char (char*) : %zu \n Size of pointer to pointer to char (char**) : %zu\n\n",
    sizeof(char), sizeof(char*), sizeof(char**));

    printf("size of (struct PshEmployee) : %zu \n Size of pointer to struct PshEmployee (struct PshEmployee*) : %zu \n Size of pointer to pointer to struct PshEmployee (struct PshEmployee**) : %zu\n\n",
    sizeof(struct PshEmployee), sizeof(struct PshEmployee*), sizeof(struct PshEmployee**));

    return(0);
}