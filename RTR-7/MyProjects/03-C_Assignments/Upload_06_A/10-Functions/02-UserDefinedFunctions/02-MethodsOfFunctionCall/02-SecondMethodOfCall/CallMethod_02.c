#include <stdio.h>   // stdio.h contains declaration of printf()

// ****** USER DEFINED FUNCTIONS: METHOD OF CALLING FUNCTION 2 ******
// ****** CALLING ONLY TWO FUNCTIONS DIRECTLY IN main(), REST OF THE FUNCTIONS TRACE THEIR CALL INDIRECTLY TO main()

int main(int argc, char *argv[], char *envp[])
{
    // Function prototypes
    void display_information(void);
    void function_country(void);

    // Code
    // Function calls
    display_information();
    function_country();

    return 0;
}

// ****** User-Defined Function's Definitions ******

// Function definition
void display_information(void)
{
    // Function prototypes
    void Function_My(void);
    void Function_Name(void);
    void Function_Is(void);
    void Function_FirstName(void);
    void Function_MiddleName(void);
    void Function_Surname(void);
    void Function_OfAMC(void);

    // Code
    // Function calls
    Function_My();
    Function_Name();
    Function_Is();
    Function_FirstName();
    Function_MiddleName();
    Function_Surname();
    Function_OfAMC();
}

void Function_My(void) // Function definition
{
    // Code
    printf("\n\n");
    printf("My");
}

void Function_Name(void) // Function definition
{
    // Code
    printf("\n\n");
    printf("Name");
}

void Function_Is(void) // Function definition
{
    // Code
    printf("\n\n");
    printf("Is");
}

void Function_FirstName(void) // Function definition
{
    // Code
    printf("\n\n");
    printf("Pranali");
}

void Function_MiddleName(void) // Function definition
{
    // Code
    printf("\n\n");
    printf("Sudam");
}

void Function_Surname(void) // Function definition
{
    // Code
    printf("\n\n");
    printf("Hirve");
}

void Function_OfAMC(void) // Function definitions
{
    // Code
    printf("\n\n");
    printf("Of ASTROMEDICOMP");
}

void function_country(void) // Function definition
{
    // Code
    printf("\n\n");
    printf("I live in India.");

    printf("\n\n");
}
