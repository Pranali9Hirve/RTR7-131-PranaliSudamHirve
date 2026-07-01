#include <stdio.h> //for printf()
#include <conio.h> //for getch()

// ASCII Values For 'A' to 'Z' => 65 to 90
#define CHAR_ALPHABET_UPPER_CASE_BEGINNING 65
#define CHAR_ALPHABET_UPPER_CASE_ENDING 90

// ASCII Values For 'a' to 'z' => 97 to 122
#define CHAR_ALPHABET_LOWER_CASE_BEGINNING 97
#define CHAR_ALPHABET_LOWER_CASE_ENDING 122

// ASCII Values For '0' to '9' => 48 to 57
#define CHAR_DIGIT_BEGINNING 48
#define CHAR_DIGIT_ENDING 57

int main(void)
{
  // Variable Declarations
  char psh_ch;
  int psh_ch_value;

  // code
  printf("\n\n");

  printf( "Enter Character : ");
  psh_ch = getch();

  printf("\n\n");

  if ((psh_ch == 'A' || psh_ch == 'a') || (psh_ch == 'E' || psh_ch == 'e') || (psh_ch == 'I' || psh_ch == 'i') || (psh_ch == 'O' || psh_ch == 'o') || (psh_ch == 'U' || psh_ch == 'u'))
  {
    printf("Character \'%c\' Entered By You, Is A VOWEL CHARACTER From The English Alphabet !!! \n\n", psh_ch);
  }
  else
  {
    psh_ch_value = (int)psh_ch;

    //If The Character Has ASCII Value Between 65 AND 90 OR Between 97 AND 122, It Is Still A Letter Of The Alphabet, But It Is A 'CONSONANT', and NOT a 'VOWEL'...
    if ((psh_ch_value >= CHAR_ALPHABET_UPPER_CASE_BEGINNING && 
        psh_ch_value <= CHAR_ALPHABET_UPPER_CASE_ENDING) ||
        (psh_ch_value >= CHAR_ALPHABET_LOWER_CASE_BEGINNING && 
          psh_ch_value <= CHAR_ALPHABET_LOWER_CASE_ENDING))
    {
      printf("Character \'%c\' Entered By You, Is A CONSONANT CHARACTER From The English Alphabet !!! \n\n", psh_ch);
    }
    else if (psh_ch_value >= CHAR_DIGIT_BEGINNING && psh_ch_value <= CHAR_DIGIT_ENDING)
    {
      printf("Character \'%c\' Entered By You, Is A DIGIT CHARACTER !!! \n \n", psh_ch);
    }
    else
    {
      printf("Character \'%c\' Entered By You, Is A SPECIAL CHARACTER !!! \n \n", psh_ch);
    }
  }
  
  return (0);
}
