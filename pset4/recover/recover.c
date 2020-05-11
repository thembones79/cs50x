#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    return 1;
  }
  // Open file
  FILE *file = fopen(argv[1], "r");
  if (!file)
  {
    return 2;
  }

  int count = 0;
  char filename[10];
  bool writing = false;
  unsigned char bytes[512];
  sprintf(filename, "%03i.jpg", count);
  FILE *img = fopen(filename, "w");
  while (fread(bytes, 512, 1, file) == 1)
  {

    // Check jpg
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
    {
      writing = true;
      fclose(img);
      //open new jpg
      sprintf(filename, "%03i.jpg", count);
      fopen(filename, "w");
      //write jpg
      fwrite(bytes, 512, 1, img);

      count++;
    }
    else
    {

      if (writing)
      {
        // write jpg
        fwrite(bytes, 512, 1, img);
      }
    }
  }

  // Close file
  fclose(img);
  fclose(file);
  printf("count: %i\n", count);

  return 0;
}