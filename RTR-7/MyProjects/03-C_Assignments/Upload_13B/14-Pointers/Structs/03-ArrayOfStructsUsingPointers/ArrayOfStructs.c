#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define PSH_NAME_LENGTH 100
#define PSH_MARITAL_STATUS 10

struct PshEmployee
{
    char pshName[PSH_NAME_LENGTH];
    int pshAge;
    char pshSex;
    float pshSalary;
    char pshMaritalStatus;
};

int main(void)
{
    // Function Prototype
    void PshGetString(char[], int);

    // Variable Declarations
    struct PshEmployee *pshPtrEmpRecord = NULL;
    int pshNumEmployees, psh_i;

    // Code
    printf("\n\n");
    printf("Enter number of employees whose details you want to record: \n\n");
    scanf("%d", &pshNumEmployees);

    pshPtrEmpRecord = (struct PshEmployee *)malloc(sizeof(struct PshEmployee) * pshNumEmployees);

    if (pshPtrEmpRecord == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY FOR %d EMPLOYEES !!! EXITING NOW...\n\n", pshNumEmployees);
        exit(0);
    }
    else
    {
        printf("SUCCESSFULLY ALLOCATED MEMORY FOR %d EMPLOYEES !!! \n\n", pshNumEmployees);
    }

    // **** USER INPUT INITIALIZATION OF ARRAY OF 'struct PshEmployee' ****
    for (psh_i = 0; psh_i < pshNumEmployees; psh_i++)
    {
        printf("\n\n");
        printf("**** DATA ENTRY FOR EMPLOYEE NUMBER %d *****\n", (psh_i+1));

        printf("\n\n");
        printf("Enter Employee Name: ");
        PshGetString(pshPtrEmpRecord[psh_i].pshName, PSH_NAME_LENGTH);

        printf("\n\n");
        printf("Enter Employee's Age (in years): ");
        scanf("%d", &pshPtrEmpRecord[psh_i].pshAge);

        printf("\n\n");
        printf("Enter Employee's Sex (M/m for Male, F/f for Female): ");
        pshPtrEmpRecord[psh_i].pshSex = getch();
        printf("%c", pshPtrEmpRecord[psh_i].pshSex);
        pshPtrEmpRecord[psh_i].pshSex = toupper(pshPtrEmpRecord[psh_i].pshSex);

        printf("\n\n");
        printf("Enter Employee's Salary (in Indian Rupees): ");
        scanf("%f", &pshPtrEmpRecord[psh_i].pshSalary);

        printf("\n\n");
        printf("Is the Employee Married (Y/y for Yes, N/n for No): ");
        pshPtrEmpRecord[psh_i].pshMaritalStatus = getch();
        printf("%c", pshPtrEmpRecord[psh_i].pshMaritalStatus);
        pshPtrEmpRecord[psh_i].pshMaritalStatus = toupper(pshPtrEmpRecord[psh_i].pshMaritalStatus);
    }

    // *** Display ***
    printf("\n\n");
    printf("**** DISPLAYING EMPLOYEE RECORD **** \n");
    for (psh_i = 0; psh_i < pshNumEmployees; psh_i++)
    {
        printf("******** EMPLOYEE NUMBER %d ********** \n\n", (psh_i + 1));
        printf("NAME        :%s\n", pshPtrEmpRecord[psh_i].pshName);
        printf("AGE        :%d\n", pshPtrEmpRecord[psh_i].pshAge);

        if (pshPtrEmpRecord[psh_i].pshSex == 'M')
        {
            printf("SEX     : Male\n");
        }
        else if (pshPtrEmpRecord[psh_i].pshSex == 'F')
        {
            printf("SEX     : Female\n");
        }
        else
        {
            printf("SEX     : Invalid data entered\n");
        }

        printf("SALARY        :%f\n", pshPtrEmpRecord[psh_i].pshSalary);

        if (pshPtrEmpRecord[psh_i].pshMaritalStatus == 'Y')
        {
            printf("Marital Status     : Married\n");
        }
        else if (pshPtrEmpRecord[psh_i].pshMaritalStatus == 'N')
        {
            printf("Marital Status     : Unmarried\n");
        }
        else
        {
            printf("Marital Status     : Invalid data entered\n");
        }

        printf("\n\n");
    }

    if (pshPtrEmpRecord)
    {
        free(pshPtrEmpRecord);
        pshPtrEmpRecord = NULL;
        printf("MEMORY ALLOCATED TO %d PshEmployee HAS BEEN SUCCESSFULLY FREED !!!\n\n", pshNumEmployees);
    }

    return(0);
}

// *** SIMPLE RUDIMENTARY IMPLEMENTATION OF gets_s() ***
// *** IMPLEMENTED DUE TO DIFFERENT BEHAVIOUR OF gets_s() / fgets() / fscanf() ON DIFFERENT PLATFORMS ***
// *** BACKSPACE / CHARACTER DELETION AND ARROW KEY CURSOR MOVEMENT NOT IMPLEMENTED ***

void PshGetString(char pshStr[], int pshStrSize)
{
    // Variable Declarations
    int psh_i;
    char psh_ch = '\0';

    // Code
    psh_i = 0;

    do
    {
        psh_ch = getch();
        pshStr[psh_i] = psh_ch;
        printf("%c", pshStr[psh_i]);
        psh_i++;
    } while ((psh_ch != '\r') && (psh_i < pshStrSize));


    if (psh_i == pshStrSize)
    {
        pshStr[psh_i -1] = '\0';
    }
    else
    {
        pshStr[psh_i] = '\0';
    }
}
