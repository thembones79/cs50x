#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool isInputValid(int argc, string argv[]);
void encrypt(string key, string plaintext);

int main(int argc, string argv[])
{
  if (!isInputValid(argc, argv))
  {
    return 1;
  }

  encrypt(argv[1], get_string("plaintext:  "));

  return 0;
}

bool isInputValid(int argc, string argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./substitution key\n");
    return false;
  }

  int n = strlen(argv[1]);

  for (int i = 0; i < n; i++)
  {
    if (argv[1][i] < 65 || (argv[1][i] > 90 && argv[1][i] < 97) || argv[1][i] > 122)
    {
      printf("Key must only contain alphabetic characters.\n");
      return false;
    }

    for (int j = i + 1; j < n; j++)
    {
      if (tolower(argv[1][i]) == tolower(argv[1][j]))
      {
        printf("Key must not contain repeated characters.\n");
        return false;
      }
    }
  }

  if (n != 26)
  {
    printf("Key must contain 26 characters.\n");
    return false;
  }

  return true;
}

int substitute(string key, int letter)
{
  if ((letter >= 97 && letter <= 122) || (letter >= 65 && letter <= 90))
  {
    for (int j = 97; j <= 122; j++)
    {
      if (tolower(letter) == j)
      {
        return letter + tolower(key[j - 97]) - j;
      }
    }
  }

  return letter;
}

void encrypt(string key, string plaintext)
{
  printf("ciphertext: ");

  for (int i = 0; i < strlen(plaintext); i++)
  {
    printf("%c", substitute(key, plaintext[i]));
  }

  printf("\n");
}