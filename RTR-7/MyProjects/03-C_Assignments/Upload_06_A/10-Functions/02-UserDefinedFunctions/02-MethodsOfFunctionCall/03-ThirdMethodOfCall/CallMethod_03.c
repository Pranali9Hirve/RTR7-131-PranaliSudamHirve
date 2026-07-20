#include <stdio.h>   // stdio.h contains declaration of printf()

// ****** USER DEFINED FUNCTIONS: METHOD OF CALLING FUNCTION 2 ******
// ****** CALLING ONLY ONE FUNCTIONS DIRECTLY IN main(), REST OF THE FUNCTIONS TRACE THEIR CALL INDIRECTLY TO main()

int main(int argc, char *argv[], char *envp[])
{
    // Function prototypes
    void Function_Country(void);

    // Code
    // Function call
    Function_Country();

    return 0;
}

void Function_Country(void) // Function definition
{
    // Function prototypes
    void Function_OfAMC(void);

    // Code
    Function_OfAMC();
    printf("\n\n");
    printf("I live in India.");
    printf("\n\n");
}

void Function_OfAMC(void) // Function definitions
{
    // Function prototypes
    void Function_Surname(void);

    // Code
    Function_Surname();
    printf("\n\n");
    printf("Of ASTROMEDICOMP");
}

void Function_Surname(void) // Function definition
{
    // Function prototypes
    void Function_MiddleName(void);

    // Code
    Function_MiddleName();
    printf("\n\n");
    printf("Hirve");
}

void Function_MiddleName(void) // Function definition
{
    // Function prototypes
    void Function_FirstName(void);

    // Code
    Function_FirstName();
    printf("\n\n");
    printf("Sudam");
}

void Function_FirstName(void) // Function definition
{
    // Function prototypes
    void Function_Is(void);

    // Code
    Function_Is();
    printf("\n\n");
    printf("Pranali");
}

void Function_Is(void) // Function definition
{
    // Function prototypes
    void Function_Name(void);

    // Code
    Function_Name();
    printf("\n\n");
    printf("Is");
}

void Function_Name(void) // Function definition
{
    // Function prototypes
    void Function_My(void);

    // Code
    Function_My();
    printf("\n\n");
    printf("Name");
}

// ****** User-Defined Function's Definitions ******
void Function_My(void) // Function definition
{
    // Code
    printf("\n\n");
    printf("My");
}
