// Stores and prints a string's address via pointer arithmetic

#include <stdio.h>

int main(void)
{
  char *s = "EMMA";
  for (int i = 0; i < 16; i++)
  {
    printf("%c\n", *(s + i));
  }
  printf("%c\n", *(s - 50));
  printf("%c\n", *s);
  // printf("%p\n", *s);
  // printf("%s\n", *s);
  // printf("%c\n", *&s);
  printf("%p\n", *&s);
  printf("%s\n", *&s);
  printf("----------\n");
  // printf("%s\n", *(&s + 1));
  printf("%s\n", &*s);
  printf("%p\n", &*(s + 1));
  printf("%s\n", &*(s + 1));
  //  printf("%c\n", &*s);
}
