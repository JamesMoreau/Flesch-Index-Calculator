#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
/*
  Assignment 2
  Author: James Moreau
  Email: jmorea03@uoguelph.ca
  Student ID: 1065510
*/

int main(int argc, char const *argv[]) {

  if (argc > 2) {
    printf("Too many arguments\n");
  }

  double fleschIndexValue = 0;
  int wordCount = 0;
  int syllableCount = 0;
  int sentenceCount = 0;

  FILE *ptr = NULL;
  long int fSize = 0;
  const char *textFile = argv[1];
  char *masterText;
  int characterIndex=0;
  int i = 0;

/*Input file*/
  ptr = fopen(textFile, "r");
  if (ptr == NULL)
  {
    printf("ERROR: Unable to open file %s\n", argv[1]);
    return 0;
  }
  fseek(ptr, 0, SEEK_END);
  fSize = ftell(ptr);
  fseek(ptr, 0, SEEK_SET);


/*creating masterText*/
  masterText = malloc(sizeof(char) * fSize);

  for (i=0; i<fSize; i++)
  {
  masterText[i] = getc(ptr);
  }

/*wordCount*/
  while (characterIndex != fSize)
  {
    if (masterText[characterIndex] == ' ' || masterText[characterIndex] == '\n' || masterText[characterIndex] == '\0' || masterText[characterIndex] == '\t')
    {
      if (masterText[characterIndex - 1] != ' ' || masterText[characterIndex - 1] != '\n' || masterText[characterIndex - 1] != '\0' || masterText[characterIndex-1] != '\t')
      {
        if (masterText[characterIndex + 1] != ' ')
        {
          wordCount++;
        }
      }
    }
    characterIndex++;
  }
  characterIndex = 0;

/*sentenceCount*/
  while (characterIndex != fSize)
  {
    if (masterText[characterIndex] == '.' || masterText[characterIndex] == '!' || masterText[characterIndex] == ';' || masterText[characterIndex] == ':' || masterText[characterIndex] == '?')
    {
      if (masterText[characterIndex+1] != '.' || masterText[characterIndex+1] != '!' || masterText[characterIndex+1] != ';' || masterText[characterIndex+1] != ':' || masterText[characterIndex+1] != '?')
      {
        sentenceCount++;
      }
    }
    characterIndex++;
  }
  characterIndex = 0;

/*Counting syllableCount*/
  while (characterIndex !=fSize)
  {
    if (masterText[characterIndex] == 'a' || masterText[characterIndex] == 'A' || masterText[characterIndex] == 'e' || masterText[characterIndex] == 'E' || masterText[characterIndex] == 'i' || masterText[characterIndex] == 'I' || masterText[characterIndex] == 'o' || masterText[characterIndex] == 'O' || masterText[characterIndex] == 'u' || masterText[characterIndex] == 'U' || masterText[characterIndex] == 'y'  || masterText[characterIndex] == 'Y')
    {
      if (masterText[characterIndex+1] != 'a' || masterText[characterIndex+1] != 'A' || masterText[characterIndex+1] != 'e' || masterText[characterIndex+1] != 'E' || masterText[characterIndex+1] != 'i' || masterText[characterIndex+1] != 'I' || masterText[characterIndex+1] != 'o' || masterText[characterIndex+1] != 'O' || masterText[characterIndex+1] != 'u' || masterText[characterIndex+1] != 'U' || masterText[characterIndex+1] != 'y'  || masterText[characterIndex+1] != 'Y')
      {
        if (masterText[characterIndex+1] != ' ') {
          syllableCount++;
        }
      }
    }
    characterIndex++;
  }
  characterIndex = 0;

/*Counting syllableCount but with numbers*/
    while (characterIndex !=fSize)
    {
      if (masterText[characterIndex] == '1' || masterText[characterIndex] == '2' || masterText[characterIndex] == '3' || masterText[characterIndex] == '4' || masterText[characterIndex] == '5' || masterText[characterIndex] == '6' || masterText[characterIndex] == '7' || masterText[characterIndex] == '8' || masterText[characterIndex] == '9')
      {
        if (masterText[characterIndex+1] != '1' || masterText[characterIndex+1] != '2' || masterText[characterIndex+1] != '3' || masterText[characterIndex+1] != '4' || masterText[characterIndex+1] != '5' || masterText[characterIndex+1] != '6' || masterText[characterIndex+1] != '7' || masterText[characterIndex+1] != '8' || masterText[characterIndex+1] != '9')
        {
            syllableCount++;
        }
      }
      characterIndex++;
    }


/*Calculating fleschIndexValue*/
fleschIndexValue = 206.835 - 84.6 * ((double) syllableCount / (double) wordCount) - 1.015 * ((double) wordCount / (double) sentenceCount);

/* Printing */
  if (wordCount == 0 || sentenceCount == 0)
  {
    printf("\nUnable to calculate Flesch Index\n");
  }
  else
  {
    printf("Flesch Index = %.0lf\n", round(fleschIndexValue));
  }
  printf("Syllable Count = %d\n", syllableCount);
  printf("Word Count = %d\n", wordCount);
  printf("Sentence Count = %d\n", sentenceCount);


/*cleaning up*/
  fclose(ptr);
  free(masterText);

 return 0;
}
