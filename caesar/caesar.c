#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(int key, string plaintext);

int main(int argc, string argv[])
{

  if (argc != 2)
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }

  int n = strlen(argv[1]);

  for (int i = 0; i < n; i++)
  {
    if (argv[1][i] < 48 || argv[1][i] > 57)
    {
      printf("Usage: ./caesar key\n");
      return 1;
    }
  }

  encrypt(atoi(argv[1]), get_string("plaintext:  "));

  return 0;
}

void encrypt(int key, string plaintext)
{
  int shift = key % 26;

  int m = strlen(plaintext);

  printf("ciphertext: ");

  for (int i = 0; i < m; i++)
  {
    int result = plaintext[i] + shift;
    if (plaintext[i] >= 97 && plaintext[i] <= 122)
    {
      if (result > 122)
      {
        result -= 26;
      }
    }
    else if (plaintext[i] >= 65 && plaintext[i] <= 90)
    {
      if (result > 90)
      {
        result -= 26;
      }
    }
    else
    {
      result = plaintext[i];
    }
    printf("%c", result);
  }
  printf("\n");
}