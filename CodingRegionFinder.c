#include <stdio.h>
#include <string.h>

int main()
{

  int i, length, start, stop, coderr;
  char seq[5000];

  scanf("%s", seq);
  length = strlen(seq);

  for (i = 0 ; i < length ; i++)
  {
    if (seq[i] != 'a' && seq[i] != 't' && seq[i] != 'g' && seq[i] != 'c' &&
        seq[i] != 'A' && seq[i] != 'T' && seq[i] != 'G' && seq[i] != 'C')
    {
      printf("Invalid character at position %d. Run again and enter a valid DNA sequence.\n", i+1);
      return 0;
    }
  }

  coderr = 0;
  i = 0;
  while (i < length)
  {
    if (seq[i] == 'a' && seq[i+1] == 't' && seq[i+2] == 'g' ||
        seq[i] == 'A' && seq[i+1] == 'T' && seq[i+2] == 'G')
    {
      start = i;
      coderr = 1;
      i+=3;
      while (i < length)
      {
        if (seq[i] == 't' && seq[i+1] == 'g' && seq[i+2] == 'a' ||
            seq[i] == 'T' && seq[i+1] == 'G' && seq[i+2] == 'A' ||
            seq[i] == 't' && seq[i+1] == 'a' && seq[i+2] == 'a' ||
            seq[i] == 'T' && seq[i+1] == 'A' && seq[i+2] == 'A' ||
            seq[i] == 't' && seq[i+1] == 'a' && seq[i+2] == 'g' ||
            seq[i] == 'T' && seq[i+1] == 'A' && seq[i+2] == 'G')
        {
          stop = i;
          printf("Coding Region found at position %d - %d\n", start+1, stop+3);
          break;
        }
        else if (i+3 >= length)
        {
          printf("Start codon at position %d but no stop codon found.\n", start+1);
          break;
        }
        i+=3;
      }
    }
    else
    {
      i++;
    }
  }
  if (!coderr)
  {
    printf("No coding region found.\n");
  }
}
