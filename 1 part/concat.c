#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//конкатенация строк
char stroka[1000];

char *concat(char **s, int n)
{
    long i = 0;
    while (i < n) {
        strncat (stroka, s[i], strnlen(s[i],100));
        i++;
    }
    return stroka;
}

int main()
{
    int n; //количество строк
    scanf("%d ", &n);
    
    long i = 0;
    
    char* arr[n];
    char s[n][100];
    
    while (i < n) {
        gets(s[i]); 
        arr[i] = s[i];
        i++;
    }
    //for (i = 0; i < n; i++) {
    // printf("%s\t", arr[i]);
    //}
    
    concat (arr, n);
    for (i = 0; i <strnlen(stroka,100); i++) printf("%c", stroka[i]);
    
    //printf("%s", stroka);
    return 0;
}
