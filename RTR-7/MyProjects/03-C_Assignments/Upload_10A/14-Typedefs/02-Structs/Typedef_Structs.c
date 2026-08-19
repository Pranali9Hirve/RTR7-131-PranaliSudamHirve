#include<stdio.h>
#include<string.h>

#define PSH_NAME_LENGTH 100

struct PshEmployee
{
    char pshName[PSH_NAME_LENGTH];
    unsigned int pshAge;
    char pshGender;
    double pshSalary;
};

struct PshMyData
{
    int psh_i;
    float psh_f;
    double psh_d;
    char psh_c;
};

int main(void)
{
    // Typedefs
    typedef struct PshEmployee PSH_MY_EMP;
    typedef struct PshMyData PSH_MY_DATA;

    // Variable Declarations
    struct PshEmployee pshEmp = {"Anvi", 7, 'F', 5000.00};
    PSH_MY_EMP pshEmpTypedef = {"Shreeja", 3, 'F', 50000.00};

    struct PshMyData pshMD = {131, 10.34f, 34.5678, 'X'};
    PSH_MY_DATA pshMyDataTypedef;

    // Code
    pshMyDataTypedef.psh_i = 7;
    pshMyDataTypedef.psh_f = 12.34f;
    pshMyDataTypedef.psh_d = 34.76587;
    pshMyDataTypedef.psh_c = 'P';

    printf("\n\n");
    printf("struct PshEmployee: \n");
    printf("pshEmp.pshName: %s\n", pshEmp.pshName);
    printf("pshEmp.pshAge: %d\n", pshEmp.pshAge);
    printf("pshEmp.pshGender: %c\n", pshEmp.pshGender);
    printf("pshEmp.pshSalary: %lf\n", pshEmp.pshSalary);

    printf("\n\n");
    printf("typedef struct PshEmployee: \n");
    printf("pshEmpTypedef.pshName: %s\n", pshEmpTypedef.pshName);
    printf("pshEmpTypedef.pshAge: %d\n", pshEmpTypedef.pshAge);
    printf("pshEmpTypedef.pshGender: %c\n", pshEmpTypedef.pshGender);
    printf("pshEmpTypedef.pshSalary: %lf\n", pshEmpTypedef.pshSalary);


    printf("\n\n");
    printf("struct PshMyData: \n");
    printf("pshMD.psh_i: %d\n", pshMD.psh_i);
    printf("pshMD.psh_f: %f\n", pshMD.psh_f);
    printf("pshMD.psh_c: %c\n", pshMD.psh_c);
    printf("pshMD.psh_d: %lf\n", pshMD.psh_d);

    printf("\n\n");
    printf("typedef struct PshMyData: \n");
    printf("pshMyDataTypedef.psh_i: %d\n", pshMyDataTypedef.psh_i);
    printf("pshMyDataTypedef.psh_f: %f\n", pshMyDataTypedef.psh_f);
    printf("pshMyDataTypedef.psh_c: %c\n", pshMyDataTypedef.psh_c);
    printf("pshMyDataTypedef.psh_d: %lf\n", pshMyDataTypedef.psh_d);

    return(0);
}
