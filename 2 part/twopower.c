#include <stdio.h>
//количество степеней двойки

int check (int s, int a) {
  if ((s != 0) && (s & ( s - 1)) == 0) return 0; else return 1;
}

int main(int argc, char **argv)
{

    int n; 
    scanf("%d", &n);
    int arr[n]; 
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int number = (1 << n) - 1;
    //printf("%d\n", number);
    int ind, j = 0, b, result = 0;
    int count = 0, s = 0;  
    for (ind = 1; ind <= number; ind++) {
      for (s = j = 0, b = ind; j < n; j++) {
        if ((b & 1) == 1)
          s += arr[j];
          b = b >> 1;
}
      if (check(s, s-1) == 0) ++count;  
    }
    printf("%d\n", count);
    return 0;
}
