#include <stdio.h>

int main(void)
{
    // Variable declarations
    int psh_iArrayOne[10];
    int psh_iArrayTwo[10];

    // **************** psh_iArrayOne[] ****************

    psh_iArrayOne[0] = 3;
    psh_iArrayOne[1] = 6;
    psh_iArrayOne[2] = 9;
    psh_iArrayOne[3] = 12;
    psh_iArrayOne[4] = 15;
    psh_iArrayOne[5] = 18;
    psh_iArrayOne[6] = 21;
    psh_iArrayOne[7] = 24;
    psh_iArrayOne[8] = 27;
    psh_iArrayOne[9] = 30;

    printf("\n\n");
    printf("Piece-meal (Hard-coded) Assignment And Display Of Elements To Array 'psh_iArrayOne[]':\n\n");

    printf("1st Element Of Array 'psh_iArrayOne[]' Or Element At 0th Index Of Array 'psh_iArrayOne[]' = %d\n", psh_iArrayOne[0]);
    printf("2nd Element Of Array 'psh_iArrayOne[]' Or Element At 1st Index Of Array 'psh_iArrayOne[]' = %d\n", psh_iArrayOne[1]);
    printf("3rd Element Of Array 'psh_iArrayOne[]' Or Element At 2nd Index Of Array 'psh_iArrayOne[]' = %d\n", psh_iArrayOne[2]);
    printf("4th Element Of Array 'psh_iArrayOne[]' Or Element At 3rd Index Of Array 'psh_iArrayOne[]' = %d\n", psh_iArrayOne[3]);
    printf("5th Element Of Array 'psh_iArrayOne[]' Or Element At 4th Index Of Array 'psh_iArrayOne[]' = %d\n", psh_iArrayOne[4]);
    printf("6th Element Of Array 'psh_iArrayOne[]' Or Element At 5th Index Of Array 'psh_iArrayOne[]' = %d\n", psh_iArrayOne[5]);
    printf("7th Element Of Array 'psh_iArrayOne[]' Or Element At 6th Index Of Array 'psh_iArrayOne[]' = %d\n", psh_iArrayOne[6]);
    printf("8th Element Of Array 'psh_iArrayOne[]' Or Element At 7th Index Of Array 'psh_iArrayOne[]' = %d\n", psh_iArrayOne[7]);
    printf("9th Element Of Array 'psh_iArrayOne[]' Or Element At 8th Index Of Array 'psh_iArrayOne[]' = %d\n", psh_iArrayOne[8]);
    printf("10th Element Of Array 'psh_iArrayOne[]' Or Element At 9th Index Of Array 'psh_iArrayOne[]' = %d\n\n", psh_iArrayOne[9]);

    // **************** psh_iArrayTwo[] ****************

    printf("\n\n");

    printf("Enter 1st Element Of Array 'psh_iArrayTwo[]' : ");
    scanf("%d", &psh_iArrayTwo[0]);

    printf("Enter 2nd Element Of Array 'psh_iArrayTwo[]' : ");
    scanf("%d", &psh_iArrayTwo[1]);

    printf("Enter 3rd Element Of Array 'psh_iArrayTwo[]' : ");
    scanf("%d", &psh_iArrayTwo[2]);

    printf("Enter 4th Element Of Array 'psh_iArrayTwo[]' : ");
    scanf("%d", &psh_iArrayTwo[3]);

    printf("Enter 5th Element Of Array 'psh_iArrayTwo[]' : ");
    scanf("%d", &psh_iArrayTwo[4]);

    printf("Enter 6th Element Of Array 'psh_iArrayTwo[]' : ");
    scanf("%d", &psh_iArrayTwo[5]);

    printf("Enter 7th Element Of Array 'psh_iArrayTwo[]' : ");
    scanf("%d", &psh_iArrayTwo[6]);

    printf("Enter 8th Element Of Array 'psh_iArrayTwo[]' : ");
    scanf("%d", &psh_iArrayTwo[7]);

    printf("Enter 9th Element Of Array 'psh_iArrayTwo[]' : ");
    scanf("%d", &psh_iArrayTwo[8]);

    printf("Enter 10th Element Of Array 'psh_iArrayTwo[]' : ");
    scanf("%d", &psh_iArrayTwo[9]);

    printf("\n\n");
    printf("Piece-meal (User Input) Assignment And Display Of Elements To Array 'psh_iArrayTwo[]':\n\n");

    printf("1st Element Of Array 'psh_iArrayTwo[]' Or Element At 0th Index Of Array 'psh_iArrayTwo[]' = %d\n", psh_iArrayTwo[0]);
    printf("2nd Element Of Array 'psh_iArrayTwo[]' Or Element At 1st Index Of Array 'psh_iArrayTwo[]' = %d\n", psh_iArrayTwo[1]);
    printf("3rd Element Of Array 'psh_iArrayTwo[]' Or Element At 2nd Index Of Array 'psh_iArrayTwo[]' = %d\n", psh_iArrayTwo[2]);
    printf("4th Element Of Array 'psh_iArrayTwo[]' Or Element At 3rd Index Of Array 'psh_iArrayTwo[]' = %d\n", psh_iArrayTwo[3]);
    printf("5th Element Of Array 'psh_iArrayTwo[]' Or Element At 4th Index Of Array 'psh_iArrayTwo[]' = %d\n", psh_iArrayTwo[4]);
    printf("6th Element Of Array 'psh_iArrayTwo[]' Or Element At 5th Index Of Array 'psh_iArrayTwo[]' = %d\n", psh_iArrayTwo[5]);
    printf("7th Element Of Array 'psh_iArrayTwo[]' Or Element At 6th Index Of Array 'psh_iArrayTwo[]' = %d\n", psh_iArrayTwo[6]);
    printf("8th Element Of Array 'psh_iArrayTwo[]' Or Element At 7th Index Of Array 'psh_iArrayTwo[]' = %d\n", psh_iArrayTwo[7]);
    printf("9th Element Of Array 'psh_iArrayTwo[]' Or Element At 8th Index Of Array 'psh_iArrayTwo[]' = %d\n", psh_iArrayTwo[8]);
    printf("10th Element Of Array 'psh_iArrayTwo[]' Or Element At 9th Index Of Array 'psh_iArrayTwo[]' = %d\n", psh_iArrayTwo[9]);

    return 0;
}
