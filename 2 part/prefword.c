#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//периодические префиксы
int* prefix(char *s)
{
  int size = strlen(s), i = 0, k = 0;
  int *pi = calloc(size, sizeof(int));

  for (i = 0; i < size; i++) pi[i] = i;

  pi[0] = 0;
  int t = 0;
  i = 1;

  while (i < size) {
      k = i;
      while ((t > 0) && (s[t] != s[i])) {
          t = pi[t-1];
      }
      if (s[t] == s[i]) {
          t++;
      }
      pi[i] = t;
      i++;
  }
  //for (i = 0; i < size; i++) printf("%d ", pi[i]);
  return pi;
}

void KMP (char *s, char *t)
{
  int size1 = strlen(s), size2 = strlen(t); //длины строк
  int q = 0, k = 0, *pi;//указатель на префиксную функцию
  pi = prefix(s);
  for (; k < size2; k++) {
    while ((q > 0) && (s[q] != t[k])) {
      q = pi[q-1];
    }
      if (s[q] == t[k]) ++q;
      if (q == 0) {
        printf("no\n");
        break;
      }
    }
      if (k == size2)
      printf("yes\n");
      free(pi);
  }

int main(int argc, char **argv)
{
    KMP(argv[1], argv[2]);
    return 0;
}
