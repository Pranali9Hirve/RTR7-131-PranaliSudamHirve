#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define PSH_NUM_EMPLOYEES 2 // SIMPLY CHANGE THIS CONSTANT VALUE TO HAVE AS MANY NUMBER OF Employee Records as you please...
#define PSH_NAME_LENGTH 100
#define PSH_MARITAL_STATUS 10

struct PshEmployee
{
    char pshName[PSH_NAME_LENGTH];
    int pshAge;
    float pshSalary;
    char pshSex;
    char pshMaritalStatus;
};

int main(void)
{
    // Function Prototype
    void PshGetString(char[], int);

    // Variable Declarations
    struct PshEmployee pshEmpRecord[PSH_NUM_EMPLOYEES]; // An array of 5 structs - Each being type 'struct PshEmployee'
    
    int psh_i;

    // Code
    // User Input INITIALIZATION OF ARRAY OF 'struct PshEmployee'
    for (psh_i = 0; psh_i < PSH_NUM_EMPLOYEES; psh_i++)
    {
        printf("\n\n");
        printf("**** DATA ENTRY FOR EMPLOYEE NUMBER %d *****\n", (psh_i+1));

        printf("\n\n");
        printf("Enter Employee Name: ");
        PshGetString(pshEmpRecord[psh_i].pshName, PSH_NAME_LENGTH);

        printf("\n\n");
        printf("Enter Employee's Age (in years): ");
        scanf("%d", &pshEmpRecord[psh_i].pshAge);

        printf("\n\n");
        printf("Enter Employee's Sex (M/m for Male, F/f for Female): ");
        pshEmpRecord[psh_i].pshSex = getch();
        printf("%c", pshEmpRecord[psh_i].pshSex);
        pshEmpRecord[psh_i].pshSex = toupper(pshEmpRecord[psh_i].pshSex);

        printf("\n\n");
        printf("Enter Employee's Salary (in Indian Rupees): ");
        scanf("%f", &pshEmpRecord[psh_i].pshSalary);

        printf("\n\n");
        printf("Is the Employee Married (Y/y for Yes, N/n for No): ");
        pshEmpRecord[psh_i].pshMaritalStatus = getch();
        printf("%c", pshEmpRecord[psh_i].pshMaritalStatus);
        pshEmpRecord[psh_i].pshMaritalStatus = toupper(pshEmpRecord[psh_i].pshMaritalStatus);
    }
   
    // *** Display ***
    printf("\n\n");
    printf("**** DISPLAYING EMPLOYEE RECORDS **** \n");
    for (psh_i = 0; psh_i < PSH_NUM_EMPLOYEES; psh_i++)
    {
        printf("******** EMPLOYEE NUMBER %d ********** \n\n", (psh_i + 1));
        printf("NAME        :%s\n", pshEmpRecord[psh_i].pshName);
        printf("AGE        :%d\n", pshEmpRecord[psh_i].pshAge);

        if (pshEmpRecord[psh_i].pshSex == 'M')
        {
            printf("SEX     : Male\n");
        }
        else if (pshEmpRecord[psh_i].pshSex == 'F')
        {
            printf("SEX     : Female\n");
        }
        else
        {
            printf("SEX     : Invalid data entered\n");
        }

        printf("SALARY        :%f\n", pshEmpRecord[psh_i].pshSalary);

        if (pshEmpRecord[psh_i].pshMaritalStatus == 'Y')
        {
            printf("Marital Status     : Married\n");
        }
        else if (pshEmpRecord[psh_i].pshMaritalStatus == 'N')
        {
            printf("Marital Status     : Unmarried\n");
        }
        else
        {
            printf("Marital Status     : Invalid data entered\n");
        }

        printf("\n\n");
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
