#include<stdio.h>
#include<string.h>

#define PSH_NAME_LENGTH 100
#define PSH_MARITAL_STATUS 10

struct PshEmployee
{
    char pshName[PSH_NAME_LENGTH];
    int pshAge;
    float pshSalary;
    char pshSex;
    char pshMaritalStatus[PSH_MARITAL_STATUS];
};

int main(void)
{
    // Variable Declarations
    struct PshEmployee pshEmpRecord[5]; // An array of 5 structs - Each being type 'struct PshEmployee'
    char pshEmpPranali[] = "Pranali";
    char pshEmpPranit[] = "Pranit";
    char pshEmpChaitali[] = "Chaitali";
    char pshEmpVrushali[] = "Vrushali";
    char pshEmpAnvi[] = "Anvi";
    
    int psh_i;

    // Code
    // HARD-COADED INITIALIZATION OF ARRAY OF 'struct PshEmployee'
    // PshEmployee 1

    printf("\n\n");
    strcpy(pshEmpRecord[0].pshName, pshEmpPranali);
    pshEmpRecord[0].pshAge = 35;
    pshEmpRecord[0].pshSex = 'F';
    pshEmpRecord[0].pshSalary = 50000.0f;
    strcpy(pshEmpRecord[0].pshMaritalStatus, "Married");

    // PshEmployee 2

    printf("\n\n");
    strcpy(pshEmpRecord[1].pshName, pshEmpPranit);
    pshEmpRecord[1].pshAge = 33;
    pshEmpRecord[1].pshSex = 'M';
    pshEmpRecord[1].pshSalary = 60000.0f;
    strcpy(pshEmpRecord[1].pshMaritalStatus, "Married");

    // PshEmployee 3

    printf("\n\n");
    strcpy(pshEmpRecord[2].pshName, pshEmpChaitali);
    pshEmpRecord[2].pshAge = 26;
    pshEmpRecord[2].pshSex = 'F';
    pshEmpRecord[2].pshSalary = 70000.0f;
    strcpy(pshEmpRecord[2].pshMaritalStatus, "Unmarried");

    // PshEmployee 4

    printf("\n\n");
    strcpy(pshEmpRecord[3].pshName, pshEmpVrushali);
    pshEmpRecord[3].pshAge = 26;
    pshEmpRecord[3].pshSex = 'F';
    pshEmpRecord[3].pshSalary = 70000.0f;
    strcpy(pshEmpRecord[3].pshMaritalStatus, "Unmarried");

    // PshEmployee 5

    printf("\n\n");
    strcpy(pshEmpRecord[4].pshName, pshEmpAnvi);
    pshEmpRecord[4].pshAge = 21;
    pshEmpRecord[4].pshSex = 'F';
    pshEmpRecord[4].pshSalary = 80000.0f;
    strcpy(pshEmpRecord[4].pshMaritalStatus, "Unmarried");

    // *** Display ***
    printf("\n\n");
    printf("**** DISPLAYING EMPLOYEE RECORD **** \n");
    for (psh_i = 0; psh_i < 5; psh_i++)
    {
        printf("******** EMPLOYEE NUMBER %d ********** \n\n", (psh_i + 1));
        printf("NAME        :%s\n", pshEmpRecord[psh_i].pshName);
        printf("AGE        :%d\n", pshEmpRecord[psh_i].pshAge);

        if (pshEmpRecord[psh_i].pshSex == 'M' || pshEmpRecord[psh_i].pshSex == 'm')
        {
            printf("SEX     : Male\n");
        }
        else
        {
            printf("SEX     : Female\n");
        }

        printf("SALARY        :%f\n", pshEmpRecord[psh_i].pshSalary);

        printf("Marital Status     :%s\n", pshEmpRecord[psh_i].pshMaritalStatus);
        
        printf("\n\n");
    }

    return(0);
}
