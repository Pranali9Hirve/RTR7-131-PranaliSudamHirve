#include <stdio.h>

// Defining Struct
struct PshMyData
{
    int psh_i;
    float psh_f;
    double psh_d;
    char psh_c;
};

int main (void)
{
    //Function Prototype
    struct PshMyData AddStructMembers(struct PshMyData, struct PshMyData, struct PshMyData);
    
    //Variable declarations
    struct PshMyData psh_data1, psh_data2, psh_data3, psh_answer_data;

    //Code
    //***Data 1 ***
    printf("\n\n");
    printf("********** DATA 1 **********\n\n");
    printf("Enter Integer Value For 'psh_i' Of 'struct PshMyData psh_data1' : ");
    scanf("%d", &psh_data1.psh_i);

    printf("\n\n");
    printf("Enter Floating-Point Value For 'psh_f' Of 'struct PshMyData psh_data1' : ");
    scanf("%f", &psh_data1.psh_f);

    printf("\n\n");
    printf("Enter Double Value For 'psh_d' Of 'struct PshMyData psh_data1' : ");
    scanf("%lf", &psh_data1.psh_d);

    printf("\n\n");
    printf("Enter Character Value For 'c' Of 'struct PshMyData psh_data1' : ");
    psh_data1.psh_c = getch();
    printf("%c", psh_data1.psh_c);

    //***psh_data2 ***
    printf("\n\n");
    printf("********** DATA 2 **********\n\n");
    printf("Enter Integer Value For 'psh_i' Of 'struct PshMyData psh_data2' : ");
    scanf("%d", &psh_data2.psh_i);

    printf("\n\n");
    printf("Enter Floating-Point Value For 'f' Of 'struct PshMyData psh_data2' : ");
    scanf("%f", &psh_data2.psh_f);

    printf("\n\n");
    printf("Enter Double Value For 'd' Of 'struct PshMyData psh_data2' : ");
    scanf("%lf", &psh_data2.psh_d);

    printf("\n\n");
    printf("Enter Character Value For 'c' Of 'struct PshMyData psh_data2' : ");
    psh_data2.psh_c = getch();
    printf("%c", psh_data2.psh_c);

    //***psh_data3 ***

    printf("\n\n");
    printf("********** DATA 3 **********\n\n");
    printf("Enter Integer Value For 'psh_i' Of 'struct PshMyData psh_data3' : ");
    scanf("%d", &psh_data3.psh_i);

    printf("\n\n");
    printf("Enter Floating-Point Value For 'psh_f' Of 'struct PshMyData psh_data3' : ");
    scanf("%f", &psh_data3.psh_f);

    printf("\n\n");
    printf("Enter Double Value For 'psh_d' Of 'struct PshMyData psh_data3' : ");
    scanf("%lf", &psh_data3.psh_d);

    printf("\n\n");
    printf("Enter Character Value For 'psh_c' Of 'struct PshMyData psh_data3' : ");
    psh_data3.psh_c = getch();
    printf("%c", psh_data3.psh_c);

    //*** CALLING FUNCTION AddStructMembers() WHICH ACCEPTS THREE VARIABLES OF 
    // TYPE 'struct PshMyData' AS PARAMETERES AND ADDS UP THE RESPECTIVE MEMBERS AND RETURNS THE ANSWER 
    // in ANOTHER struct OF SAME TYPE ***
    psh_answer_data = AddStructMembers(psh_data1, psh_data2, psh_data3);

    printf("\n\n");
    printf("********** ANSWER **********\n\n");
    printf("psh_answer_data.psh_i = %d\n", psh_answer_data.psh_i);
    printf("psh_answer_data.psh_f = %f\n", psh_answer_data.psh_f);
    printf("psh_answer_data.psh_d = %lf\n\n", psh_answer_data.psh_d);
    
    psh_answer_data.psh_c = psh_data1.psh_c;
    printf("psh_answer_data.psh_c (from psh_data1) = %c\n\n", psh_answer_data.psh_c);

    psh_answer_data.psh_c = psh_data2.psh_c;
    printf("psh_answer_data.psh_c (from psh_data2) = %c\n\n", psh_answer_data.psh_c);

    psh_answer_data.psh_c = psh_data3.psh_c;
    printf("psh_answer_data.psh_c (from psh_data3) = %c\n\n", psh_answer_data.psh_c);

    return(0);    

}

struct PshMyData AddStructMembers(struct PshMyData psh_md_one, struct PshMyData psh_md_two, struct PshMyData psh_md_three)
{
    // Variable Declarations

    struct PshMyData psh_answer;

    // Code
    psh_answer.psh_i = psh_md_one.psh_i + psh_md_two.psh_i + psh_md_three.psh_i;
    psh_answer.psh_f = psh_md_one.psh_f + psh_md_two.psh_f + psh_md_three.psh_f;
    psh_answer.psh_d = psh_md_one.psh_d + psh_md_two.psh_d + psh_md_three.psh_d;
    return(psh_answer);
}
